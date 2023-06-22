const int redButton = 13;      // Pin connected to the red button and LED
const int greenButton = 10;    // Pin connected to the green button and LED
const int blueButton = 8;      // Pin connected to the blue button and LED
const int yellowButton = 2;

void setup() {
  Serial.begin(9600);

  pinMode(redButton, INPUT_PULLUP);
  pinMode(greenButton, INPUT_PULLUP);
  pinMode(blueButton, INPUT_PULLUP);
  pinMode(yellowButton, INPUT_PULLUP);
}

void loop() {
  // Read the button states
  int buttonStateRed = digitalRead(redButton);
  int buttonStateGreen = digitalRead(greenButton);
  int buttonStateBlue = digitalRead(blueButton);
  int buttonStateYellow = digitalRead(yellowButton);

  if (Serial.available() > 0) {
    int data = Serial.read();
    switch (data) {
      case '0':
        digitalWrite(redButton, HIGH);
        digitalWrite(greenButton, LOW);
        digitalWrite(blueButton, LOW);
        digitalWrite(yellowButton, LOW);

        if (buttonStateRed == LOW) {
          Serial.write('0');
        }
        if (buttonStateBlue == LOW || buttonStateYellow == LOW || buttonStateGreen == LOW) {
          Serial.write('5');
        }

        break;

      case '1':
        digitalWrite(redButton, LOW);
        digitalWrite(greenButton, HIGH);
        digitalWrite(blueButton, LOW);
        digitalWrite(yellowButton, LOW);

        if (buttonStateGreen == LOW) {
          Serial.write('1');
        }
        if (buttonStateRed == LOW || buttonStateYellow == LOW || buttonStateBlue == LOW) {
          Serial.write('5');
        }
        break;

      case '2':
        digitalWrite(redButton, LOW);
        digitalWrite(greenButton, LOW);
        digitalWrite(blueButton, HIGH);
        digitalWrite(yellowButton, LOW);

        if (buttonStateBlue == LOW) {
          Serial.write('2');
        }
        if (buttonStateRed == HIGH || buttonStateYellow == HIGH || buttonStateGreen == HIGH) {
          Serial.write('5');
        }
        break;

      case '3':
        digitalWrite(redButton, LOW);
        digitalWrite(greenButton, LOW);
        digitalWrite(blueButton, LOW);
        digitalWrite(yellowButton, HIGH);

        if (buttonStateYellow == LOW) {
          Serial.write('3');
        }
        if (buttonStateRed == LOW || buttonStateBlue == LOW || buttonStateGreen == LOW) {
          Serial.write('5');
        }
        break;

      default:
        // If an unrecognized data is received, turn off all LEDs
        digitalWrite(redButton, LOW);
        digitalWrite(greenButton, LOW);
        digitalWrite(blueButton, LOW);
        digitalWrite(yellowButton, LOW);
        break;
    }
  }
}
