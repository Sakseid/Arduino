#include <IRremote.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

  
  const int RECV_PIN = 3;
  IRrecv irrecv(RECV_PIN);
  decode_results results;
  int t = 1;
  int kode[4];

void setup(){
  lcd.begin(16, 2);
  Serial.begin(9600);
  irrecv.enableIRIn();
  gratulerer();
}

void loop(){
  if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);
        irrecv.resume();
        translateIR(); 
  }
       
}

void gratulerer(){
        lcd.setCursor(0,0); 
        lcd.print("Gratulerer med");
        lcd.setCursor(0,1);
        lcd.print("dagen, Samuel!");
        }

void translateIR() // takes action based on IR code received
// describing Sony IR codes on LCD module
{
  switch(results.value)
  { 
    case 0xFF30CF: {
      lcd.print("1"); break;
      kode[t]=1;
      t++;
    }
    case 0xFF18E7: {
      lcd.print("2"); break;
      kode[t]=2;
      t++;
    }
    case 0xFF7A85:{
      lcd.print("3"); break;
      kode[t]=3;
      t++;
    }
    case 0xFF10EF: {
      lcd.print("4"); break;
      kode[t]=4;
      t++;
    }
    case 0xFF38C7: {
      lcd.print("5"); break;
      kode[t]=5;
      t++;
    }
    case 0xFF5AA5: {
      lcd.print("6"); break;
      kode[t]=6;
      t++;
    }
    case 0xFF42BD: {
      lcd.print("7"); break;
      kode[t]=7;
      t++;
    }
    case 0xFF4AB5: {
      lcd.print("8"); break;
      kode[t]=8;
      t++;
    }
    case 0xFF52AD: {
      lcd.print("9"); break;
      kode[t]=9;
      t++;
    }
    case 0xFF6897: {
      lcd.print("0"); break;
      kode[t]=0;
      t++;
    }
    case 0xFF906F: {
      lcd.clear();
      sjekkKode();
      t=0;
    }
  }
}

void sjekkKode(){
if (t==t){
  digitalWrite(4, HIGH);
  lcd.clear();
  lcd.print("Kode ok");
}
}


