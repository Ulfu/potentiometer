/*
  This example code is in the public domain.
*/

// constants won't change. They're used here to
// set pin numbers:
int ledPins[8]; //= {4,5,6,7,8,9,10,11};      // the number of the LED pin
const int potentiometerPin = 0;      // the number of the potentiometer pin

int ledsState[8] = {0,0,0,0,0,0,0,0}; //Current LEDs that are HIGH
int potentiometerRead;
int ledPointer = 0;

void setup() {
  for (int i = 0; i < 8; i++) {
    //Assign number of pins
    ledPins[i] = i + 4;
    //Set all led states to LOW
    ledsState[i] = false;
    // initialize the LED pins as an outputs:
    pinMode(ledPins[i], OUTPUT);
  }
  // initialize the button pins as an input pullup:
  pinMode(potentiometerPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  potentiometerRead = analogRead(potentiometerPin);
  ledPointer = map(potentiometerRead, 0, 1023, 0, 8);

  for (int i = 0;  i < 8; i++) {

    Serial.println(ledsState[i]); //Prints led state
    if (i < ledPointer) {
      ledsState[i] = true;
    }
    else {
      ledsState[i] = false;
    }
    digitalWrite(ledPins[i], ledsState[i]);
  }
}
