volatile byte aFlag = 0;
volatile byte bFlag = 0; 
volatile int encoderPos = 0; 
volatile int oldEncPos = 0; 
volatile byte reading = 0; 
volatile byte currentPos = 0;

void PinA()
{
  cli();
  reading = PIND & 0xC; 
  if(reading == B00001100 && aFlag)
  { 
    encoderPos = (encoderPos - 15 < 15) ? 15 : encoderPos - 15; 
    bFlag = 0; 
    aFlag = 0; 
  }
  else if (reading == B00000100) bFlag = 1; 
  sei();
}

void PinB()
{
  cli();
  reading = PIND & 0xC;
  if (reading == B00001100 && bFlag) 
  {
    encoderPos = (encoderPos + 15 > 255) ? 255 : encoderPos + 15; 
    bFlag = 0;
    aFlag = 0;
  }
  else if (reading == B00001000) aFlag = 1;
  sei();
}

int Encoder(bool dir)
{ //1 to output direction. 0 to output position
  static int state = 15;
  if(dir == 1)
  {
    if(encoderPos > oldEncPos) 
    {
      state = 1;
    }else if (encoderPos < oldEncPos)
    {
      state = 0;
    }
  }else
  {
    if(encoderPos != oldEncPos)
    {
      state = encoderPos;
    }
  }
  oldEncPos = encoderPos;
  return(state);
}
