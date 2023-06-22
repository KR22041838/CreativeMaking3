const int ledPin0 = 2;
const int ledPin1 = 3;
const int ledPin2 = 4;
const int ledPin3 = 5;

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
  if (Serial.available() > 0) {
    int data = Serial.read();
    switch (data) {
      case '0':
        digitalWrite(redButton, HIGH);
        digitalWrite(greenButton, LOW);
        digitalWrite(blueButton, LOW);
        digitalWrite(yellowButton, LOW);
        break;
      case '1':
        digitalWrite(redButton, LOW);
        digitalWrite(greenButton, HIGH);
        digitalWrite(blueButton, LOW);
        digitalWrite(yellowButton, LOW);;
        break;
      case '2':
        digitalWrite(redButton, LOW);
        digitalWrite(greenButton, LOW);
        digitalWrite(blueButton, HIGH);
        digitalWrite(yellowButton, LOW);
        break;
      case '3':
        digitalWrite(redButton, LOW);
        digitalWrite(greenButton, LOW);
        digitalWrite(blueButton, LOW);
        digitalWrite(yellowButton, HIGH);
        break;
      default:
        // If an unrecognized data is received, turn off all LEDs
        digitalWrite(ledPin0, LOW);
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, LOW);
        digitalWrite(ledPin3, LOW);
        break;
    }
  }
}
