/*
  Display HDSP2000
  Destroyed one when connected upside down!
  managed to make light from one at 2010.04.24
 
 */
#include "HDSP2000Shield.h"

void setup()   {
  char text[13] = "Hello World!"; //some text
  for(int i = 0; i < 13; i++)
  {
    HDSP2000.txtBuffer[i] = text[i];
  }
  HDSP2000.begin();
}

void loop()                    
{
}


