void go_position_0(){

unsigned long micro1time = micros();
unsigned long micro2time = micros();
unsigned long micro3time = micros();
unsigned long micro4time = micros();
unsigned long micro5time = micros();
unsigned long micro6time = micros();
int delay1=100;
int delay2=delay1;
int delay3=delay1;
int delay4=delay1;
int delay5=delay1;
int delay6=delay1;
next_move = false;
go_round_program1 = false;
you_can_move_auto = false;


if (digitalRead(indsensePin1) == LOW && digitalRead(indsensePin2) == LOW && digitalRead(indsensePin3) == LOW && digitalRead(indsensePin4) == LOW && digitalRead(endstop5) == HIGH && digitalRead(indsensePin6) == LOW)
{
 szukanie_krancowek = true;
}


// SEARCHING FOR END STOPS
if (szukanie_krancowek == true){
  
  
 // AXIS 1 FINDING ITS POSITION 0 from end stop
 if (digitalRead(indsensePin1) == LOW){
   if (micro1time - micro1prev >=delay1){
  digitalWrite(dirPin1, LOW);
  micro1prev = micro1time;

   digitalWrite(stepPin1, !digitalRead(stepPin1));
}} 
  
  
 // AXIS 2 FINDING ITS POSITION 0 from end stop
 if (digitalRead(indsensePin2) == LOW){
if (micro2time - micro2prev >=delay2){
  digitalWrite(dirPin2, HIGH);
  micro2prev = micro2time;

  digitalWrite(stepPin2, !digitalRead(stepPin2));
}}

 // AXIS 3 FINDING ITS POSITION 0 from end stop
 if (digitalRead(indsensePin3) == LOW){
if (micro3time - micro3prev >=delay3){
  digitalWrite(dirPin3, HIGH);
  micro3prev = micro3time;

  digitalWrite(stepPin3, !digitalRead(stepPin3));
}}


 // AXIS 4 FINDING ITS POSITION 0 from end stop
 if (digitalRead(indsensePin4) == LOW){
if (micro4time - micro4prev >=delay4){
  digitalWrite(dirPin4, HIGH);
  micro4prev = micro4time;

  digitalWrite(stepPin4, !digitalRead(stepPin4));
}}


 // AXIS 5 FINDING ITS POSITION 0 from end stop
 if (digitalRead(endstop5) == HIGH){
if (micro5time - micro5prev >=delay5){
  digitalWrite(dirPin5, HIGH);
  micro2prev = micro5time;

  digitalWrite(stepPin5, !digitalRead(stepPin5));
}}


 // AXIS 6 FINDING ITS POSITION 0 from end stop
 if (digitalRead(indsensePin6) == LOW){
if (micro6time - micro6prev >=delay6){
  digitalWrite(dirPin6, HIGH);
  micro6prev = micro6time;

  digitalWrite(stepPin6, !digitalRead(stepPin6));
}}
// JEŻELI ZNALEZIONE KRANCÓWKI W POZYCJI 0 ZAPISZ POZYCJE 0 I POZWOL ISC DO POCZATKU
if (digitalRead(indsensePin1) == HIGH && digitalRead(indsensePin2) == HIGH && digitalRead(indsensePin3) == HIGH && digitalRead(indsensePin4) == HIGH && digitalRead(endstop5) ==LOW && digitalRead(indsensePin6) == HIGH && find_first_pos == false){

step1=0;
step2=0;
step3=0;
step4=0;
step5=0;
step6=0;
find_first_pos = true;
szukanie_krancowek = false;


}}

if (find_first_pos == true) {

  // FIND AXIS 1 POSITION 0
  if (step1 < axis1_0) {
     if (micro1time - micro1prev >=delay1)
{
  digitalWrite(dirPin1, LOW);
  micro1prev = micro1time;

   digitalWrite(stepPin1, !digitalRead(stepPin1));
   ++step1;
}}

 if (step1 > axis1_0) {
     if (micro1time - micro1prev >=delay1)
{
  digitalWrite(dirPin1, HIGH);
  micro1prev = micro1time;

   digitalWrite(stepPin1, !digitalRead(stepPin1));
   --step1;
}}

 // FIND AXIS 2 POSITION 0
  if (step2 < axis2_0) {
     if (micro2time - micro2prev >=delay2)
{
  digitalWrite(dirPin2, HIGH);
  micro2prev = micro2time;

   digitalWrite(stepPin2, !digitalRead(stepPin2));
   ++step2;
}}

 if (step2 > axis2_0) {
     if (micro2time - micro2prev >=delay2)
{
  digitalWrite(dirPin2, LOW);
  micro2prev = micro2time;

   digitalWrite(stepPin2, !digitalRead(stepPin2));
   --step2;
}}

  // FIND AXIS 3 POSITION 0
  if (step3 < axis3_0) {
     if (micro3time - micro3prev >=delay3)
{
  digitalWrite(dirPin3, HIGH);
  micro3prev = micro3time;

   digitalWrite(stepPin3, !digitalRead(stepPin3));
   ++step3;
}}

 if (step3 > axis3_0) {
     if (micro3time - micro3prev >=delay3)
{
  digitalWrite(dirPin3, LOW);
  micro3prev = micro3time;

   digitalWrite(stepPin3, !digitalRead(stepPin3));
   --step3;
}}

  // FIND AXIS 4 POSITION 0
  if (step4 < axis4_0) {
     if (micro4time - micro4prev >=delay4)
{
  digitalWrite(dirPin4, HIGH);
  micro4prev = micro4time;

   digitalWrite(stepPin4, !digitalRead(stepPin4));
   ++step4;
}}

 if (step4 > axis4_0) {
     if (micro4time - micro4prev >=delay4)
{
  digitalWrite(dirPin4, LOW);
  micro4prev = micro4time;

   digitalWrite(stepPin4, !digitalRead(stepPin4));
   --step4;
}}

  // FIND AXIS 5 POSITION 0
  if (step5 < axis5_0) {
     if (micro5time - micro5prev >=delay5)
{
  digitalWrite(dirPin5, HIGH);
  micro5prev = micro5time;

   digitalWrite(stepPin5, !digitalRead(stepPin5));
   ++step5;
}}

 if (step5 > axis5_0) {
     if (micro5time - micro5prev >=delay5)
{
  digitalWrite(dirPin5, LOW);
  micro5prev = micro5time;

   digitalWrite(stepPin5, !digitalRead(stepPin5));
   --step5;
}}

  // FIND AXIS 6 POSITION 0
  if (step6 < axis6_0) {
     if (micro6time - micro6prev >=delay6)
{
  digitalWrite(dirPin6, HIGH);
  micro6prev = micro6time;

   digitalWrite(stepPin6, !digitalRead(stepPin6));
   ++step6;
}}

 if (step6 > axis6_0) {
     if (micro6time - micro6prev >=delay6)
{
  digitalWrite(dirPin6, LOW);
  micro6prev = micro6time;

   digitalWrite(stepPin6, !digitalRead(stepPin6));
   --step6;
}}
}

if (step1 == axis1_0 && step2 == axis2_0 && step3 == axis3_0 && step4 == axis4_0 && step5 == axis5_0 && step6 == axis6_0 && i_am_at_0 == false) {
digitalWrite(stepPin1, LOW);
digitalWrite(stepPin2, LOW);
digitalWrite(stepPin3, LOW);
digitalWrite(stepPin4, LOW);
digitalWrite(stepPin5, LOW);
digitalWrite(stepPin6, LOW);
step1=0;
step2=0;
step3=0;
step4=0;
step5=0;
step6=0;
i_am_at_0 = true;
find_first_pos = false;
}

if (i_am_at_0 == true){
    // FIND AXIS 1 POSITION 0
  if (step1 < axis1_00) {
     if (micro1time - micro1prev >=delay1)
{
  digitalWrite(dirPin1, LOW);
  micro1prev = micro1time;

   digitalWrite(stepPin1, !digitalRead(stepPin1));
   ++step1;
}}

 if (step1 > axis1_00) {
     if (micro1time - micro1prev >=delay1)
{
  digitalWrite(dirPin1, HIGH);
  micro1prev = micro1time;

   digitalWrite(stepPin1, !digitalRead(stepPin1));
   --step1;
}}

 // FIND AXIS 2 POSITION 0
  if (step2 < axis2_00) {
     if (micro2time - micro2prev >=delay2)
{
  digitalWrite(dirPin2, HIGH);
  micro2prev = micro2time;

   digitalWrite(stepPin2, !digitalRead(stepPin2));
   ++step2;
}}

 if (step2 > axis2_00) {
     if (micro2time - micro2prev >=delay2)
{
  digitalWrite(dirPin2, LOW);
  micro2prev = micro2time;

   digitalWrite(stepPin2, !digitalRead(stepPin2));
   --step2;
}}

  // FIND AXIS 3 POSITION 0
  if (step3 < axis3_00) {
     if (micro3time - micro3prev >=delay3)
{
  digitalWrite(dirPin3, HIGH);
  micro3prev = micro3time;

   digitalWrite(stepPin3, !digitalRead(stepPin3));
   ++step3;
}}

 if (step3 > axis3_00) {
     if (micro3time - micro3prev >=delay3)
{
  digitalWrite(dirPin3, LOW);
  micro3prev = micro3time;

   digitalWrite(stepPin3, !digitalRead(stepPin3));
   --step3;
}}

  // FIND AXIS 4 POSITION 0
  if (step4 < axis4_00) {
     if (micro4time - micro4prev >=delay4)
{
  digitalWrite(dirPin4, HIGH);
  micro4prev = micro4time;

   digitalWrite(stepPin4, !digitalRead(stepPin4));
   ++step4;
}}

 if (step4 > axis4_00) {
     if (micro4time - micro4prev >=delay4)
{
  digitalWrite(dirPin4, LOW);
  micro4prev = micro4time;

   digitalWrite(stepPin4, !digitalRead(stepPin1));
   --step4;
}}

  // FIND AXIS 5 POSITION 0
  if (step5 < axis5_00) {
     if (micro5time - micro5prev >=delay5)
{
  digitalWrite(dirPin5, HIGH);
  micro5prev = micro5time;

   digitalWrite(stepPin5, !digitalRead(stepPin5));
   ++step5;
}}

 if (step5 > axis5_00) {
     if (micro5time - micro5prev >=delay5)
{
  digitalWrite(dirPin5, LOW);
  micro5prev = micro5time;

   digitalWrite(stepPin5, !digitalRead(stepPin5));
   --step5;
}}

  // FIND AXIS 6 POSITION 0
  if (step6 < axis6_00) {
     if (micro6time - micro6prev >=delay6)
{
  digitalWrite(dirPin6, HIGH);
  micro6prev = micro6time;

   digitalWrite(stepPin6, !digitalRead(stepPin6));
   ++step6;
}}

 if (step6 > axis6_00) {
     if (micro6time - micro6prev >=delay6)
{
  digitalWrite(dirPin6, LOW);
  micro6prev = micro6time;

   digitalWrite(stepPin6, !digitalRead(stepPin6));
   --step6;
}}
}

}
