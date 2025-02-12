

#ifndef DEFINES_H
  #include "defines.h"  //############### Constants!
                      // Global leds[]
#endif


//=======================================================================
//  EXPAND - grow and shrink second colour
//=======================================================================
void Expand(){
  //debugln("Expand is ready");
  // First, fill with primary color
  for (uint16_t i=0; i<NUM_LEDS; i++){
    leds[i] = COLOR01;
  }

  // Expanding secondary color
  // EXPAND_INTERVAL is the number of pixels around the target pixel (if 5 then 2 on either side)
  for (uint16_t i=0;i<=EXPAND_INTERVAL/2; i++) {    // 0,1,2
    // Grow secondary from every nth pixel to fill
    for (uint16_t n=EXPAND_INTERVAL; n<NUM_LEDS; n+=EXPAND_INTERVAL){  // n +/- 0,1,2
      leds[n+i] = COLOR02;
      leds[n-i] = COLOR02;
    }
    FastLED.show();
    delay(SPEED_EXPAND);
  }



  // Shrinking secondary color
  debugln("Shrinking....");
  for (int i=EXPAND_INTERVAL/2;i>=0;i--) {   // 2,1,0 uint drops to 65525!!
    debugvar("i set to ",i);
    // Shrink secondary from every nth pixel to fill
    for (uint16_t n=EXPAND_INTERVAL; n<NUM_LEDS; n+=EXPAND_INTERVAL){  
      leds[n+i] = COLOR01;
      leds[n-i] = COLOR01;
    }
    FastLED.show();
    delay(SPEED_EXPAND);
  }

}


