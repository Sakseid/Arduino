#include <IRremote.h>
/*
 * Circuit:-
 * 
 * 3 pin ir sensor's (facing you):
 * - 1st pin connected to ground
 * - 2nd pin connected to 5V
 * - 3rd pin connected to digital pin 11 (PWM)
 */
int RECV_PIN = 11;//(PWM)

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(String(results.value, HEX));
    irrecv.resume();
  }
}
