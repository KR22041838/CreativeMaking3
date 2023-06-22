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
  // Read the button states
  int buttonStateRed = digitalRead(redButton);
  int buttonStateGreen = digitalRead(greenButton);
  int buttonStateBlue = digitalRead(blueButton);
  int buttonStateYellow = digitalRead(yellowButton);

  if (Serial.available() > 0) {
    byte receivedByte = Serial.read();
    if (receivedByte == '1') {
      digitalWrite(redLED, HIGH);
      digitalWrite(greenLED, LOW);
      digitalWrite(blueLED, LOW);
      digitalWrite(yellowLED, LOW);
    }
    else if (receivedByte == '2') {
      digitalWrite(blueLED, LOW);
      digitalWrite(greenLED, HIGH);
      digitalWrite(blueLED, LOW);
      digitalWrite(yellowLED, LOW);
    }
    else if (receivedByte == '3') {
      digitalWrite(yellowLED, LOW);
      digitalWrite(greenLED, LOW);
      digitalWrite(blueLED, HIGH);
      digitalWrite(yellowLED, LOW);
    }
    else if (receivedByte == '4') {
      digitalWrite(greenLED, LOW);
      digitalWrite(greenLED, LOW);
      digitalWrite(blueLED, LOW);
      digitalWrite(yellowLED, HIGH);
    }
    else 
      digitalWrite(greenLED, LOW);
      digitalWrite(greenLED, LOW);
      digitalWrite(blueLED, LOW);
      digitalWrite(yellowLED, LOW);
  }

  if (buttonStateRed == HIGH) {
    Serial.write('1');
  }
  else if (buttonStateGreen == HIGH) {
    Serial.write('2');
  }
  else if (buttonStateBlue == HIGH) {
    Serial.write('3');
  }
  else if (buttonStateYellow == HIGH) {
    Serial.write('4');
  }

  Serial.flush();

  delay(200); // Adjust the delay as per your requirement
}
