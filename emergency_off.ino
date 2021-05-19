void emergency_off(){

digitalWrite(enPin1, LOW);
digitalWrite(enPin2, LOW);
digitalWrite(enPin3, LOW);
digitalWrite(enPin4, LOW);
digitalWrite(enPin5, LOW);
digitalWrite(enPin6, LOW);
digitalWrite(stepPin1, LOW);
digitalWrite(stepPin2, LOW);
digitalWrite(stepPin3, LOW);
digitalWrite(stepPin4, LOW);
digitalWrite(stepPin5, LOW);
digitalWrite(stepPin6, LOW);

allow_to_go = false;
find_first_pos = false;
szukanie_krancowek = false;  
i_am_at_0 = false;
allow_to_start_program = false;
 you_can_move_auto == false;
 Program_1_ON = false;
}
