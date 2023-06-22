// TOO MANY SERIAL.WRITE(); IS AMBIGUOUS CHANGE TO BYTES

const int redButton = 13;    // Pin connected to both the button and LED
const int greenButton = 10;    // Pin connected to both the button and LED
const int blueButton = 8;    // Pin connected to both the button and LED
const int yellowButton = 2;    // Pin connected to both the button and LED

void setup() {
  Serial.begin(9600);  
  pinMode(redButton, INPUT_PULLUP);  // Set the pin as input with internal pull-up resistor
  pinMode(greenButton, INPUT_PULLUP);  // Set the pin as input with internal pull-up resistor
  pinMode(blueButton, INPUT_PULLUP);  // Set the pin as input with internal pull-up resistor
  pinMode(yellowButton, INPUT_PULLUP);  // Set the pin as input with internal pull-up resistor
 
}

void loop() {
  // Read the button state
  int buttonStateRed = digitalRead(redButton);
  int buttonStateGreen = digitalRead(greenButton);
  int buttonStateBlue= digitalRead(blueButton);
  int buttonStateYellow = digitalRead(yellowButton);

  if (buttonStateRed == HIGH) {              // If the button is pressed (LOW state)
    digitalWrite(redButton, HIGH);    // Turn on the LED
    digitalWrite(greenButton, LOW);
    digitalWrite(blueButton, LOW);
    digitalWrite(yellowButton, LOW);

    //Serial Communication 
    Serial.print(1); // debugging purpose only,adds '0's to Unity console
   // Serial.write(1);
    Serial.flush();
    delay(100);
  }
  
    else if  (buttonStateGreen == HIGH) {              // If the button is pressed (LOW state)
    digitalWrite(redButton, LOW);    // Turn on the LED
    digitalWrite(greenButton, HIGH);
    digitalWrite(blueButton, LOW);
    digitalWrite(yellowButton, LOW);
      
    //Serial Communication 
    Serial.print(2); // debugging purpose only,adds '0's to Unity console
   // Serial.write(2);
    Serial.flush();
    delay(100);
    }


    else if  (buttonStateBlue == HIGH) {              // If the button is pressed (LOW state)
    digitalWrite(redButton, LOW);    // Turn on the LED
    digitalWrite(greenButton, LOW);
    digitalWrite(blueButton, HIGH);
    digitalWrite(yellowButton, LOW);

    //Serial Communication 
    Serial.print(3); // debugging purpose only,adds '0's to Unity console
    //Serial.write(3);
    Serial.flush();
    delay(100);
    }

    else if  (buttonStateYellow == HIGH) {              // If the button is pressed (LOW state)
    digitalWrite(redButton, LOW);    // Turn on the LED
    digitalWrite(greenButton, LOW);
    digitalWrite(blueButton, LOW);
    digitalWrite(yellowButton, HIGH);

    //Serial Communication 
    Serial.print(4); // debugging purpose only,adds '0's to Unity console
   // Serial.write(4);
    Serial.flush();
    delay(100);
    }

  
    else {
    digitalWrite(redButton, LOW);
    digitalWrite(greenButton, LOW);
    digitalWrite(blueButton, LOW);
    digitalWrite(yellowButton, LOW);// Turn off the LED
    Serial.print(0);
    //Serial.write(0);
    Serial.flush();
    delay(100);
    
  }
}
