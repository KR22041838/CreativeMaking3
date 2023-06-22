const int redButton = 5;      // Pin connected to the red button and LED
const int greenButton = 4;    // Pin connected to the green button and LED
const int blueButton = 3;     // Pin connected to the blue button and LED
const int yellowButton = 2;

const int redLED = 11;      // Pin connected to the red button and LED
const int greenLED = 10;    // Pin connected to the green button and LED
const int blueLED = 9;      // Pin connected to the blue button and LED
const int yellowLED = 8;

bool ledTurnedOn = false;

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
  if (!ledTurnedOn && Serial.available() > 0) {
    int data = Serial.read();

    switch (data) {
      case '0':
        digitalWrite(redLED, HIGH);
        digitalWrite(greenLED, LOW);
        digitalWrite(blueLED, LOW);
        digitalWrite(yellowLED, LOW);
        
        ledTurnedOn = true;  // Set the flag to indicate LED is turned on
        
        delay(1000);
        break;

      case '1':
        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, HIGH);
        digitalWrite(blueLED, LOW);
        digitalWrite(yellowLED, LOW);
        
        ledTurnedOn = true;  // Set the flag to indicate LED is turned on
        break;

      case '2':
        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, LOW);
        digitalWrite(blueLED, HIGH);
        digitalWrite(yellowLED, LOW);
        
        ledTurnedOn = true;  // Set the flag to indicate LED is turned on
        delay(1000);
        break;

      case '3':
        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, LOW);
        digitalWrite(blueLED, LOW);
        digitalWrite(yellowLED, HIGH);
        
        ledTurnedOn = true;  // Set the flag to indicate LED is turned on
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

  if (ledTurnedOn) {
    // Check button states
    int buttonStateRed = digitalRead(redButton);
    int buttonStateGreen = digitalRead(greenButton);
    int buttonStateBlue = digitalRead(blueButton);
    int buttonStateYellow = digitalRead(yellowButton);

    if (buttonStateRed == HIGH) {
      Serial.write('0');
      Serial.flush();
    }
    if (buttonStateBlue == HIGH)  {
      Serial.write('2');
      Serial.flush();
    }
    if (buttonStateGreen == HIGH)  {
      Serial.write('1');
      Serial.flush();
    }
     if (buttonStateYellow == HIGH)  {
      Serial.write('3');
      Serial.flush();
    }
  }
}
