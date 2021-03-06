#include "Encoder.h"

const int redPin = 9;
const int greenPin = 6;
const int bluePin = 10;
const int whitePin = 11;
const int Button = 7;
int counter = 0;
int state = 0;
static unsigned char pinA = 2;
static unsigned char pinB = 3;

void setup() {
  pinMode(pinA, INPUT_PULLUP);
  pinMode(pinB, INPUT_PULLUP);
  pinMode(Button, INPUT_PULLUP);

  attachInterrupt(0, PinA, RISING);
  attachInterrupt(1, PinB, RISING);
  setColourRgb(0,0,0);

  Serial.begin(115200);
}

void loop() {
  unsigned int rgbColour[3];

  rgbColour[0] = 255;
  rgbColour[1] = 0;
  rgbColour[2] = 0;

  if(counter < 10 & (digitalRead(Button)==LOW))
  {
    counter++;
    delay(500);
  }else if (counter >= 10)
  {
    counter = 0;
  }

  Serial.println(counter);

  switch (counter){
    case 0:
      analogWrite(whitePin, Encoder(0));
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
      break;
    case 1:
      digitalWrite(whitePin, LOW);
      analogWrite(redPin, Encoder(0));
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
      break;
    case 2:
      digitalWrite(whitePin, LOW);
      digitalWrite(redPin, LOW);
      analogWrite(greenPin, Encoder(0));
      digitalWrite(bluePin, LOW);
      break;
    case 3:
      digitalWrite(whitePin, LOW);
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      analogWrite(bluePin, Encoder(0));
      break;
    case 4:
      digitalWrite(whitePin, LOW);
      analogWrite(redPin, Encoder(0));
      analogWrite(greenPin, Encoder(0));
      digitalWrite(bluePin, LOW);
      break;
    case 5:
      digitalWrite(whitePin, LOW);
      digitalWrite(redPin, LOW);
      analogWrite(greenPin, Encoder(0));
      analogWrite(bluePin, Encoder(0));
      break;
    case 6:
      analogWrite(whitePin, LOW);
      analogWrite(redPin, Encoder(0));
      digitalWrite(greenPin, LOW);
      analogWrite(bluePin, Encoder(0));
      break;
    case 7:
     break;
    case 8:
      break;
    case 9:
      break;
    case 10:
      for (int decColour = 0; decColour < 3; decColour += 1) {
          int incColour = decColour == 2 ? 0 : decColour + 1;

        for(int i = 0; i < 255; i += 1) {
          rgbColour[decColour] -= 1;
          rgbColour[incColour] += 1;
      
          setColourRgb(rgbColour[0], rgbColour[1], rgbColour[2]);
          delay(5);
          }
        }
      break;
  }
}

void setColourRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
 }
