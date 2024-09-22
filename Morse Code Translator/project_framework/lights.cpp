// lights.cpp - Lights buffer handling
//
// Adapted from code by John Graham-Cumming by Alison N. Norman
//

#include "lights.h"

// leds_init: Initializes leds to all pixels off and mirrors
// that to the actual display
void leds_init()
{
  for ( int x = 0; x < NUM_LEDS + 1; ++x )
    leds[x] = CRGB::Black;

  FastLED.show();
}

// leds_scroll: scroll the leds left one column
void leds_scroll()
{
  for ( int x = 1; x < NUM_LEDS + 1; ++x ) {
    leds[x-1] = leds[x];
  }

  FastLED.show();
}

void test_leds()
{
  for(int j = 0; j < 5; j++)
  {
    for(int i=0; i < NUM_LEDS; i++)
    {
      if(i%2==0)
         leds[i]=CRGB::SteelBlue;
      else
         leds[i]=CRGB::PaleVioletRed;
    }
    FastLED.delay(700);
    for(int i=0; i < NUM_LEDS; i++)
    {
      if(i%2==0)
         leds[i]=CRGB::PaleVioletRed;
      else
         leds[i]=CRGB::SteelBlue;
    }
    FastLED.delay(700);
  }
}

