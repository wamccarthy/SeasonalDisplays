/***********************************************************************
Random.h

Pixels set randomly to a random colour from the colours array








***********************************************************************/

#ifndef DEFINES_H
#include "defines.h"  //############### Constants!
                      // Global leds[]
#endif

//=======================================================================
// TWINKLE_RANDOM
//=======================================================================
void Random() {
  debugln("Random starts now!");
  // Christmas??
  // int num_colours = 6;
  //CRGB colours[num_colours] = {CRGB::Blue, CRGB::Violet, CRGB::Red, CRGB::Blue, CRGB::Orange, CRGB::Green};

  // Other times
  //int num_colours = 3;
  //CRGB colours[num_colours] = {0x444444, 0x008888, 0xff82ee};  // White, Cyan, Violet

  // Valentine's
  int num_colours = 3;
  CRGB colours[num_colours] = { CRGB::Red, CRGB::White, CRGB::Pink };

  // St. Patrick's
  //int num_colours = 3;
  //CRGB colours[num_colours] = {CRGB::Green, CRGB::Cyan, CRGB::Violet};


  uint8_t pixel = random(NUM_LEDS / 3) * 3;
  CRGB thisColour = colours[random(num_colours)];
  debugln("Set 3? at a time");
  for (uint8_t i = 0; i < RANDOM_GROUPING; i++) {
    leds[pixel + i] = thisColour;
  }
  FastLED.show();
  delay(RANDOM_DELAY);
}
