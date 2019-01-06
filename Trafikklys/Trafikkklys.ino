boolean buttonOn = false;

void setup() {
    // put your setup code here, to run once:
    pinMode(9, OUTPUT); // configure piezo as output
    pinMode(8, INPUT);
    pinMode(7, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(1, OUTPUT);
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);    
}

void loop() {
    if (digitalRead(8) == HIGH){
        delay(50); // software debounce
        if (digitalRead(8) == HIGH) {
            // if the switch is HIGH, ie. pushed down - change the lights!
            delay(1500);
            changeToRed();
            delay(1500);
            pedestrian();
            changeToGreen();
        }
    }
}

void changeToRed(){
    // green off, yellow on for 3 seconds
    digitalWrite(4, LOW);
    digitalWrite(2, HIGH);
    delay(3000);

    // turn off yellow, then turn red on for 5 seconds
    digitalWrite(2, LOW);
    digitalWrite(1, HIGH);
    delay(2000);
}

void changeToGreen(){
    // red and yellow on for 2 seconds (red is already on though)
    digitalWrite(2, HIGH);
    delay(2000);

    // turn off red and yellow, then turn on green
    digitalWrite(2, LOW);
    digitalWrite(1, LOW);
    digitalWrite(4, HIGH);
    delay(3000);
}

void pedestrian(){
  int teller = 0;
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    delay(3000);
    while (teller<6){
    digitalWrite(7, LOW);
    delay(300);
    digitalWrite(7, HIGH);
    tone(9, 3000);
    delay(300);
    noTone(9);
    teller++;
    }
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    delay(1500);
}
