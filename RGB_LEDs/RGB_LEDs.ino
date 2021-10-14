#include "RGBLED.h"

const int redPin = 3;
const int greenPin = 4;
const int bluePin = 5;

RGBLED *LED;

void setup() 
{
  LED = new RGBLED(redPin, greenPin, bluePin);
  LED->SetColour(255, 0, 255);
  Serial.begin(9600);
  // set the digital pin as output:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

int currentMode = 2;

void loop() 
{
  if(currentMode == 0)
  {
    LED->TurnOnChannels();
  }
  else if(currentMode == 1)
  {
     LED->Breathe(3000);
  }
  else if(currentMode == 2)
  {
    LED->SetColour(255, 0, 0);
    LED->Breathe(3000);
    LED->SetColour(0, 255, 0);
    LED->Breathe(3000);
    LED->SetColour(0, 0, 255);
    LED->Breathe(3000);
    LED->SetColour(255, 255, 0);
    LED->Breathe(3000);
    LED->SetColour(255, 0, 255);
    LED->Breathe(3000);
    LED->SetColour(0, 255, 255);
    LED->Breathe(3000);
    LED->SetColour(255, 255, 255);
    LED->Breathe(3000);
  }
}
