// Final code for Adruino and Unity Communication using a touch capacitor and LED's.
/* The code has been adapted from This:

This a library for the MPR121 12-channel Capacitive touch sensor

Designed specifically to work with the MPR121 Breakout in the Adafruit shop 
  ----> https://www.adafruit.com/products/

These sensors use I2C communicate, at least 2 pins are required 
to interface

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Limor Fried/Ladyada for Adafruit Industries.  
BSD license, all text above must be included in any redistributio:
*/ 

#include <Wire.h>
#include "Adafruit_MPR121.h"

#ifndef _BV                   //define Bit Value
#define _BV(bit) (1 << (bit)) //create binary value of 1 bit set to 1
#endif

Adafruit_MPR121 cap = Adafruit_MPR121();
uint16_t lasttouched = 0;   //unsigned 16bit integer, lasttouch variable initalised to 0
uint16_t currtouched = 0;   //unsigned 16bit integer, currenttouch variable initalised to 0


const int redLED = 11;      // Pin connected to the red button and LED
const int greenLED = 10;    // Pin connected to the green button and LED
const int blueLED = 9;      // Pin connected to the blue button and LED
const int yellowLED = 8;    // Pin connected to the yellow button and LED

void setup() {
  Serial.begin(9600);
 
  pinMode(redLED, OUTPUT);    //Setting LED's as Outputs
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);


  while (!Serial) {   // Prevent Leonardo from starting too fast
    delay(10);
  }
  
  
  if (!cap.begin(0x5A)) {// Initialize the MPR121 capacitive touch sensor
    // Error handling if sensor initialization fails
}
}
void loop() {


    if (Serial.available() > 0) {        // check if incoming serial data available from Unity
    byte receivedByte = Serial.read();   //read byte from serial input buffer
    if (receivedByte == '1') {           //if byte from unity is equal to 1 execute code block
      digitalWrite(redLED, HIGH);        //Turn red LED on and others off
      digitalWrite(greenLED, LOW);
      digitalWrite(blueLED, LOW);
      digitalWrite(yellowLED, LOW);

    }
    else if (receivedByte == '2') {     //if byte from unity is equal to 2 execute code block
      digitalWrite(redLED, LOW);        //Turn green LED on and others off
      digitalWrite(greenLED, HIGH);
      digitalWrite(blueLED, LOW);
      digitalWrite(yellowLED, LOW);
    }
    else if (receivedByte == '3') {     //if byte from unity is equal to 3 execute code block
      digitalWrite(redLED, LOW);        //Turn blue LED on and others off
      digitalWrite(greenLED, LOW);
      digitalWrite(blueLED, HIGH);
      digitalWrite(yellowLED, LOW);
    }
    else if (receivedByte == '4') {     //if byte from unity is equal to 4 execute code block
      digitalWrite(redLED, LOW);        //Turn yellow LED on and others off
      digitalWrite(greenLED, LOW);
      digitalWrite(blueLED, LOW);
      digitalWrite(yellowLED, HIGH);
    }
  }
  currtouched = cap.touched(); // Get the current touch status from the sensor
  
  for (uint8_t i = 0; i < 5; i++) {  //initialised loop counter variable i to 0 for incriments upto 4
    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i))) {
      Serial.print(i);           // Print the index of the touched button
      delay(200);
   
    }
  
  lasttouched = currtouched;// Update the previous touch status for the next iteration
}
