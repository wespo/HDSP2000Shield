/*
  Display HDSP2000
  Destroyed one when connected upside down!
  managed to make light from one at 2010.04.24
 
 */
#include "HDSP2000Shield.h"
//text buffers
char * txtString = (char*) malloc(256 * sizeof(char)); //255 character long word!
int txtLen;
int startOffset = 0;
void setup()   {
  Serial.begin(9600);
  txtString = "FOUR SCORE AND SEVEN YEARS AGO OUR FATHERS BROUGHT FORTH ON THIS CONTINENT A NEW NATION, CONCEIVED IN LIBERTY, AND DEDICATED TO THE PROPOSITION THAT ALL MEN ARE CREATED EQUAL.";
  txtLen = 176;
  HDSP2000.begin();
}

void loop()                    
{
  //wizzer
  if(startOffset > (txtLen - 4*dispCount - 1))
  {
    startOffset = 0;
  }
  for(int i = 0; i <= (dispCount*4); i++)
  {
    HDSP2000.txtBuffer[i] = txtString[startOffset + i];
  }
  
  startOffset++;
  
  if((startOffset > (txtLen - 4*dispCount - 1)) || (startOffset == 1))
  {
    delay(1000);
  }
  else
  {
    delay(100);
  }     
}


