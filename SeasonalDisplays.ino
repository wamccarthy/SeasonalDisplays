/*************************************************************
SeasonalDisplays.ino

for the 300/600 Addressable LEDs around the family room bay window
and the lights around the front door. 

Colour is green/red - for Christmas

    white/ grey - regular
    white/ red - Valentine's 
    green/ white - St. Patrick's

Author:
  W.A.McCarthy

Modified:
  2024-08-06: First iteration
  2025-01-08: Separated function into include files + defines
  2025-02-01: Added debug macros
  2025-02-07: Cleaned up Expand where shrinking dropped below 0 
              and uint8_t became large (unsigned)
              Random tidy up
              Series testing


*************************************************************/

#include <FastLED.h>

#ifndef DEFINES_H
  #include "defines.h"  //############### Constants!
                      // Global leds[]
#endif


//=======================================================================
// External functions

#ifdef TRACKING_ON
  #include "Tracking.h" // Primary color set, secondary color rotates
#endif
#ifdef SERIES_ON
  #include "Series.h"   // Alternting colors in ascending groups 
#endif
#ifdef RANDOM_ON
  #include "Random.h"   // Random Pixel set to random from color set
#endif
#ifdef EXPAND_ON
  #include "Expand.h"   // Secondary color grows on both sides then shrinks
#endif


//##############################################################
// 

void runner( void (*f)(), char selector ) {
  uint32_t duration = 0;
  switch( selector ) {
    case 'T': duration = TRACKING_DURATION; break;
    case 'S': duration = SERIES_DURATION; break;
    case 'R': duration = RANDOM_DURATION; break;
    case 'E': duration = EXPAND_DURATION; break;
  }

  debugvar("duration = ",duration);
  uint64_t start_time = millis();
  while (millis() - start_time < duration) {
    (*f)();
  }
}

//--------------------------------------------------------------
void setup() {

  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  // Limit for the plugin power supply  for (unsigned int k=0;k<TRACKING_REPEAT;k++){

  FastLED.setMaxPowerInVoltsAndMilliamps(VOLTS, MAX_MA);
  FastLED.setBrightness(40);
  for (unsigned int i=0;i<NUM_LEDS;i++){
    leds[i].setRGB(0,0,0);
  }
  #ifdef DEBUG
    Serial.begin(BAUD_RATE);
    Serial.println("Debugging in progress.....");
  #endif
}
//----------------------------------------------------------------------
void loop() {
  
debugln("Looping.....");

#ifdef TRACKING_ON
  runner (Tracking,'T');
#endif
#ifdef SERIES_ON
  runner (Series, 'S');
#endif
#ifdef RANDOM_ON
  runner(Random, 'R');
#endif
#ifdef EXPAND_ON
  runner(Expand, 'E');
#endif

}
