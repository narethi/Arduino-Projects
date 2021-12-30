int dataPin = 5;
int outputEnabledPin = 4;
int latchPin = 2;
int clockPin = 3;
int lightSensorPin = A0;

const int NUMBER_OF_WRITABLE_BYTES = 6;
byte DATA[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

enum class Color
{
  Red = 0,
  Green = 1,
  Blue = 2 
};

void SetDataToSingleValue(byte data)
{
  for(int i = 0; i < NUMBER_OF_WRITABLE_BYTES; i++)
  {
    DATA[i] = data;
  }
}

void WriteByteToShiftRegister(byte data)
{
  byte mask = 0x01;
  while(mask != 0)
  {
    SingleSetShift(mask & data); 
    mask <<= 1;
  }
}

void WriteBytesToShiftRegister(byte * data, int numberOfBytes)
{
  digitalWrite(outputEnabledPin, HIGH);
  for(int i = 0; i < numberOfBytes; i++)
  {
    WriteByteToShiftRegister(data[i]);
  }
  digitalWrite(outputEnabledPin, LOW);
}

void SingleSetShift(bool on)
{
  digitalWrite(clockPin, LOW);
  digitalWrite(latchPin, LOW);
  digitalWrite(dataPin, on ? HIGH : LOW);
  digitalWrite(latchPin, HIGH);
  digitalWrite(dataPin, LOW);
  digitalWrite(clockPin, HIGH);
  digitalWrite(latchPin, LOW);
}

void setup() 
{
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(outputEnabledPin, OUTPUT);
  pinMode(lightSensorPin, INPUT);

  SetDataToSingleValue(0x00);
  WriteBytesToShiftRegister(DATA, 6);

}

void DrawWave(byte * LEDs, int numberOfLEDs, int millisecondDelay = -1)
{
  SetDataToSingleValue(0x00);
  auto index = 0;
  auto remaining = 0;
  for(int i = 0; i < numberOfLEDs; i++)
  {
    index = (i*3/8);
    remaining = 8 - ((i*3)%8);
  
    if(remaining == 1)
    {
      //LED 5
      DATA[5 - index] |= (LEDs[i] >> 2);
      DATA[4 - index] |= ((LEDs[i] & 0x03) << 6);
    }
    else if(remaining == 2)
    {
      //LED 2
      DATA[5 - index] |= (LEDs[i] >> 1);
      DATA[4 - index] |= (LEDs[i] & 0x01) << 7;
    }
    else if(remaining == 3)
    {
      //LED 7
      DATA[5 - index] |= LEDs[i];
    }
    else if(remaining == 4)
    {
      //LED 4
      DATA[5 - index] |= (LEDs[i] << 1);
    }
    if(remaining == 5)
    {
      //LED 1
      DATA[5 - index] |= (LEDs[i] << 2);
    }
    else if(remaining == 6)
    {
      //LED 6
      DATA[5 - index] |= (LEDs[i] << 3);
      WriteBytesToShiftRegister(DATA, 6);
    }
    else if(remaining == 7)
    {
      //LED 3
      DATA[5 - index] |= (LEDs[i] << 4);
    }
    else if(remaining == 8)
    {
      //LED 0
      DATA[5 - index] |= (LEDs[i] << 5);
    }

    if(millisecondDelay > -1)
    {
      WriteBytesToShiftRegister(DATA, 6);
      delay(millisecondDelay);
    }
  }
}

void DrawAlternativeMaskArray(byte * masks, int numberOfMasks, int numberOfLEDs, int millisecondDelay = -1)
{
  byte * ledArray = new byte[numberOfLEDs];
  int currentMask = 0;
  for(int i = 0; i < numberOfLEDs; i++)
  {
    ledArray[i] = masks[currentMask];
    if(currentMask == numberOfMasks - 1)
    {
      currentMask = 0;
    }
    else
    {
      currentMask++;
    }
  }
  DrawWave(ledArray, 16, millisecondDelay);
  delete[] ledArray;
}

void DrawSimpleWave(byte mask, int millisecondDelay = -1)
{
  byte * ledArray = new byte[16];
  for(int i = 0; i< 16; i++)
  {
    ledArray[i] = mask;
  }
  DrawWave(ledArray, 16, millisecondDelay);
  delete[] ledArray;
}

void OutputSimpleWave(byte mask, int stepMillisecondDelay = -1, int completionMillisecondDelay = 300)
{
  DrawSimpleWave(mask, stepMillisecondDelay);
  WriteBytesToShiftRegister(DATA, 6);
  delay(completionMillisecondDelay);
}

void FlashLights()
{
    byte colorMask = 0x01;
  for(int i = 0; i < 30; i++)
  {
    if(colorMask > 4) colorMask = 0x01;
    DrawSimpleWave(colorMask);
    WriteBytesToShiftRegister(DATA, 6);
    delay(250);
    DrawSimpleWave(0x00);
    WriteBytesToShiftRegister(DATA, 6);
    delay(300);
    colorMask <<= 1;
  }
}

int demoStep = 0;

void DemoProgram()
{
  byte * masks;
  if(demoStep > 14)
  {
    masks = new byte[8];
    masks[0] = 0x01;
    masks[1] = 0x02;
    masks[2] = 0x03;
    masks[3] = 0x04;
    masks[4] = 0x05;
    masks[5] = 0x06;
    masks[6] = 0x07;
    masks[7] = 0x00;
  }

  switch(demoStep)
  {
    case 0:
      OutputSimpleWave(0x01);
      break;
    case 1:
      OutputSimpleWave(0x02);
      break;
    case 3:
      OutputSimpleWave(0x04);
      break;
    case 4:
      OutputSimpleWave(0x03);
      break;
    case 5:
      OutputSimpleWave(0x05);
      break;
    case 6:
      OutputSimpleWave(0x06);
      break;
   case 7:
      OutputSimpleWave(0x07);
      break;
   case 8:
      OutputSimpleWave(0x01, 100);
      break;
    case 9:
      OutputSimpleWave(0x02, 100);
      break;
    case 10:
      OutputSimpleWave(0x04, 100);
      break;
    case 11:
      OutputSimpleWave(0x03, 100);
      break;
    case 12:
      OutputSimpleWave(0x05, 100);
      break;
    case 13:
      OutputSimpleWave(0x06, 100);
      break;
    case 14:
      OutputSimpleWave(0x07, 100);
      break;
    case 15:
     DrawAlternativeMaskArray(masks, 8, 16, 250);
     delete[] masks;
     break;
    case 16:
      DrawAlternativeMaskArray(masks, 8, 16, 200);
      delete[] masks;
      break;
    case 17:
      DrawAlternativeMaskArray(masks, 8, 16, 150);
      delete[] masks;
      break;
    case 18:
      DrawAlternativeMaskArray(masks, 8, 16, 100);
      delete[] masks;
      break;
    case 19:
      DrawAlternativeMaskArray(masks, 8, 16, 50);
      delete[] masks;
      break;
    case 21:
      DrawAlternativeMaskArray(masks, 8, 16, 50);
      delete[] masks;
      break;
    case 22:
      DrawAlternativeMaskArray(masks, 8, 16, 50);
      delete[] masks;
      break;
    case 23:
      DrawAlternativeMaskArray(masks, 8, 16, 250);
      delete[] masks;
      break;
    case 24:
     FlashLights();
     break;
  }
  
  if(demoStep == 24)
  {
    demoStep = 0;
  }
  else
  {
     demoStep++;
  }
}



void loop() 
{ 
  if(analogRead(lightSensorPin) < 1)
  {
    DemoProgram();
  }
  else
  {
    OutputSimpleWave(0x00);
  }
  delay(10);
}
