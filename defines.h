/*********************************************************
defines.h

Provide constants to control the various aspects of the 
various functions

2024-01-23
W.A.McCarthy

**********************************************************/
#define DEFINES_H

#ifndef DEBUG_H
  #include "debug.h"
#endif

#define NUM_LEDS   300            // 300 for Bay window    600 for front door
#define LED_TYPE   WS2812B
#define DATA_PIN   2             // 2 for Arduino Nano   13 for ESP32
#define COLOR_ORDER GRB

/* Limit current to protect drawing too much */
#define VOLTS          5
#define MAX_MA       2000

// Turn on the processes desired
//#define TRACKING_ON
#define SERIES_ON
#define RANDOM_ON
#define EXPAND_ON

// Color selection ----------------------------------------------------
// Other times
//#define COLOR01 0x444444     // Brightness for each colour led
//#define COLOR02 CRGB::Cyan      // Brightness for each colour led

// Christmas
//#define COLOR01 CRGB::Red     // Brightness for each colour led
//#define COLOR02 CRGB::Green      // Brightness for each colour led

// Valentine's
#define COLOR01 0x444444      // Brightness for each colour led
#define COLOR02 CRGB::DarkRed     // Brightness for each colour led

// St. Patrick's
//#define COLOR01 CRGB::Green     // Brightness for each colour led
//#define COLOR02 CRGB::White      // Brightness for each colour led

//--------------------------------------------------------------------------------
// Tracking controls
#define INTERVAL 5    // Spacing of other colour in Tracking
//#define ROTATION_COUNT 20   // TESTING
#define ROTATION_COUNT 100   // Multiple of INTERVAL to avoid skip in the middle
                              // Actual count will be ROTATION_COUNT / INTERVAL !!!
#define SPEED_TRACKING 1000  /* Higher is slower - time between moves */
#define TRACKING_DURATION 120000    // 1000 per second - uses millis for time lapse
                              // 120000 = 2 minutes

//-----------------------------------------------------------------------------------
// Series controls
#define SERIES_DURATION 120000    // 1000 per second - uses millis for time lapse
#define SPEED_SERIES 2000       /* Higher is slower - time between shrink */
#define SERIES_UPPER_LIMIT 7    // Maximum number of repeats
#define SERIES_LOWER_LIMIT 2    // Minimum number of repeats
//----------------------------------------------------------------------------------
// Twinkle_random controls
#define RANDOM_DURATION 120000      // 1000 per second - uses millis for time lapse
                                // 120000 = 2 minutes
#define RANDOM_DELAY  100       // Time between setting a random pixel
#define RANDOM_GROUPING 3       // Number of pixels to set each time
//-----------------------------------------------------------------------------------
// Expand controls
#define EXPAND_DURATION 120000  // 2 minutes     
#define EXPAND_INTERVAL 5     // Odd number so expand converges
#define SPEED_EXPAND 2000

//-----------------------------------------------------------------------------------
// Global declaration
CRGB leds[NUM_LEDS];
