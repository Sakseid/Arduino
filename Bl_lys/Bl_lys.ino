void setup() {
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);

}

void loop() {
    right();
    right();
    right();
    left();
    left();
    left();

}

void right(){
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  delay(70);
  
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  delay(70);
}


void left(){

  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  delay(70);
  
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  delay(70);
}
