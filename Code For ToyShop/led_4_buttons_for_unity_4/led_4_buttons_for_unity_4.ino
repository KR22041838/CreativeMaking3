
const int redButton = 13;      // Pin connected to the red button and LED
const int greenButton = 10;    // Pin connected to the green button and LED
const int blueButton = 8;      // Pin connected to the blue button and LED
const int yellowButton = 2;

void setup() {
  Serial.begin(9600);

  pinMode(redButton, OUTPUT);
  pinMode(greenButton, OUTPUT);
  pinMode(blueButton, OUTPUT);
  pinMode(yellowButton, OUTPUT);

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
          Serial.write((byte)0); // Cast the integer value to byte

        }
        if (buttonStateBlue == HIGH || buttonStateYellow == HIGH || buttonStateGreen == HIGH) {
          Serial.write((byte)5); // Cast the integer value to byte

        }

        break;

      case '1':
        digitalWrite(redButton, LOW);
        digitalWrite(greenButton, HIGH);
        digitalWrite(blueButton, LOW);
        digitalWrite(yellowButton, LOW);;

        if (buttonStateGreen == LOW) {
          Serial.write((byte)1); // Cast the integer value to byte

        }
        if (buttonStateRed == HIGH || buttonStateYellow == HIGH || buttonStateBlue == HIGH) {
          Serial.write((byte)5); // Cast the integer value to byte

        }
        break;

  case '2':
    digitalWrite(redButton, LOW);
    digitalWrite(greenButton, LOW);
    digitalWrite(blueButton, HIGH);
    digitalWrite(yellowButton, LOW);

    if (buttonStateBlue == LOW) {
      Serial.write((byte)2); // Cast the integer value to byte

    }
    if (buttonStateRed == HIGH || buttonStateYellow == HIGH || buttonStateGreen == HIGH) {
      Serial.write((byte)5); // Cast the integer value to byte

        }
    break;


  case '3':
    digitalWrite(redButton, LOW);
    digitalWrite(greenButton, LOW);
    digitalWrite(blueButton, LOW);
    digitalWrite(yellowButton, HIGH);

    if (buttonStateYellow == LOW) {
      Serial.write((byte)3); // Cast the integer value to byte

    }
      if (buttonStateRed == HIGH || buttonStateRed== HIGH || buttonStateBlue == HIGH) {
          Serial.write((byte)5); // Cast the integer value to byte

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
