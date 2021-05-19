void manual_movement() {
  
unsigned long micro1time = micros();
unsigned long micro2time = micros();
unsigned long micro3time = micros();
unsigned long micro4time = micros();
unsigned long micro5time = micros();
unsigned long micro6time =  micros();

int delay1=analogRead(pot);
delay1=map(delay1, 0, 1023, 30, 1500);
int delay2=delay1;
int delay3=delay1;
int delay4=delay1;
int delay5=delay1;
int delay6=delay1;


//AXIS 1 MOVEMENT

if (digitalRead(axis1p) == HIGH && digitalRead(axis1m) == LOW)
{
 if (micro1time - micro1prev >=delay1)
{
  digitalWrite(dirPin1, LOW);
  micro1prev = micro1time;
  if (digitalRead(stepPin1 == LOW))
{
   digitalWrite(stepPin1, !digitalRead(stepPin1));
   ++step1;
 
} 
}}

// Going LOW after move up axis1
if (digitalRead(axis1p) == LOW && digitalRead(axis1m) == LOW && digitalRead(stepPin1) == HIGH && digitalRead(dirPin1) == LOW){
   if (micro1time - micro1prev >=delay1){
    micro1prev=micro1time;
    digitalWrite(stepPin1, LOW);
    ++step1;
   }
}
 


if (digitalRead(axis1m) == HIGH && digitalRead(axis1p) == LOW)
{
 if (micro1time - micro1prev >=delay1)
{
  digitalWrite(dirPin1, HIGH);
  micro1prev = micro1time;

   digitalWrite(stepPin1, !digitalRead(stepPin1));
   --step1;
  


}}

// Going LOW after move down axis1
if (digitalRead(axis1p) == LOW && digitalRead(axis1m) == LOW && digitalRead(stepPin1) == HIGH && digitalRead(dirPin1) == HIGH){
   if (micro1time - micro1prev >=delay1){
    micro1prev=micro1time;
    digitalWrite(stepPin1, LOW);
    --step1;
   }
}



//AXIS 2 MOVEMENT

if (digitalRead(axis2p) == HIGH && digitalRead(axis2m) == LOW)
{
 if (micro2time - micro2prev >=delay2)
{
  digitalWrite(dirPin2, HIGH);
  micro2prev = micro2time;

   digitalWrite(stepPin2, !digitalRead(stepPin2));
    ++step2;

 
}}

// Going LOW after move up axis2
if (digitalRead(axis2p) == LOW && digitalRead(axis2m) == LOW && digitalRead(stepPin2) == HIGH && digitalRead(dirPin2) == HIGH){
   if (micro2time - micro2prev >=delay2){
    micro2prev=micro2time;
    digitalWrite(stepPin2, LOW);
    ++step2;
   }
}


if (digitalRead(axis2m) == HIGH && digitalRead(axis2p) == LOW)
{
 if (micro2time - micro2prev >=delay2)
{
  digitalWrite(dirPin2, LOW);
  micro2prev = micro2time;

   digitalWrite(stepPin2, !digitalRead(stepPin2));
   --step2;

}}

// Going LOW after move down axis2
if (digitalRead(axis2p) == LOW && digitalRead(axis2m) == LOW && digitalRead(stepPin2) == HIGH && digitalRead(dirPin2) == LOW){
   if (micro2time - micro2prev >=delay2){
    micro2prev=micro2time;
    digitalWrite(stepPin2, LOW);
    --step2;
   }
}




//AXIS 3 MOVEMENT

if (digitalRead(axis3p) == HIGH && digitalRead(axis3m) == LOW)
{
 if (micro3time - micro3prev >=delay3)
{
  digitalWrite(dirPin3, HIGH);
  micro3prev = micro3time;

   digitalWrite(stepPin3, !digitalRead(stepPin3));
   ++step3;

 
}}

// Going LOW after move up axis3
if (digitalRead(axis3p) == LOW && digitalRead(axis3m) == LOW && digitalRead(stepPin3) == HIGH && digitalRead(dirPin3) == HIGH){
   if (micro3time - micro3prev >=delay3){
    micro3prev=micro3time;
    digitalWrite(stepPin3, LOW);
    ++step3;
   }
}


if (digitalRead(axis3m) == HIGH && digitalRead(axis3p) == LOW)
{
 if (micro3time - micro3prev >=delay3)
{
  digitalWrite(dirPin3, LOW);
  micro3prev = micro3time;

   digitalWrite(stepPin3, !digitalRead(stepPin3));
   --step3;

}}

// Going LOW after move down axis3
if (digitalRead(axis3p) == LOW && digitalRead(axis3m) == LOW && digitalRead(stepPin3) == HIGH && digitalRead(dirPin3) == LOW){
   if (micro3time - micro3prev >=delay3){
    micro3prev=micro3time;
    digitalWrite(stepPin3, LOW);
    --step3;
   }
}



//AXIS 4 MOVEMENT

if (digitalRead(axis4p) == HIGH && digitalRead(axis4m) == LOW)
{
 if (micro4time - micro4prev >=delay4)
{
  digitalWrite(dirPin4, HIGH);
  micro4prev = micro4time;

   digitalWrite(stepPin4, !digitalRead(stepPin4));
   ++step4;

 
}}

// Going LOW after move up axis4
if (digitalRead(axis4p) == LOW && digitalRead(axis4m) == LOW && digitalRead(stepPin4) == HIGH && digitalRead(dirPin4) == HIGH){
   if (micro4time - micro4prev >=delay4){
    micro4prev=micro4time;
    digitalWrite(stepPin4, LOW);
    ++step4;
   }
}

if (digitalRead(axis4m) == HIGH && digitalRead(axis4p) == LOW)
{
 if (micro4time - micro4prev >=delay4)
{
  digitalWrite(dirPin4, LOW);
  micro4prev = micro4time;

   digitalWrite(stepPin4, !digitalRead(stepPin4));
    --step4;

}}



// Going LOW after move down axis4
if (digitalRead(axis4p) == LOW && digitalRead(axis4m) == LOW && digitalRead(stepPin4) == HIGH && digitalRead(dirPin4) == LOW){
   if (micro4time - micro4prev >=delay4){
    micro4prev=micro4time;
    digitalWrite(stepPin4, LOW);
    --step4;
   }
}

//AXIS 5 MOVEMENT

if (digitalRead(axis5p) == HIGH && digitalRead(axis5m) == LOW)
{
 if (micro5time - micro5prev >=delay5)
{
  digitalWrite(dirPin5, HIGH);
  micro5prev = micro5time;

   digitalWrite(stepPin5, !digitalRead(stepPin5));
   ++step5;

 
}}

// Going LOW after move up axis5
if (digitalRead(axis5p) == LOW && digitalRead(axis5m) == LOW && digitalRead(stepPin5) == HIGH && digitalRead(dirPin5) == HIGH){
   if (micro5time - micro5prev >=delay5){
    micro5prev=micro5time;
    digitalWrite(stepPin5, LOW);
    ++step5;
   }
}

if (digitalRead(endstop5) == LOW) {
if (digitalRead(axis5m) == HIGH && digitalRead(axis5p) == LOW)
{
 if (micro5time - micro5prev >=delay5)
{
  digitalWrite(dirPin5, LOW);
  micro5prev = micro5time;

   digitalWrite(stepPin5, !digitalRead(stepPin5));
    --step5;

}}}

// Going LOW after move down axis5
if (digitalRead(axis5p) == LOW && digitalRead(axis5m) == LOW && digitalRead(stepPin5) == HIGH && digitalRead(dirPin5) == LOW){
   if (micro5time - micro5prev >=delay5){
    micro5prev=micro5time;
    digitalWrite(stepPin5, LOW);
    --step5;
   }
}


//AXIS 6 MOVEMENT

if (digitalRead(axis6p) == HIGH && digitalRead(axis6m) == LOW)
{
 if (micro6time - micro6prev >=delay6)
{
  digitalWrite(dirPin6, HIGH);
  micro6prev = micro6time;

   digitalWrite(stepPin6, !digitalRead(stepPin6));
   ++step6;

 
}}


// Going LOW after move up axis6
if (digitalRead(axis6p) == LOW && digitalRead(axis6m) == LOW && digitalRead(stepPin6) == HIGH && digitalRead(dirPin6) == HIGH){
   if (micro6time - micro6prev >=delay6){
    micro6prev=micro6time;
    digitalWrite(stepPin6, LOW);
    ++step6;
   }
}


if (digitalRead(axis6m) == HIGH && digitalRead(axis6p) == LOW)
{
 if (micro6time - micro6prev >=delay6)
{
  digitalWrite(dirPin6, LOW);
  micro6prev = micro6time;

   digitalWrite(stepPin6, !digitalRead(stepPin6));
   --step6;

}}

// Going LOW after move down axis6
if (digitalRead(axis6p) == LOW && digitalRead(axis6m) == LOW && digitalRead(stepPin6) == HIGH && digitalRead(dirPin6) == LOW){
   if (micro6time - micro6prev >=delay6){
    micro6prev=micro6time;
    digitalWrite(stepPin6, LOW);
    --step6;
   }
}

}
