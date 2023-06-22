#include <Wire.h>
#include "Adafruit_MPR121.h"

#ifndef _BV
#define _BV(bit) (1 << (bit)) 
#endif

Adafruit_MPR121 cap = Adafruit_MPR121();
uint16_t lasttouched = 0;
uint16_t currtouched = 0;


const int redLED = 11;      // Pin connected to the red button and LED
const int greenLED = 10;    // Pin connected to the green button and LED
const int blueLED = 9;      // Pin connected to the blue button and LED
const int yellowLED = 8;

void setup() {
  Serial.begin(9600);
 
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);

 


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


    if (Serial.available() > 0) {
    byte receivedByte = Serial.read();
    if (receivedByte == '1') {
      digitalWrite(redLED, HIGH);
      digitalWrite(greenLED, LOW);
      digitalWrite(blueLED, LOW);
      digitalWrite(yellowLED, LOW);

    }
    else if (receivedByte == '2') {
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, HIGH);
      digitalWrite(blueLED, LOW);
      digitalWrite(yellowLED, LOW);
    }
    else if (receivedByte == '3') {
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, LOW);
      digitalWrite(blueLED, HIGH);
      digitalWrite(yellowLED, LOW);
    }
    else if (receivedByte == '4') {
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, LOW);
      digitalWrite(blueLED, LOW);
      digitalWrite(yellowLED, HIGH);
    }
  }
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
