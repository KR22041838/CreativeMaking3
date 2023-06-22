const int redButton = 13;      // Pin connected to the red button and LED
const int greenButton = 10;    // Pin connected to the green button and LED
const int blueButton = 8;      // Pin connected to the blue button and LED
const int yellowButton = 2;    // Pin connected to the yellow button and LED

void setup() {
  Serial.begin(9600);
  pinMode(redButton, INPUT_PULLUP);    // Set the pin as input with internal pull-up resistor
  pinMode(greenButton, INPUT_PULLUP);  // Set the pin as input with internal pull-up resistor
  pinMode(blueButton, INPUT_PULLUP);   // Set the pin as input with internal pull-up resistor
  pinMode(yellowButton, INPUT_PULLUP); // Set the pin as input with internal pull-up resistor
}

void loop() {
  // Read the button states
  int buttonStateRed = digitalRead(redButton);
  int buttonStateGreen = digitalRead(greenButton);
  int buttonStateBlue = digitalRead(blueButton);
  int buttonStateYellow = digitalRead(yellowButton);

  if (buttonStateRed == HIGH) {
    digitalWrite(redButton, HIGH);      // Turn on the red LED
    digitalWrite(greenButton, LOW);
    digitalWrite(blueButton, LOW);
    digitalWrite(yellowButton, LOW);

    // Serial Communication
    Serial.write((byte)1); // Cast the integer value to byte
    Serial.flush();
    delay(500);
  }
  else if (buttonStateGreen == HIGH) {
    digitalWrite(redButton, LOW);
    digitalWrite(greenButton, HIGH);    // Turn on the green LED
    digitalWrite(blueButton, LOW);
    digitalWrite(yellowButton, LOW);

    // Serial Communication
    Serial.write((byte)2); // Cast the integer value to byte
    Serial.flush();
    delay(500);
  }
  else if (buttonStateBlue == HIGH) {
    digitalWrite(redButton, LOW);
    digitalWrite(greenButton, LOW);
    digitalWrite(blueButton, HIGH);     // Turn on the blue LED
    digitalWrite(yellowButton, LOW);

    // Serial Communication
    Serial.write((byte)3); // Cast the integer value to byte
    Serial.flush();
    delay(500);
  }
  else if (buttonStateYellow == HIGH) {
    digitalWrite(redButton, LOW);
    digitalWrite(greenButton, LOW);
    digitalWrite(blueButton, LOW);
    digitalWrite(yellowButton, HIGH);   // Turn on the yellow LED

    // Serial Communication
    Serial.write((byte)4); // Cast the integer value to byte
    Serial.flush();
    delay(500);
  }
  else {
    digitalWrite(redButton, LOW);
    digitalWrite(greenButton, LOW);
    digitalWrite(blueButton, LOW);
    digitalWrite(yellowButton, LOW);    // Turn off all LEDs
    
    // Serial Communication
   // Serial.write((byte)0); // Cast the integer value to byte
    //Serial.flush();
    //delay(500);
  }
}
