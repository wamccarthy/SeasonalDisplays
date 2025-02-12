# SeasonalDisplays
String of addressable LEDs are animated with various routines (Arduino IDE- Nano &amp; ESP32

/*********************************************************
defines.h

Provide constants to control the various aspects of the 
various functions

/*********************************************************
debug.h

Provide debugging statements that are easy to turn off when
no longer needed

/*************************************************************
SeasonalDisplays.ino

for the 300/600 Addressable LEDs around the family room bay window
and the lights around the front door. 

Colour is green/red - for Christmas
  white/cyan is a good look
  white/ grey - regular
  white/ red - Valentine's 
  green/ white - St. Patrick's

/***********************************************************************
Tracking.h

Pixels set to COLOR01 then COLOR02 is marched forward then backward

/***************************************************************************
Series.h

Description: 
  - pixels ar set with a repeating pattern starting with 2 of each color
  and progressing to 7 of each color
  - the pattern then reverses bak down to 2 of each color

//----------------------------------------------------------------------
Random.h

Pixels set randomly to a random colour from the colours array

//----------------------------------------------------------------------
Expand.h

Set pixels at set intervals then set pixels on each side after a delay
After the expansion count, shrink back to 1


