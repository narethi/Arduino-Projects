int latchPin = 6;
int clockPin = 5;
int dataPin = 4;
int resetPin = 7;

byte output = 0xFF;

int NUMBER_OF_LINES = 8;
byte lines[] = {0x01, //Bottom Left
                0x02, //Bottom
                0x04, //Bottom Right
                0x08, //DOT
                0x10, //Top Right
                0x20, //Top
                0x40, //Top Left
                0x80}; //Center


int NUMBER_OF_CHARACTERS = 8;
byte characters[] = {0x01 | 0x04 | 0x10 | 0x20 | 0x40 | 0x80, //A
                     0x01 | 0x02 | 0x04 | 0x40 | 0x80 , //b
                     0x01 | 0x02 | 0x80, //c
                     0x01 | 0x02 | 0x04 | 0x10 | 0x80, //d
                     0x01 | 0x02 | 0x20 | 0x40 | 0x80, //E
                     0x01 | 0x20 | 0x40 | 0x80, //F
                     0x02 | 0x04 | 0x10 | 0x20 | 0x40 | 0x80, //g
                     0x01 | 0x04 | 0x10 | 0x40 | 0x80, //H
                     };

int NUMBER_OF_NUMBERS = 10;
byte numbers[] = { 0x01 | 0x02 | 0x04 | 0x10 | 0x20 | 0x40,
                   0x04 | 0x10,
                   0x01 | 0x02 | 0x10 | 0x20 | 0x80,
                   0x02 | 0x04 | 0x10 | 0x20 | 0x80,
                   0x04 | 0x10 | 0x40 | 0x80,
                   0x02 | 0x04 | 0x20 | 0x40 | 0x80 ,
                   0x01 | 0x02 | 0x04 | 0x40 | 0x80,
                   0x04 | 0x10 | 0x20 | 0x40,
                   0x01 | 0x02 | 0x04 | 0x10 | 0x20 | 0x40 | 0x80,
                   0x02 | 0x04 | 0x10 | 0x20 | 0x40 | 0x80,
                   };

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(resetPin, OUTPUT);
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

void SingleSetShift(bool on)
{
  digitalWrite(clockPin, LOW);
  digitalWrite(latchPin, LOW);
  digitalWrite(dataPin, on ? HIGH : LOW);
  digitalWrite(latchPin, HIGH);
  digitalWrite(dataPin, LOW);
  digitalWrite(clockPin, HIGH);
}

void loop() 
{
  for(int i= 0; i< 8; i++)
  {
     WriteByteToShiftRegister(0xFF);
  }
delay(1000);
  for(int i= 0; i< 8; i++)
  {
     WriteByteToShiftRegister(0x00);
  }
delay(1000);
  for(int i = 0; i < NUMBER_OF_CHARACTERS; i++)
  {
    WriteByteToShiftRegister(characters[i]);
    delay(100);
  }

  for(int i = 0; i < NUMBER_OF_NUMBERS; i++)
  {
    WriteByteToShiftRegister(numbers[i]);
    delay(100);
  }
  
  for(int i = 0; i < NUMBER_OF_LINES; i++)
  {
    WriteByteToShiftRegister(lines[i]);
    delay(100);
  }
/*

  WriteByteToShiftRegister(0x00);
  delay(250);*/
}
