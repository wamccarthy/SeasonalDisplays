/***************************************************************************
Series.h

Description: 
  - pixels ar set with a repeating pattern starting with 2 of each color
  and progressing to 7 of each color
  - the pattern then reverses bak down to 2 of each color

Author:
  W.A.McCarthy

Date:
  2025-02-07: Clean up variable types and debug statements

              







****************************************************************************/

#ifndef DEFINES_H
  #include "defines.h"  //############### Constants!
                      // Global leds[]
#endif

//=======================================================================
//  SERIES 
//=======================================================================

//-----------------------------------------------------------------------
// fill alternating colors
void fill(uint8_t reps){
  debugvar("    fill these reps  >> ",reps);
  uint16_t i=0;
  uint16_t n=0;
  while (true) {
    for(n=0;n<reps;n++) {
      leds[i+n] = COLOR01; 
    }
    i += reps;
    if (i>=NUM_LEDS) break;
    for(n=0;n<reps;n++) {
      leds[i+n] = COLOR02; 
    }
    i += reps;
    if (i>=NUM_LEDS) break;
    debugvar("i is now ",i);
  }

}
//----------------------------------------------------------
void Series(){
  for (uint8_t repeats=SERIES_UPPER_LIMIT; repeats>=SERIES_LOWER_LIMIT; repeats--){  
    debugvar("down repeats = ",repeats);
    fill(repeats);
    FastLED.show();
    delay(SPEED_SERIES);
  }
  for (uint8_t repeats=SERIES_LOWER_LIMIT+1; repeats<=SERIES_UPPER_LIMIT+1; repeats++){  
    debugvar("up repeats = ",repeats);
    fill(repeats);
    FastLED.show();
    delay(SPEED_SERIES);
  }
}
