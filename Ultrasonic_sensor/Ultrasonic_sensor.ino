/* Ultrasonic sensor HC-SR04
 *  http://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/
 */

#include <LiquidCrystal.h>

const int trigPin = 9;
const int echoPin = 10;


long duration;
int distance;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0, 1);
  /* Clears the trigPin */
  digitalWrite(trigPin, LOW);
  delay(2);

  /* Sets the trigPin on HIGH state for 10 microseconds */
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);

  /*Reads the echoPin, returns the sound wave travel time in microseconds */
  duration = pulseIn(echoPin, HIGH);

  /*Calculating distance */
  distance = duration*0.034/2;

  /* Prints the distance on the Serial Monitor */
  lcd.clear();
  lcd.print("Avstand: ");
  lcd.print(distance);
  lcd.print(" cm");
  delay(300);
}
