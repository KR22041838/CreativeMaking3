const int redButton = 5;      // Pin connected to the red button and LED
const int greenButton = 4;    // Pin connected to the green button and LED
const int blueButton = 3;     // Pin connected to the blue button and LED
const int yellowButton = 2;

const int redLED = 11;      // Pin connected to the red button and LED
const int greenLED = 10;    // Pin connected to the green button and LED
const int blueLED = 9;      // Pin connected to the blue button and LED
const int yellowLED = 8;

void setup() {
  Serial.begin(9600);

  pinMode(redButton, INPUT_PULLUP);
  pinMode(greenButton, INPUT_PULLUP);
  pinMode(blueButton, INPUT_PULLUP);
  pinMode(yellowButton, INPUT_PULLUP);

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    int data = Serial.read();

    // Read the button states inside the if block
    int buttonStateRed = digitalRead(redButton);
    int buttonStateGreen = digitalRead(greenButton);
    int buttonStateBlue = digitalRead(blueButton);
    int buttonStateYellow = digitalRead(yellowButton);

    switch (data) {
      case '0':
        digitalWrite(redLED, HIGH);
        digitalWrite(greenLED, LOW);
        digitalWrite(blueLED, LOW);
        digitalWrite(yellowLED, LOW);
        
   Serial.read();

        if (buttonStateRed == HIGH) {
          Serial.write('0');
          Serial.flush();
        }
        if (buttonStateBlue == HIGH || buttonStateYellow == HIGH || buttonStateGreen == HIGH) {
          Serial.write('5');
        }

        break;

      case '1':
        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, HIGH);
        digitalWrite(blueLED, LOW);
        digitalWrite(yellowLED, LOW);
Serial.read();
        if (buttonStateGreen == HIGH) {
          Serial.write('1');
          Serial.flush();
        }
        if (buttonStateRed == HIGH || buttonStateYellow == HIGH || buttonStateBlue == HIGH) {
          Serial.write('5');
        }
        break;

      case '2':
        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, LOW);
        digitalWrite(blueLED, HIGH);
        digitalWrite(yellowLED, LOW);
 Serial.read();
        if (buttonStateBlue == HIGH) {
          Serial.write('2');
          Serial.flush();
        }
        if (buttonStateRed == HIGH || buttonStateYellow == HIGH || buttonStateGreen == HIGH) {
          Serial.write('5');
        }
        break;

      case '3':
        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, LOW);
        digitalWrite(blueLED, LOW);
        digitalWrite(yellowLED, HIGH);
Serial.read();
        if (buttonStateYellow == HIGH) {
          Serial.write('3');
          Serial.flush();
        }
        if (buttonStateRed == HIGH || buttonStateBlue == HIGH || buttonStateGreen == HIGH) {
          Serial.write('5');
        }
        break;

      default:
        // If an unrecognized data is received, turn off all LEDs
        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, LOW);
        digitalWrite(blueLED, LOW);
        digitalWrite(yellowLED, LOW);
        break;
    }
  }
}
