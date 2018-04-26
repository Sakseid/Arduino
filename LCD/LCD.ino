#include <LiquidCrystal.h>
#include <dht.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);



void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0,0); 
  lcd.print("Gratulerer");
 
}
