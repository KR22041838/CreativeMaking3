const int redButton = 5;
const int greenButton = 4;
const int blueButton = 3;
const int yellowButton = 2;

const int redLED = 11;
const int greenLED = 10;
const int blueLED = 9;
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
 int buttonStateRed = digitalRead(redButton);
  int buttonStateGreen = digitalRead(greenButton);
  int buttonStateBlue = digitalRead(blueButton);
  int buttonStateYellow = digitalRead(yellowButton);

    if (Serial.available() == 0) {
      digitalWrite(redLED, HIGH);
      digitalWrite(greenLED, LOW);
      digitalWrite(blueLED, LOW);
      digitalWrite(yellowLED, LOW);
       int buttonStateRed = digitalRead(redButton);
    }
     
else if (redLED == HIGH && buttonStateRed == HIGH) {
        Serial.write('0');
}
    
    else if (Serial.available() == 1) {
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, HIGH);
      digitalWrite(blueLED, LOW);
      digitalWrite(yellowLED, LOW);

      int buttonStateGreen = digitalRead(greenButton);
      if (buttonStateGreen == HIGH) {
        Serial.write('1');
      }
    }
    else if (Serial.available() == 2) {
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, LOW);
      digitalWrite(blueLED, HIGH);
      digitalWrite(yellowLED, LOW);

      int buttonStateBlue = digitalRead(blueButton);
      if (buttonStateBlue == HIGH) {
        Serial.write('2');
      }
    }
    else if (Serial.available() == 3) {
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, LOW);
      digitalWrite(blueLED, LOW);
      digitalWrite(yellowLED, HIGH);

      int buttonStateYellow = digitalRead(yellowButton);
      if (buttonStateYellow == HIGH) {
        Serial.write('3');
      }
    }

    delay(200); // Adjust the delay as per your requirement
  }  }
