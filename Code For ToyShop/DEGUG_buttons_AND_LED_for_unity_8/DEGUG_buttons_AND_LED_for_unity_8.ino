const int redButton = 5;      // Pin connected to the red button and LED
const int greenButton = 4;    // Pin connected to the green button and LED
const int blueButton = 3;     // Pin connected to the blue button and LED
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

  if (buttonStateRed == HIGH) {
    Serial.write('0');
    
  }
  else if (buttonStateGreen == HIGH) {
    Serial.write('1');
  }
  else if (buttonStateBlue == HIGH) {
    Serial.write('2');
  }
  else if (buttonStateYellow == HIGH) {
    Serial.write('3');
  }
  else {

  }

  Serial.flush();

  delay(200); // Adjust the delay as per your requirement
}
