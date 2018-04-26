#include <IRremote.h>
#include <LiquidCrystal.h>
#include <dht.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
dht DHT;
const int RECV_PIN = 0;
IRrecv irrecv(RECV_PIN);
decode_results results;



void setup(){
  lcd.begin(16, 2);
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop(){
  if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);
        irrecv.resume();
        lcd.setCursor(0,0); 
        lcd.print("Temp: ");
  }
}

