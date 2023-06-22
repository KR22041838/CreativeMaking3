const int buttonLedPin = 2;    // Pin connected to both the button and LED

void setup() {
  pinMode(buttonLedPin, INPUT_PULLUP);  // Set the pin as input with internal pull-up resistor
}

void loop() {
  int buttonState = digitalRead(buttonLedPin);  // Read the button state
  digitalWrite(buttonLedPin, LOW); // Turn off the LED initially
  
  if (buttonState == HIGH) {              // If the button is pressed (LOW state)
    digitalWrite(buttonLedPin, HIGH);    // Turn on the LED
    Serial.print(1);
    delay(100);
  
  } else {
    digitalWrite(buttonLedPin, LOW);     // Turn off the LED
    Serial.print(0);
    delay(100);
    
  }
}
