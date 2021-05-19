void control_panel() {

if (digitalRead(button_green) == HIGH){
  allow_to_go = true;
  digitalWrite(enPin1, HIGH);
  digitalWrite(enPin2, HIGH);
  digitalWrite(enPin3, HIGH);
  digitalWrite(enPin4, HIGH);
  digitalWrite(enPin5, HIGH);
  digitalWrite(enPin6, HIGH);
  digitalWrite(diode_green, HIGH);
  digitalWrite(diode_red, LOW);
}


  
}
