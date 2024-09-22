//tests.cpp - learn how to control the lights here!
//by Alison N. Norman

#include "tests.h"

int brightness = 0;
//blink the light closest to the controller



void chase()
{
for (int i=0; i< NUM_LEDS; i++)
  {
    leds[i]=CRGB::Pink;
    FastLED.delay(100);
    leds[i]=CRGB::Black;
  }
}

void chase2()
{
for (int i=0; i< NUM_LEDS; i++)
  {
    leds[i]=CRGB::Pink;
    FastLED.delay(10);
    leds[i]=CRGB::Black;
  }
  leds[24]=CRGB::Black;
  FastLED.show();
}






