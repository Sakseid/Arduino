/*
   IR Remote Password lock script
   -------------------------------
   Company: Distro Studios
   Developer: Ajith Gopi
   YouTube: https://www.youtube.com/user/ajithgopikklm
   Facebook: https://www.facebook.com/AjithJishnuGopi

   Thanks to
   -------------------------------
   IRremote.h developer.

   Circuit:

    - IR reciever connected to pin PWM pin 11 (like described in ir_get_hex code).
    - Green LED connected to pin 7.
    - Red LED connected to pin 8.
    - Buzzer connected to pin 4.
*/
#include <IRremote.h>

/*Edit these settings*/
//Password and security
String pass = "1234"; //Password to unlock. be sure to edit the '5' inside '[]' to password length +1.
int chances = 3; //Chances before buzzer will start to buzz continuously.
bool afterChances = true; /*Is possible to enter password after
  running out of chances. true = yes. (not recommended to set
  false, Arduino must be restarted to enter password if set
  to false.).If set true, buzzer will stop when correct password is
  entered after running out of chances.*/


//Pins
int RECV_PIN = 11; //IR Reciever pin (PWM).
int greenLed = 7; //Green LED pin.
int redLed = 8; //Red Led pin.
int buzzer = 4; //Buzzer pin.

//remote buttons
String btn1 = "ff30cf"; //Your button 1 IR HEX code (in lower case). eg.: ff63ad
String btn2 = "ff18e7"; //Your button 2 IR HEX code (in lower case).
String btn3 = "ff7a85";
String btn4 = "ff10ef";
String btn5 = "ff38c7";
String btn6 = "ff5aa5";
String btn7 = "ff42bd";
String btn8 = "ff4ab5";
String btn9 = "ff52b5";
String btn0 = "ff6897";
String btnReset = "ff906f"; //Your Reset button IR hex code.

//Misc
bool shouldBeep = true;
bool unlockSound = true;

/*Don't edit anything below this if you don't what you are doing.
   Somethimes, it can cause high load to your arduino.
*/
bool locked = true;
String cPass = "";
int chance = 0;
String cmp = "----Distro Studios-----\n";
IRrecv irrecv(RECV_PIN);
decode_results results;
String str2 = "os-----\n";
void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  irrecv.enableIRIn();
  Serial.begin(9600);
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, LOW);
  Serial.print(cmp);
}

void loop() {
  if (cmp.endsWith(str2) == false)
    Serial.print("Error!");
  else {
    if (irrecv.decode(&results)) {

      if (String(results.value, HEX) == btn1) {
        Serial.print("1");
        updatePass("1");
      }
      else if (String(results.value, HEX) == btn2) {
        Serial.print("2");
        updatePass("2");
      }
      else if (String(results.value, HEX) == btn3) {
        Serial.print("3");
        updatePass("3");
      }
      else if (String(results.value, HEX) == btn4) {
        Serial.print("4");
        updatePass("4");
      }
      else if (String(results.value, HEX) == btn5) {
        Serial.print("5");
        updatePass("5");
      }
      else if (String(results.value, HEX) == btn6) {
        Serial.print("6");
        updatePass("6");
      }
      else if (String(results.value, HEX) == btn7) {
        Serial.print("7");
        updatePass("7");
      }
      else if (String(results.value, HEX) == btn8) {
        Serial.print("8");
        updatePass("8");
      }
      else if (String(results.value, HEX) == btn9) {
        Serial.print("9");
        updatePass("9");
      }
      else if (String(results.value, HEX) == btn0) {
        Serial.print("0");
        updatePass("0");
      }
      else if (String(results.value, HEX) == btnReset) {
        resetPass();
        Serial.println("\nRESET");
      }
      irrecv.resume(); // Receive the next value
    }
    if (chance > chances)
      digitalWrite(buzzer, HIGH);//buzzer

    if (locked == true) {
      digitalWrite(redLed, HIGH);
      digitalWrite(greenLed, LOW);
    }
    else {
      digitalWrite(redLed, LOW);
      digitalWrite(greenLed, HIGH);
    }
  }
}

bool updatePass(String ch) {
  if (locked == false)
    return false;
  beep();
  if (updatable() == true) {
    cPass += ch;
    if (cPass.length() < pass.length()) {

    }
    else {
      if (pass == cPass) {
        locked = false;
        digitalWrite(greenLed, HIGH);
        digitalWrite(redLed, LOW);
        chance = 0;
        Serial.println("\nUNLOCKED");
        if (unlockSound == true) {
          delay(60);
          digitalWrite(buzzer, HIGH);
          delay(150);
          digitalWrite(buzzer, LOW);
          delay(100);
          digitalWrite(buzzer, HIGH);
          delay(200);
          digitalWrite(buzzer, LOW);
        }
      }
      else {
        cPass = "";
        chance += 1;
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        Serial.println("\nWRONG PASSWORD!");
      }
    }
  }
}

bool updatable() {
  if (chance <= chances)
    return true;
  return afterChances;
}

void resetPass() {
  cPass = "";
  locked = true;
}

void beep() {
  if (shouldBeep == true) {
    digitalWrite(buzzer, HIGH);
    delay(60);
    digitalWrite(buzzer, LOW);
  }
}
