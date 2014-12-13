/* HDSP2000 LED Library 
   W. Esposito.
   July 2013
   
*/

#include "HDSP2000Shield.h"
#include <Arduino.h>
#include "matrixTable.h"
#include "digitalWriteFast.h" //the inbuilt arduino digitalWrite functionality is dog slow. This is faster. Replace "digitalWrite with digitalWrite in this file for maximum compatiblity"

HDSP2000Shield HDSP2000;

HDSP2000Shield::HDSP2000Shield()
{  
  for(int i = 0; i <= (dispCount*4); i++) //Initially Fill Buffer.
  {
    txtBuffer[i] = ' ';
  }
}
void HDSP2000Shield::begin(int refreshRate)
{
  //{COL1, COL2, COL3, COL4, COL5}
  bus[0] = COL1;
  bus[1] = COL2;
  bus[2] = COL3;
  bus[3] = COL4;
  bus[4] = COL5;
  curCol = 0;


  for(int i = 0; i < 5; i++)
  {
    pinMode(bus[i], OUTPUT); //bus as output
  }
 
  pinMode(DIN, OUTPUT); // DataIn Displayz
  pinMode(CLK, OUTPUT); // Clock
  pinMode(VB, OUTPUT);  // VB

  TCCR1A = 0;                 // clear control register A 
  TCCR1B = _BV(WGM13);        // set mode 8: phase and frequency correct pwm, stop the timer
  if(refreshRate > 0)
  {
	setPeriod(refreshRate);	
  }
  else
  {
	setPeriod(3000);	
  }
  TIMSK1 = _BV(TOIE1);                                     // sets the timer overflow interrupt enable bit
}

void HDSP2000Shield::setPeriod(long microseconds)
{
	  
  long cycles = (F_CPU / 2000000) * microseconds;                                // the counter runs backwards after TOP, interrupt is at BOTTOM so divide microseconds by 2
  if(cycles < RESOLUTION)              clockSelectBits = _BV(CS10);              // no prescale, full xtal
  else if((cycles >>= 3) < RESOLUTION) clockSelectBits = _BV(CS11);              // prescale by /8
  else if((cycles >>= 3) < RESOLUTION) clockSelectBits = _BV(CS11) | _BV(CS10);  // prescale by /64
  else if((cycles >>= 2) < RESOLUTION) clockSelectBits = _BV(CS12);              // prescale by /256
  else if((cycles >>= 2) < RESOLUTION) clockSelectBits = _BV(CS12) | _BV(CS10);  // prescale by /1024
  else        cycles = RESOLUTION - 1, clockSelectBits = _BV(CS12) | _BV(CS10);  // request was out of bounds, set as maximum
  
  oldSREG = SREG;				
  cli();							// Disable interrupts for 16 bit register access
  ICR1 = pwmPeriod = cycles;                                          // ICR1 is TOP in p & f correct pwm mode
  SREG = oldSREG;
  
  TCCR1B &= ~(_BV(CS10) | _BV(CS11) | _BV(CS12));
  TCCR1B |= clockSelectBits;                                          // reset clock select register, and starts the clock
  sei();
}

void HDSP2000Shield::end()
{
	TIMSK1 &= ~_BV(TOIE1);                                   // clears the timer overflow interrupt enable bit 
}

void HDSP2000Shield::driveDisplay()
{
   if(curCol > 4)
   {
     curCol = 0;
   }
   digitalWriteFast(VB,LOW);       // Blank
   long currentColData = 0;    // buffer for column data

   if(curCol == 0) //last column branch
   {
      digitalWriteFast(COL5,LOW);     // off previous column
   }
   else
   {
      digitalWriteFast(bus[curCol-1],LOW); // off previous column
   }

   for(int i = dispCount; i>0; i--) //Build and transmit the column word for each display, in order.
   {
     currentColData = buildCol(txtBuffer, i-1, curCol);
     shiftlong(currentColData);
   }
  digitalWriteFast(bus[curCol],HIGH);  // on selected column
  digitalWriteFast(VB,HIGH);      // column on
  curCol++; //next column
}

void HDSP2000Shield::shiftlong(long val) {
  //digitalWrite(CLK, LOW);
  for (int i = 0; i < 28; i++)  {
          digitalWriteFast(DIN, !!(val & (1L << i)));
          digitalWriteFast(CLK, HIGH);
          delayMicroseconds(1);
          digitalWriteFast(CLK, LOW);          
  }
}

long HDSP2000Shield::buildCol(char* string, int disp, int col)
{
  long returnWord = 0;
  for(int i = 0; i < 4; i++) //outer loop iterates over characters
  {
    for(int row = 0; row < 7; row++) //inner loop iterates within rows of a single character
    {
      int index = string[i+4*disp] - 0x20; //
      char bitShift = char_data[index][row];
      bitShift >>= col;
      bitShift &= 0x01;
      returnWord <<= 1;
      returnWord |= bitShift; 
    }
  }
  return returnWord;
}

ISR(TIMER1_OVF_vect)          // interrupt service routine that wraps a user defined function supplied by attachInterrupt
{
  HDSP2000.driveDisplay();
}