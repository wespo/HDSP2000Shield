/* 
 HDSP 2000 Shield RTC Example. Reuquires Time Library
 Get at github.com/wespo/Time
 also note that the board was modified to use pin 2 instead of A4.
 Change #define COL1 A4 on line 19 of HDSP200Shield.h to
 #define COL1 2
 */ 
 
#include <Time.h>  
#include <Wire.h>
#include "HDSP2000Shield.h"
#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t

#define TIME_MSG_LEN  11   // time sync to PC is HEADER followed by unix time_t as ten ascii digits
#define TIME_HEADER  'T'   // Header tag for serial time sync message
#define TIME_REQUEST  7    // ASCII bell character requests a time sync message 

void setup()  {
  Serial.begin(9600);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  setSyncInterval(10); //resynch with RTC every 5 seconds.
  setSyncProvider(RTC.get);  //set function to call when sync required
  Serial.println("Waiting for sync message");
  char text[13] = "Hello World!"; //some text
  for(int i = 0; i < 13; i++)
  {
    HDSP2000.txtBuffer[i] = text[i];
  }
  HDSP2000.begin(5000);
}

void loop(){    
  if(Serial.available() ) 
  {
    processSyncMessage();
  }
  if(timeStatus()!= timeNotSet)   
  {
    digitalWrite(13,timeStatus() == timeSet); // on if synced, off if needs refresh  
    digitalClockDisplay();  
  }
  if(!digitalRead(4))
  {
    setTime(((now()+60)/60)*60);
    delay(100);
    RTC.set(now());
  }
  if(!digitalRead(5))
  {
    setTime(((now()+3600)/60)*60);
    delay(100);
    RTC.set(now());
  }
  delay(10);
  
}

void digitalClockDisplay(){
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print(" ");
  Serial.print(day());
  Serial.print(" ");
  Serial.print(month());
  Serial.print(" ");
  Serial.print(year()); 
  Serial.println(); 
  writeTime();
}

void printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

void processSyncMessage() {
  // if time sync available from serial port, update time and return true
  while(Serial.available() >=  TIME_MSG_LEN ){  // time message consists of a header and ten ascii digits
    char c = Serial.read() ; 
    Serial.print(c);  
    if( c == TIME_HEADER ) {       
      time_t pctime = 0;
      for(int i=0; i < TIME_MSG_LEN -1; i++){   
        c = Serial.read();          
        if( c >= '0' && c <= '9'){   
          pctime = (10 * pctime) + (c - '0') ; // convert digits to a number    
        }
      }   
      setTime(pctime);   // Sync Arduino clock to the time received on the serial port
      RTC.set(pctime);
    }  
  }
}

time_t requestSync()
{
  Serial.write(TIME_REQUEST);  
  return 0; // the time will be sent later in response to serial mesg
}
void writeTime() //put the time to the display.
{
      int hourNow = hour();
      if(hourNow > 12)
      {
        hourNow = hourNow - 12;
      }
      if(hourNow == 0)
      {
        hourNow = 12; 
      }
      HDSP2000.txtBuffer[0] = ' ';
      HDSP2000.txtBuffer[1] = hourNow/10 + 0x30; //0 ascii offset
      HDSP2000.txtBuffer[2] = hourNow%10 + 0x30; //0 ascii offset
      HDSP2000.txtBuffer[3] = ':';
      HDSP2000.txtBuffer[4] = minute()/10 + 0x30; //0 ascii offset
      HDSP2000.txtBuffer[5] = minute()%10 + 0x30; //0 ascii offset
      HDSP2000.txtBuffer[6] = ':';
      HDSP2000.txtBuffer[7] = second()/10 + 0x30; //0 ascii offset
      HDSP2000.txtBuffer[8] = second()%10 + 0x30; //0 ascii offset
     
      if(hour()>12)
      {
              HDSP2000.txtBuffer[9] = 'P';
      }
      else
      {
              HDSP2000.txtBuffer[9] = 'A';        
      }
      HDSP2000.txtBuffer[10] = 'M';
      HDSP2000.txtBuffer[11] = ' ';
}
