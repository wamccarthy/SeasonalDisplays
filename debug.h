/*********************************************************
debug.h

Provide debugging statements that are easy to turn off when
no longer needed

2024-01-23
W.A.McCarthy

**********************************************************/

#define DEBUG_H     // Notify procedures if debugging is included

#define DEBUG       // Turn on debugging  COMMENT OUT FOR IMPLEMENTATION

#define ESP32       // Indicate processor for baudrate

#ifdef DEBUG
    #define debug(x) Serial.print(F(x))
    #define debugln(x) Serial.println(F(x))
    #define debugvar(t,n) Serial.print(F(t));Serial.println(n)
#else
    #define debug(x)
    #define debugln(x)
    #define debugvar(...)
#endif

#ifdef ESP32
  #define BAUD_RATE 115200    // ESP32-WROOM-DA
#else 
 #define BAUD_RATE 9600    // NANO
#endif

/*******************************************
INCLUDE IN SETUP()!
#ifdef DEBUG
  Serial.begin(BAUD_RATE);
  debugln("Debugging activated");
endif
*******************************************/