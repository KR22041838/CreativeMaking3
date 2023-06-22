#include <Wire.h>
#include "Adafruit_MPR121.h"

#ifndef _BV
#define _BV(bit) (1 << (bit)) 
#endif

Adafruit_MPR121 cap = Adafruit_MPR121();
uint16_t lasttouched = 0;
uint16_t currtouched = 0;

void setup() {
  Serial.begin(9600);

  while (!Serial) { // Needed to keep Leonardo/Micro from starting too fast!
    delay(10);
  }
  
 // Serial.println("Adafruit MPR121 Capacitive Touch sensor test"); 
  
  if (!cap.begin(0x5A)) {
  //  Serial.println("MPR121 not found, check wiring?");
  //  while (1);
  }
 // Serial.println("MPR121 found!");
//}
}
void loop() {
  currtouched = cap.touched();
  
  for (uint8_t i = 0; i < 5; i++) {
    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i))) {
      Serial.print(i);
   //   Serial.println(" touched");
      delay(200);
      // Send 'i' data to Unity
     // Serial.write('i');
    }
    
   // if (!(currtouched & _BV(i)) && (lasttouched & _BV(i))) {
   //   Serial.print(i);
   //   Serial.println(" released");
      
      // Send 'r' data to Unity
     // Serial.write('r');
  //  }
  }
  
  lasttouched = currtouched;
}
