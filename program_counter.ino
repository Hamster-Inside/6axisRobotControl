  void program_counter(){
  unsigned long millis1timer = millis();
 if (end_of_program1 == false){

if (counter_stage == 0){
  Serial.println("counter stage 0"); 
if (base_position == 0)
{
  Serial.println("Pierwsze ruchy");
  wait_before = 1000;
axis1_next_position = 0;
axis2_next_position = 0;
axis3_next_position = 0;
axis4_next_position = 0;
axis5_next_position = 0;
axis6_next_position = 0;
++counter_stage;
}

if (base_position == 1)
{
  Serial.println("Drugie ruchy");
    wait_before = 1000;
axis1_next_position = 0;
axis2_next_position = -31392;
axis3_next_position = -61600;
axis4_next_position = 0;
axis5_next_position = -594;
axis6_next_position = 0;
++counter_stage;
}

if (base_position == 2)
{
  Serial.println("Trzecie ruchy");
    wait_before = 1000;
axis1_next_position = 0;
axis2_next_position = -62840;
axis3_next_position = 0;
axis4_next_position = 0;
axis5_next_position = -8534;
axis6_next_position = 0;
++counter_stage;
}

if (base_position == 3)
{
  Serial.println("Drugie ruchy");
    wait_before = 1000;
axis1_next_position = 0;
axis2_next_position = -31392;
axis3_next_position = -61600;
axis4_next_position = 0;
axis5_next_position = -594;
axis6_next_position = 0;
++counter_stage;
}
if (base_position == 4)
{
  Serial.println("Pierwsze ruchy");
  wait_before = 1000;
axis1_next_position = 0;
axis2_next_position = 0;
axis3_next_position = 0;
axis4_next_position = 0;
axis5_next_position = 0;
axis6_next_position = 0;
++counter_stage;
}

if (base_position == 5){
  end_of_program1 = true;    //STOP OF THE PROGRAM
  base_position = 0;
  counter_stage = 0;
  Serial.println("stop programu");
}
}
if (counter_stage == 1){
    Serial.println("counter stage 1"); 
if (axis1_next_position != step1){
axis1_moveto = axis1_next_position-step1;
Serial.println("Przeliczenia dla 1");
Serial.print("axis1_moveto =  ");
Serial.println(axis1_moveto);
axis1_count_ready = true;
}
else{
axis1_count_ready = true; 
}


if (axis2_next_position != step2){
axis2_moveto = axis2_next_position-step2;
Serial.println("Przeliczenia dla 2");
Serial.print("axis2_moveto =  ");
Serial.println(axis2_moveto);
axis2_count_ready = true;
}
else{
axis2_count_ready = true; 
}

if (axis3_next_position != step3){
axis3_moveto = axis3_next_position-step3;
Serial.println("Przeliczenia dla 3");
Serial.print("axis3_moveto =  ");
Serial.println(axis3_moveto);
axis3_count_ready = true;
}
else{
axis3_count_ready = true; 
}

if (axis4_next_position != step4){
axis4_moveto = axis4_next_position-step4;
Serial.println("Przeliczenia dla 4");
Serial.print("axis4_moveto =  ");
Serial.println(axis4_moveto);
axis4_count_ready = true;
}
else{
axis4_count_ready = true; 
}

if (axis5_next_position != step5){
axis5_moveto = axis5_next_position-step5;
Serial.println("Przeliczenia dla 5");
Serial.print("axis5_moveto =  ");
Serial.println(axis5_moveto);
axis5_count_ready = true;
}
else{
axis5_count_ready = true; 
}

if (axis6_next_position != step6){
axis6_moveto = axis6_next_position-step6;
Serial.println("Przeliczenia dla 6");
Serial.print("axis6_moveto =  ");
Serial.println(axis6_moveto);
axis6_count_ready = true;
}
else{
axis6_count_ready = true; 
}
if (axis1_count_ready && axis1_count_ready && axis1_count_ready && axis1_count_ready && axis1_count_ready && axis1_count_ready == true){
  ++counter_stage;
}
}
if (counter_stage == 2){
    Serial.println("counter stage 2"); 
if (axis1_next_position != step1){
   prepareMovement( 0, axis1_moveto );   // axis 1 move
   prepare1done = true;
}
else{
   prepare1done = true;
}
if (axis2_next_position != step2){
   prepareMovement( 1, axis2_moveto );   // axis 2 move
   prepare2done = true;
}
else{
   prepare2done = true;
}
if (axis3_next_position != step3){
   prepareMovement( 2, axis3_moveto );   // axis 3 move
   prepare3done = true;
}
else{
   prepare3done = true;
}
if (axis4_next_position != step4){
   prepareMovement( 3, axis4_moveto );   // axis 4 move
   prepare4done = true;
}
else{
   prepare4done = true;
}
if (axis5_next_position != step5){
   prepareMovement( 4, axis5_moveto );   // axis 5 move
   prepare5done = true;
}
else{
   prepare5done = true;
}
if (axis6_next_position != step6){
   prepareMovement( 5, axis6_moveto );   // axis 6 move
   prepare6done = true;
}
else{
   prepare6done = true;
}
if (prepare1done && prepare2done && prepare3done && prepare4done && prepare5done && prepare6done == true){
  ++counter_stage;
}
}
if (counter_stage == 3){
    Serial.println("counter stage 3"); 
prepare1done = false;
prepare2done = false;
prepare3done = false;
prepare4done = false;
prepare5done = false;
prepare6done = false;
axis1_count_ready = false;
axis2_count_ready = false;
axis3_count_ready = false;
axis4_count_ready = false;
axis5_count_ready = false;
axis6_count_ready = false;
go_next_step = false;
 ++counter_stage;
  millis1compare = millis1timer;
}
if (counter_stage == 4){
   if (millis1timer - millis1compare >=wait_before)
{
  Serial.println("odczekanie 1 sek");
 ++counter_stage;
  millis1compare = millis1timer;
}
}
if (counter_stage == 5 && go_next_step == false){
  runAndWait();
}
if (axis1_next_position == step1 && axis2_next_position == step2 && axis3_next_position == step3 && axis4_next_position == step4 && axis5_next_position == step5 && axis6_next_position == step6 && go_next_step == false){
    done_running = true;
    ++base_position;
    Serial.println("wszystko na pozycji i mozna isc next");
    counter_stage = 0;
    go_next_step = true;
} 
}}

