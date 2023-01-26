#ifndef SEGMENTS_H_
#define SEGMENTS_H_

#include <Arduino.h>

#ifndef CLK              //Connected to TPIC pin 13: SRCLK (aka Clock)
#define CLK 9
#endif

#ifndef LATCH            //Connected to TPIC pin 12: RCLK (aka Latch/load/CS/SS...)
#define LATCH 10
#endif

#ifndef OE               //Connected to TPIC pin 9: OE (Output Enable)
#define OE 11
#endif

#ifndef DOUT
#define DOUT 9           //Connected to TPIC pin 3: SER (aka MOSI)
#endif

//Number Patterns (0-9)
//***Drains 0-7 must be connected to segments A-DP respectively***
const byte numTable[] = 
{
  B11111100,
  B01100000,
  B11011010,
  B11110010,
  B01100110,
  B10110110,
  B10111110,
  B11100000,
  B11111110,
  B11110110
};

//Global Variables
int const numDevices = 4;                       //The number of x-digit display modules you plan to use
int const maxDisplays = 4;                      //The maximum displays that could be accommodated (see note 1)
int const maxDigits = 7;                        //The maximum digits you plan on displaying per display module (each SR can handle a max of 8 digits)
int SRData[maxDisplays][maxDigits];                         //The storage location for the digit information. We must specify a fixed array at compile time (see note 2)
bool debug = true;                     //Change to true to print messages
int delayTime = 1000;                     //Optional (just for demonstrating multiplexing)

/*
  Notes
 1. It is recommended to use an external power supply to avoid oversource/sinking the microcontroller
    or if you need to power high voltage, high current displays. This code will turn on/off all segments in a digit for ***each*** display.
    So, if using 2x 3-digit displays all displaying an 8 + DP, the max consumption will be:
       20mA (desired forward current) * 8 (segments that are on) * 2 (displays showing identical info) = 320mA
 2. The first dimension should equal maxDisplays. The second dimension should equal the number of digits
 */


void initializeSRData();
void printSRData();
void setDigit(int dispID, int digit, int value, boolean dp);
void setSegments(int dispID, int digit, byte value);
void clearDisplay(int dispID);
void refreshDisplay();


#endif