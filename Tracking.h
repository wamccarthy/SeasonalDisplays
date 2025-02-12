/***********************************************************************
Tracking.h

Pixels set to COLOR01 then COLOR02 is marched forward then backward


***********************************************************************/
#ifndef DEFINES_H
  #include "defines.h"  //############### Constants!  -- Global leds[]
#endif

//============================================================
// Set all pixels to primary color then at intervals, 
//    secondary color
void FillInterval(){
  // Fill with one colour
  debugln("Filling before rotating......");
  for (uint16_t i=0; i<NUM_LEDS; i++){
    leds[i] = COLOR01;
  }
  // Put in the other colour at regular intervals
  for (uint16_t i=0; i<NUM_LEDS; i+= INTERVAL){
    leds[i] = COLOR02;
  }
}

//===========================================================
void Forward(){
  // Make the pattern to be rotated
  FillInterval();
  // Rotate the pixels for a while
  for (uint8_t i=0;i<ROTATION_COUNT;i++){
    // Remember the pixel at the end of the strand
    CRGB keeper = leds[NUM_LEDS-1];
    // Pull the pixels up by one
    for (int j=NUM_LEDS-1;j>0;j--){
      leds[j] = leds[j-1];
    }
    leds[0] = keeper;   // The removed end pixel goes here

    FastLED.show();
    delay(SPEED_TRACKING);
  }
}

//-----------------------------------------------------------
void Backward(){
  debugln("Backward");
  // Make the pattern to be rotated
  FillInterval();
  debugln("Colours are set     ");
  // Rotate the pixels for a while
  for (int i=0;i<ROTATION_COUNT;i++){
    //debug(i);
    // Remember the pixel at the beginning of the strand
    CRGB keeper = leds[0];
    // Move from start to the end down one
    //for (int j=0;j<NUM_LEDS;j++){
    //  leds[j] = leds[j+1];
    //}
    //leds[NUM_LEDS-1] = keeper;  // The last one gets the old first one
    FastLED.show();
    delay(SPEED_TRACKING);
  }
}


//------------------------------------------------------------
void Tracking(){
  //Forward();
  delay(1000);
  
  //Backward();
  delay(1000);
}
