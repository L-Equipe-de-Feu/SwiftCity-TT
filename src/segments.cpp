#include <Arduino.h>
#include "segments.h"

//==========BEGIN SR Functions==========
void initializeSRData()
{
  //Display Scanner (Iterates through each display module)
  digitalWrite(LATCH,LOW);      //Tells all SRs that uController is sending data

  for(int dispID = 0; dispID < maxDisplays; dispID++)
  {    
    //Digit Scanner (Iterates through each SR (digit) in a display module)
    for(int digit = 0; digit < maxDigits; digit++)
    {
      //Clears any garbage on the serial line
      shiftOut(DOUT,CLK,LSBFIRST,0);          //Shift out 0s to all displays
      SRData[dispID][digit] = 0;              //Stores a 0 for each digit so its completely off
    }
  }
  digitalWrite(LATCH,HIGH);      //Tells all SRs that uController is done sending data
}

void printSRData()
{
  if(!debug)
    return;

  Serial.println("Printing SR Data...");

  //Display Scanner
  for(int dispID = 0; dispID < maxDisplays; dispID++)
  {    
    Serial.print("Display # ");
    Serial.println(dispID);

    //Digit Scanner
    for(int digit = 0; digit < maxDigits; digit++)
    {
      Serial.print("Digit ");
      Serial.print(digit);
      Serial.print(": ");
      Serial.println(SRData[dispID][digit],BIN);
    }
    Serial.println();
  }
}

void setDigit(int dispID, int digit, int value, boolean dp)
{
  //Parameter checker
  if(dispID < 0 || dispID >= numDevices)
  {
    Serial.println("dispID OoB!");         //OoB = Out of bounds
    return;
  }

  if(digit < 0 || digit > maxDigits)
  {
    Serial.println("digit OoB!"); 
    return;
  }

  if(value < 0 || value > 9)
  {
    Serial.println("Invalid value!"); 
    return;
  }

  value = numTable[value];

  //Toggle dp if needed
  if(dp)
    value |= B00000001;          //Turns on the first binary digit (segment) using an OR bitmask

  //Store the digit
  SRData[dispID][digit] = value;

  if(debug)
    printSRData();
}

void setSegments(int dispID, int digit, byte value)
{
  //Parameter checker
  if(dispID < 0 || dispID >= numDevices)
  {
    Serial.println("dispID OoB!"); 
    return;
  }

  if(digit < 0 || digit > maxDigits)
  {
    Serial.println("digit OoB!"); 
    return;
  }

  if(value < 0 || value > 255)
  {
    Serial.println("Invalid byte!"); 
    return;
  }

  //Store the digit
  SRData[dispID][digit] = value;

  if(debug)
    printSRData();
}

void clearDisplay(int dispID)
{
  initializeSRData();
  refreshDisplay();
}

void refreshDisplay()
{
  //Digit Scanner
  for(int digit = 0; digit < maxDigits; digit++)
  {   
    //Display Scanner
    digitalWrite(LATCH,LOW);
    for(int dispID = numDevices -  1; dispID >= 0; dispID--)
    {
      //Pre-Digit blanker (shifts out 0s to correct digits before sending segment data to desired digit)
      for(int blanks = (maxDigits - 1 - digit); blanks > 0; blanks--)
        shiftOut(DOUT,CLK,LSBFIRST,0);

      shiftOut(DOUT,CLK,LSBFIRST,SRData[dispID][digit]);

      //Post-Digit blanker (shifts out 0s to remaining digits)
      for(int blanks = digit; blanks > 0; blanks--)
        shiftOut(DOUT,CLK,LSBFIRST,0);
    }
    digitalWrite(LATCH,HIGH);

    //Demonstrates multiplexing operation
    delay(delayTime);
    delayTime -= 10;
    if(delayTime <= 0)
      delayTime = 0;
  }
}

//==========END SR Functions==========
