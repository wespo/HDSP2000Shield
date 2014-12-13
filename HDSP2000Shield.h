/* HDSP2000 LED Library 
   W. Esposito.
   July 2013
   
*/


#ifndef _HDSP2000_
#define _HDSP2000_

#include <avr/io.h>
#include <avr/interrupt.h>

#define RESOLUTION 65536    // Timer1 is 16 bit


//Pin Defines
#define dispCount 3
#define COL1 A4
#define COL2 A3
#define COL3 A2
#define COL4 A1
#define COL5 A0
#define VB 8
#define CLK 3
#define DIN 7

class HDSP2000Shield
{
	private:
		int bus[5]; //array of colunm pins
		long buildCol(char* string, int disp, int col);
		void shiftlong(long val);
		int curCol; //start at beginning.
		void setPeriod(long microseconds);
		unsigned int pwmPeriod;
		unsigned char clockSelectBits;
		char oldSREG;					// To hold Status Register while ints disabled
	public:
		HDSP2000Shield();
		void driveDisplay();
		void begin(int refreshRate = -1);
		void end();
		char txtBuffer[25];
};

extern HDSP2000Shield HDSP2000;

#endif