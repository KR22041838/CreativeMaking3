const int buttonLedPin = 13;    // Pin connected to both the button and LED

void setup() {
  
  pinMode(buttonLedPin, INPUT_PULLUP);  // Set the pin as input with internal pull-up resistor
 Serial.begin(9600);  
}

void loop() {
  int buttonState = digitalRead(buttonLedPin);  // Read the button state

  if (buttonState == HIGH) {              // If the button is pressed (LOW state)
    digitalWrite(buttonLedPin, HIGH);    // Turn on the LED
    Serial.write(1);
    Serial.flush();
    delay(100);
  
  } else {
    digitalWrite(buttonLedPin, LOW);     // Turn off the LED
    Serial.write(2);
    Serial.flush();
    delay(100);
    
  }
}
