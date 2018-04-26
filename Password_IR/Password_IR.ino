#include <IRremote.h>
#include <Password.h>

Password password = Password( "1234" );

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  irrecv.enableIRIn(); // Start the receiver
  Serial.begin(9600);
  Serial.print("Ready");
}

// Compare two tick values, returning 0 if newval is shorter,
// 1 if newval is equal, and 2 if newval is longer
// Use a tolerance of 20%
int compare(unsigned int oldval, unsigned int newval) {
  if (newval < oldval * .8) {
    return 0;
  } 
  else if (oldval < newval * .8) {
    return 2;
  } 
  else {
    return 1;
  }
}

// Use FNV hash algorithm: http://isthe.com/chongo/tech/comp/fnv/#FNV-param
#define FNV_PRIME_32 16777619
#define FNV_BASIS_32 2166136261

/* Converts the raw code values into a 32-bit hash code.
 * Hopefully this code is unique for each button.
 */
unsigned long decodeHash(decode_results *results) {
  unsigned long hash = FNV_BASIS_32;
  for (int i = 1; i+2 < results->rawlen; i++) {
    int value =  compare(results->rawbuf, results->rawbuf[i+2]);
    // Add value into the hash
    hash = (hash * FNV_PRIME_32) ^ value;
  }
  return hash;
}

void loop() {
  if (irrecv.decode(&results)) {
    unsigned long hash = decodeHash(&results);
    switch (hash) {
    case 0xB7CEF1C7: // 1 (10)
      password.append('1');
      break;
    case 0x3F3C26A7: // 2
      password.append('2');
      break;
    case 0x3021612B: // 3
      password.append('3');
      break;
    case 0x7EFFC747: // 4
      password.append('4');
      break;
    case 0xD8AD1F4B: // 5
      password.append('5');
      break;
    case 0x2CAD10E3: // 6
      password.append('6');
      break;
    case 0x1D924B67: // 7
      password.append('7');
      break;
    case 0xB93DEFA7: // 8
      password.append('8');
      break;
    case 0x12EB47AB: // 9
      password.append('9');
      break;
    case 0x275A9FCB: // 0
      password.append('0');
      break;
    case 0x20934FE3: //Power Button
      checkPassword(); 
      break;
    case 0x253F247: //TV/AV  
      password.reset();
      break;
    default:
      Serial.print("Unknown ");
      Serial.println(hash, HEX);    
    }
    irrecv.resume(); // Resume decoding (necessary!)
  }
}

void checkPassword(){
  if (password.evaluate()){
    Serial.println("Success");
    Serial.println("Code For Opening Door");
    //Add code to run if it works
    
    password.reset();
  }else{
    Serial.println("Wrong");
    Serial.println("Please Try Again");
    //add code to run if it did not work
    
    
  }
}


