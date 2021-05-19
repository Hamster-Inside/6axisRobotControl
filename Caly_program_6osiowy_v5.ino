#define enPin1 42
#define dirPin1 38
#define stepPin1 40

#define enPin2 34
#define dirPin2 30
#define stepPin2 32

#define enPin3 26
#define dirPin3 22
#define stepPin3 24

#define enPin4 43
#define dirPin4 39
#define stepPin4 41

#define enPin5 35
#define dirPin5 31
#define stepPin5 33

#define enPin6 27
#define dirPin6 23
#define stepPin6 25

#define diode_red 44
#define diode_green 45

#define button_red 3 // red need to be low to work - closed circuit
#define button_green 2 // green need to be high to work - open circuit

#define AXIS1_STEP_HIGH             PORTG |=  0b00000010;
#define AXIS1_STEP_LOW              PORTG &= ~0b00000010;

#define AXIS2_STEP_HIGH             PORTC |=  0b00100000;
#define AXIS2_STEP_LOW              PORTC &= ~0b00100000;

#define AXIS3_STEP_HIGH             PORTA |=  0b00000100;
#define AXIS3_STEP_LOW              PORTA &= ~0b00000100;

#define AXIS4_STEP_HIGH             PORTG |=  0b00000001;
#define AXIS4_STEP_LOW              PORTG &= ~0b00000001;

#define AXIS5_STEP_HIGH             PORTC |=  0b00010000;
#define AXIS5_STEP_LOW              PORTC &= ~0b00010000;

#define AXIS6_STEP_HIGH             PORTA |=  0b00001000;
#define AXIS6_STEP_LOW              PORTA &= ~0b00001000;

#define indsensePin1 46
#define indsensePin2 48
#define indsensePin3 50
#define indsensePin4 47
#define endstop5 51
#define indsensePin6 49




#define axis1p 13
#define axis1m 12 
#define axis2p 11 
#define axis2m 10
#define axis3p 9 
#define axis3m 8 
#define axis4p A2 
#define axis4m A4 
#define axis5p 5
#define axis5m 4
#define axis6p 36
#define axis6m 37
#define startprog 14
#define stopprog 15
#define prog1 16
#define prog2 17
#define stepback 18
#define stepforward 19
#define EMRstop 53
#define base 52
#define point0 28
#define MA 29
#define pot A0




 
unsigned long micro1prev = 0;
unsigned long micro2prev = 0;
unsigned long micro3prev = 0;
unsigned long micro4prev = 0;
unsigned long micro5prev = 0;
unsigned long micro6prev = 0;
unsigned long globaltimeprev = 0;
unsigned long blinkdiodeprev = 0;
unsigned long blinktime = 500000;
unsigned long microstepprev = 0;
unsigned long millis1compare = 0;



const long globaldelay = 3000000;

long step1=0;
long step2=0;
long step3=0;
long step4=0;
long step5=0;
long step6=0;
long delay1;
long delay2;
long delay3;
long delay4;
long delay5;
long delay6;

long base_position;

long axis1_moveto;
long axis2_moveto;
long axis3_moveto;
long axis4_moveto;
long axis5_moveto;
long axis6_moveto;


const long axis1_0 = -964;
const long axis2_0 = -20278;
const long axis3_0 = -15670;
const long axis4_0 = -2870;
const long axis5_0 = 25329;
const long axis6_0 = 247;

const long axis1_00 = 0;
const long axis2_00 = 0;
const long axis3_00 = 0;
const long axis4_00 = 0;
const long axis5_00 = 0;
const long axis6_00 = 0;

boolean axis1move = false; 
boolean axis2move = false; 
boolean axis3move = false; 
boolean axis4move = false; 
boolean axis5move = false; 
boolean axis6move = false; 
boolean find_first_pos = false;
boolean allow_to_go = false;
boolean szukanie_krancowek = false;
boolean i_am_at_0 = false;
boolean set_program_1 = false;
boolean set_program_2 = false;
boolean allow_to_start_program = false;
boolean you_can_move_auto = false;
boolean one_push = false;
boolean next_move = false;
boolean done_moving = false;
boolean go_round_program1 = true;    // zapetlenie programu 1 - true = tak, false = nie (wykonaj raz i zakoncz)
boolean count_variables = false;
boolean start_progtimer = false;
boolean find_highest_poschange = false;
boolean read_values = true;
boolean last_step = false;
boolean doonce1 = true;
boolean doonce2 = true;
boolean doonce3 = true;
boolean doonce4 = true;
boolean doonce5 = true;
boolean doonce6 = true;
boolean Program_1_ON = false;
boolean end_of_program1 = true;
boolean sitting_on_0 = false;
boolean done_counting = false;
boolean axis1_count_ready = false;
boolean axis2_count_ready = false;
boolean axis3_count_ready = false;
boolean axis4_count_ready = false;
boolean axis5_count_ready = false;
boolean axis6_count_ready = false;
boolean check_position = false;
boolean go_to_counting = false;
boolean done_running = false;
boolean prepare1done = false;
boolean prepare2done = false;
boolean prepare3done = false;
boolean prepare4done = false;
boolean prepare5done = false;
boolean prepare6done = false;
boolean go_next_step = false;
boolean doonce_endstop = false;



long position1;
long position2;
long position3;
long position4;
long position5;
long position6;
long prevposition1;
long prevposition2;
long prevposition3;
long prevposition4;
long prevposition5;
long prevposition6;
long position1jump;
long position2jump;
long position3jump;
long position4jump;
long position5jump;
long position6jump;
long highest_poschange;
long highest_delay = 50; // top speed at auto program move
long axis1_next_position = 0;
long axis2_next_position = 0;
long axis3_next_position = 0;
long axis4_next_position = 0;
long axis5_next_position = 0;
long axis6_next_position = 0;
long counter_stage = 0;
long wait_before;

#define TIMER1_INTERRUPTS_ON    TIMSK1 |=  (1 << OCIE1A);
#define TIMER1_INTERRUPTS_OFF   TIMSK1 &= ~(1 << OCIE1A);


struct stepperInfo {
  // externally defined parameters
  float acceleration;
  volatile unsigned long minStepInterval; // ie. max speed, smaller is faster
  void (*dirFunc)(int);
  void (*stepFunc)();

  // derived parameters
  unsigned long c0;                // step interval for first step, determines acceleration
  long stepPosition;              // current position of stepper (total of all movements taken so far)

  // per movement variables (only changed once per movement)
  volatile int dir;                        // current direction of movement, used to keep track of position
  volatile unsigned long totalSteps;        // number of steps requested for current movement
  volatile bool movementDone = false;      // true if the current movement has been completed (used by main program to wait for completion)
  volatile unsigned long rampUpStepCount;   // number of steps taken to reach either max speed, or half-way to the goal (will be zero until this number is known)
  volatile unsigned long estStepsToSpeed;  // estimated steps required to reach max speed
  volatile unsigned long estTimeForMove;   // estimated time (interrupt ticks) required to complete movement
  volatile unsigned long rampUpStepTime;
  volatile float speedScale;               // used to slow down this motor to make coordinated movement with other motors

  // per iteration variables (potentially changed every interrupt)
  volatile unsigned long n;                 // index in acceleration curve, used to calculate next interval
  volatile float d;                        // current interval length
  volatile unsigned long di;               // above variable truncated
  volatile unsigned long stepCount;         // number of steps completed in current movement
};

void axis1_Step() {
  if (digitalRead(stepPin1) == HIGH){
    AXIS1_STEP_LOW;
   }
  else{
    AXIS1_STEP_HIGH;
  }
  if (digitalRead(dirPin1) == HIGH){
    --step1;
  }
  else{
    ++step1;
  }
}
void axis1_Dir(int dir) {
  digitalWrite(dirPin1, dir);
}

void axis2_Step() {
  if (digitalRead(stepPin2) == HIGH){
    AXIS2_STEP_LOW;
  }
  else{
    AXIS2_STEP_HIGH;
  }
    if (digitalRead(dirPin2) == HIGH){
    ++step2;
  }
  else{
    --step2;
  }
}
void axis2_Dir(int dir) {
  digitalWrite(dirPin2, !dir);
}

void axis3_Step() {
  if (digitalRead(stepPin3) == HIGH){
    AXIS3_STEP_LOW;
  }
  else{
    AXIS3_STEP_HIGH;
  }
    if (digitalRead(dirPin3) == HIGH){
    ++step3;
  }
  else{
    --step3;
  }
}
void axis3_Dir(int dir) {
  digitalWrite(dirPin3, !dir);
}

void axis4_Step() {
  if (digitalRead(stepPin4) == HIGH){
    AXIS4_STEP_LOW;
  }
  else{
    AXIS4_STEP_HIGH;
  }
    if (digitalRead(dirPin4) == HIGH){
    ++step4;
  }
  else{
    --step4;
  }
}
void axis4_Dir(int dir) {
  digitalWrite(dirPin4, !dir);
}

void axis5_Step() {
  if (digitalRead(stepPin5) == HIGH){
    AXIS5_STEP_LOW;
  }
  else{
    AXIS5_STEP_HIGH;
  }
    if (digitalRead(dirPin5) == HIGH){
    ++step5;
  }
  else{
    --step5;
  }
}
void axis5_Dir(int dir) {
  digitalWrite(dirPin5, !dir);
}

void axis6_Step() {
  if (digitalRead(stepPin6) == HIGH){
    AXIS6_STEP_LOW;
  }
  else{
    AXIS6_STEP_HIGH;
  }
    if (digitalRead(dirPin6) == HIGH){
    ++step6;
  }
  else{
    --step6;
  }
}
void axis6_Dir(int dir) {
  digitalWrite(dirPin6, !dir);
}

void resetStepperInfo( stepperInfo& si ) {
  si.n = 0;
  si.d = 0;
  si.di = 0;
  si.stepCount = 0;
  si.rampUpStepCount = 0;
  si.rampUpStepTime = 0;
  si.totalSteps = 0;
  si.stepPosition = 0;
  si.movementDone = false;
}

#define NUM_STEPPERS 6

volatile stepperInfo steppers[NUM_STEPPERS];







void setup() {
  
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(enPin1, OUTPUT);
  
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(enPin2, OUTPUT);
  
  pinMode(stepPin3, OUTPUT);
  pinMode(dirPin3, OUTPUT);
  pinMode(enPin3, OUTPUT);
  
  pinMode(stepPin4, OUTPUT);
  pinMode(dirPin4, OUTPUT);
  pinMode(enPin4, OUTPUT);

  pinMode(stepPin5, OUTPUT);
  pinMode(dirPin5, OUTPUT);
  pinMode(enPin5, OUTPUT);

  pinMode(stepPin6, OUTPUT);
  pinMode(dirPin6, OUTPUT);
  pinMode(enPin6, OUTPUT);

   attachInterrupt(1, emergency_off, LOW); 
  
  pinMode(indsensePin1, INPUT);
  pinMode(indsensePin2, INPUT);
  pinMode(indsensePin3, INPUT);
  pinMode(indsensePin4, INPUT);
  pinMode(endstop5, INPUT);
  pinMode(indsensePin6, INPUT);
  pinMode(axis1p, INPUT);
  pinMode(axis1m, INPUT);
  pinMode(axis2p, INPUT);
  pinMode(axis2m, INPUT);
  pinMode(axis3p, INPUT);
  pinMode(axis3m, INPUT);
  pinMode(axis4p, INPUT);
  pinMode(axis4m, INPUT);
  pinMode(axis5p, INPUT);
  pinMode(axis5m, INPUT);
  pinMode(axis6p, INPUT);
  pinMode(axis6m, INPUT);
  pinMode(startprog, INPUT);
  pinMode(stopprog, INPUT);
  pinMode(prog1, INPUT);
  pinMode(prog2, INPUT);
  pinMode(stepback, INPUT);
  pinMode(stepforward, INPUT);
  pinMode(EMRstop, INPUT);
  pinMode(base, INPUT);
  pinMode(point0, INPUT);
  pinMode(MA, INPUT);
  pinMode(pot, INPUT);

  pinMode(diode_green, OUTPUT);
  pinMode(diode_red, OUTPUT);

  pinMode(button_green, INPUT);
  pinMode(button_red, INPUT);


  
  digitalWrite(dirPin1, HIGH);
  digitalWrite(stepPin1, LOW);
  digitalWrite(enPin1, LOW);
  
  digitalWrite(dirPin2, HIGH);
  digitalWrite(stepPin2, LOW);
  digitalWrite(enPin2, LOW);
  
  digitalWrite(dirPin3, HIGH);
  digitalWrite(stepPin3, LOW);
  digitalWrite(enPin3, LOW);
  
  digitalWrite(dirPin4, HIGH);
  digitalWrite(stepPin4, LOW);
  digitalWrite(enPin4, LOW);

  digitalWrite(dirPin5, HIGH);
  digitalWrite(stepPin5, LOW);
  digitalWrite(enPin5, LOW);

  digitalWrite(dirPin6, HIGH);
  digitalWrite(stepPin6, LOW);
  digitalWrite(enPin6, LOW);

  Serial.begin(9600);

noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

  OCR1A = 1000;                             // compare value
  TCCR1B |= (1 << WGM12);                   // CTC mode
  TCCR1B |= ((1 << CS11) | (1 << CS10));    // 64 prescaler
interrupts();

  steppers[0].dirFunc = axis1_Dir;
  steppers[0].stepFunc = axis1_Step;
  steppers[0].acceleration = 500;
  steppers[0].minStepInterval = 4;

  steppers[1].dirFunc = axis2_Dir;
  steppers[1].stepFunc = axis2_Step;
  steppers[1].acceleration = 500;
  steppers[1].minStepInterval = 4;

  steppers[2].dirFunc = axis3_Dir;
  steppers[2].stepFunc = axis3_Step;
  steppers[2].acceleration = 500;
  steppers[2].minStepInterval = 4;

  steppers[3].dirFunc = axis4_Dir;
  steppers[3].stepFunc = axis4_Step;
  steppers[3].acceleration = 500;
  steppers[3].minStepInterval = 4;

  steppers[4].dirFunc = axis5_Dir;
  steppers[4].stepFunc = axis5_Step;
  steppers[4].acceleration = 500;
  steppers[4].minStepInterval = 4;

  steppers[5].dirFunc = axis6_Dir;
  steppers[5].stepFunc = axis6_Step;
  steppers[5].acceleration = 500;
  steppers[5].minStepInterval = 4;



  




}

void loop() {

unsigned long blinkdiodetime = micros();
if (allow_to_go == true){

// Jeżeli ustawiony na MANUAL:
if (digitalRead(MA) == HIGH){
 manual_movement();//przechodzi do funkcji ruchu recznego
 gripper(); //ustawienia chwytaka
 allow_to_start_program = false;

}
// Jeżeli uruchomiony tryb bazowania:
if (digitalRead(base) == HIGH && digitalRead(MA) == LOW){
 base_by_hand(); //reczne bazowanie z pilota
 gripper(); //ustawienia chwytaka
  i_am_at_0 = false;

}
if (digitalRead(base) == LOW){
axis1move = false; 
axis2move = false; 
axis3move = false; 
axis4move = false; 
axis5move = false; 
axis6move = false; 

}
if (digitalRead(point0) == LOW && digitalRead(base) == LOW && digitalRead(MA) == LOW){
  go_position_0();
}
}
if (allow_to_go == false) {
 
 if (blinkdiodetime - blinkdiodeprev >=blinktime)
{
  digitalWrite(diode_red, !digitalRead(diode_red));
  digitalWrite(diode_green, digitalRead(diode_red));
  blinkdiodeprev = blinkdiodetime;
}}

// Sygnały z panelu
control_panel();


if (digitalRead(prog2) == HIGH){
  Serial.println("");
  Serial.print("Axis 1 position = ");
  Serial.println(step1);
  Serial.print("Axis 2 position = ");
  Serial.println(step2);
  Serial.print("Axis 3 position = ");
  Serial.println(step3);
  Serial.print("Axis 4 position = ");
  Serial.println(step4);
  Serial.print("Axis 5 position = ");
  Serial.println(step5);
  Serial.print("Axis 6 position = ");
  Serial.println(step6);
  Serial.println("");
  delay(500);

  Serial.print("you_can_go_full_auto = ");
  Serial.println(you_can_move_auto);
  Serial.print("allow_to_start_program = ");
  Serial.println(allow_to_start_program);
  Serial.print("one_push = ");
  Serial.println(one_push);
  Serial.print("done_moving = ");
  Serial.println(done_moving);
  Serial.print("next_move = ");
  Serial.println(next_move);
  Serial.print("i_am_at_0 = ");
  Serial.println(i_am_at_0);
  Serial.print("last_step = ");
  Serial.println(last_step);
  Serial.print("next_move = ");
  Serial.println(next_move);
  Serial.print("go_to_counting = ");
  Serial.println(go_to_counting);

  Serial.print("axis1_count_ready = ");
  Serial.println(axis1_count_ready);
  Serial.print("axis2_count_ready = ");
  Serial.println(axis2_count_ready);
  Serial.print("axis3_count_ready = ");
  Serial.println(axis3_count_ready);
  Serial.print("axis4_count_ready = ");
  Serial.println(axis4_count_ready);
  Serial.print("axis5_count_ready = ");
  Serial.println(axis5_count_ready);
  Serial.print("axis6_count_ready = ");
  Serial.println(axis6_count_ready);
  Serial.print("digitalRead(startprog) = ");
  Serial.println(digitalRead(startprog));

    Serial.print("base_position = ");
  Serial.println(base_position);
     Serial.print("counter_stage = ");
  Serial.println(counter_stage);
  
  
  

}
if (digitalRead(prog1) == HIGH && digitalRead(prog2) == LOW){
  set_program_1 = true;
  set_program_2 = false;
}
//if (digitalRead(prog2) == HIGH && digitalRead(prog1) == LOW){
 // set_program_1 = false;
 // set_program_2 = true;
// }
if (set_program_1 == true && set_program_2 == false && digitalRead(MA) == LOW && digitalRead(base) == LOW && digitalRead(point0) == HIGH){
  program_1();
}
}
