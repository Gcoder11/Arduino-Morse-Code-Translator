#include "FastLED.h"
#include "lights.h"
#include "tests.h"
#include "project.h"
#include <Button.h>
#include <Arduino.h>
#include <OneButton.h>


// Example for Arduino UNO with input button on pin 2
#define PIN_INPUT 11

OneButton button(PIN_INPUT, true);

CRGB leds[NUM_LEDS+1];

Button button2 = Button(2);

bool currentlyTyping;

int lengthPressed = 0;
float lengthWaited;

int buttonState;
bool buttonUp = true;

int presses[4];

char characters[15];

int pressCounter = 0;

int characterCounter;


bool longPress;
bool shortPress;

void LongPressReleased(void *oneButton) {
  longPress = true;
}

void ShortPressReleased(void *oneButton) {
  shortPress = true;
}


void setup()
{
  delay( 3000 ); // power-up safety delay
  Serial.begin(9600); //enables serial output for debugging
  //WS2811 on pin 7, color sequence, lights data structure, and number of lights for controller
  FastLED.addLeds<LED_TYPE, LED_PIN, RGB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

  for (int i = 0; i < 4; i++) {
    presses[i] = 2;
  }
  for (int i = 0; i < 24; i++) {
    characters[i] = ' ';
  }

  button2.begin();
  shortPress = false;
  button.attachLongPressStop(LongPressReleased, &button);
  button.attachClick(ShortPressReleased, &button);

  FastLED.setBrightness(  BRIGHTNESS );  //sets the brightness for the strand of LEDs.  Default is 64, max is 255.
  chase();
  
  leds_init(); 
}

void loop()
{ 
  button.tick();
  if (pressCounter > 4) {
    pressCounter = 0;
  }
  if (characterCounter > 4) {
    characterCounter = 0;
  }
  if (longPress) {
    currentlyTyping = true;
    for (int i = 0; i < 25; i++) {
      leds[i]=CRGB::Black;
    }
    FastLED.delay(20);

    leds[11]=CRGB::Red;
    leds[12]=CRGB::Red;
    leds[13]=CRGB::Red;
    FastLED.show();
    lengthWaited = 0;
    longPress = false;
    presses[pressCounter] = 1;
    pressCounter += 1;

    
  } else if (shortPress){
    currentlyTyping = true;
    lengthWaited = 0;
    for (int i = 0; i < 25; i++) {
      leds[i]=CRGB::Black;
    }
    FastLED.delay(20);

    leds[11]=CRGB::Black;
    leds[12]=CRGB::Red;
    leds[13]=CRGB::Black;
    FastLED.show();


    shortPress = false;
    presses[pressCounter] = 0;
    pressCounter += 1;
  } 
   else if (currentlyTyping) {

      if (lengthWaited > 5000) {
        leds[11]=CRGB::Black;
        leds[12]=CRGB::Black;
        leds[13]=CRGB::Black;
        FastLED.delay(20);
        currentlyTyping = false;
        lengthWaited = 0;
        pressCounter = 0;
        characters[characterCounter] = GetChar(presses);
        characterCounter += 1;
        for (int i = 0; i < 4; i++) {
          presses[i] = 2;
        }
      }
      lengthWaited += 0.1;
    }
  

  if (button2.pressed()) {
    chase2();
    currentlyTyping = false;
    characterCounter = 0;
    for (int i = 0; i < 15; i++) {
      Serial.print(characters[i]);
      
    }
    Serial.println("");
    DisplayText(characters);


    //???? Problematic??????
    ResetPresses();
  }
  //blink_light_0_example();
  //blink_lights_0_and_24();
  //blink_all_lights();
  //blink_alternating_lights();
  //fade_brightness();
  //chase();
  //hase_two_colors_with_scroll();

  //add other functions you would like to execute here!
  
    
}

void ResetPresses() {
  for (int i = 0; i < 4; i++) {
    presses[i] = 2;
  }
  for (int i = 0; i < 24; i++) {
    characters[i] = ' ';
  }
  shortPress = false;
  longPress = false;
}

char GetChar(int presses[]) {
  int letterCounter = 0;
  char character = GetLetterFromMorse(presses);

  return character;
}

char GetLetterFromMorse(int* letter) {


int morseA[4] = {
0,1,2,2
};
int morseB[4] = {
1,0,0,0
};
int morseC[4] = {
1,0,1,0
};
int morseD[4] = {
1,0,0,2
};
int morseE[4] = {
0,2,2,2
};
int morseF[4] = {
0,0,1,0
};
int morseG[4] = {
1,1,0,2
};
int morseH[4] = {
0,0,0,0
};
int morseI[4] = {
0,0,2,2
};
int morseJ[4] = {
0,1,1,1
};
int morseK[4] = {
1,0,1,2
};
int morseL[4] = {
0,1,0,0
};
int morseM[4] = {
1,1,2,2
};
int morseN[4] = {
1,0,2,2
};
int morseO[4] = {
1,1,1,2
};
int morseP[4] = {
0,1,1,0
};
int morseQ[4] = {
1,1,0,1
};
int morseR[4] = {
0,1,0,2
};
int morseS[4] = {
0,0,0,2
};
int morseT[4] = {
1,2,2,2
};
int morseU[4] = {
0,0,1,2
};
int morseV[4] = {
0,0,0,1
};
int morseW[4] = {
0,1,1,2
};
int morseX[4] = {
1,0,0,1
};
int morseY[4] = {
1,0,1,1
};
int morseZ[4] = {
1,1,0,0
};
  if (Compare(presses, morseA)) {
    return 'a';
    
  }
  if (Compare(presses, morseB)) {
    return 'b';
  } else
    if (Compare(presses, morseC)) {
    return 'c';

  }else
    if (Compare(presses, morseD)) {
    return 'd';

  }else
    if (Compare(presses, morseE)) {
    return 'e';
    

  }else
    if (Compare(presses, morseF)) {
    return 'f';

  }else
    if (Compare(presses, morseG)) {
    return 'g';

  }else
    if (Compare(presses, morseH)) {
    return 'h';

  }else
    if (Compare(presses, morseI)) {
    return 'i';

  }else
    if (Compare(presses, morseJ)) {
    return 'j';

  }else
    if (Compare(presses, morseK)) {
    return 'k';

  }else
    if (Compare(presses, morseL)) {
    return 'l';

  }else
    if (Compare(presses, morseM)) {
    return 'm';

  }else
    if (Compare(presses, morseN)) {
    return 'n';

  }else
    if (Compare(presses, morseO)) {
    return 'o';

  }else
    if (Compare(presses, morseP)) {
    return 'p';

  }else
    if (Compare(presses, morseQ)) {
    return 'q';

  }else
    if (Compare(presses, morseR)) {
    return 'r';

  }else
    if (Compare(presses, morseS)) {
    return 's';

  }else
    if (Compare(presses, morseT)) {
    return 't';

  }else
    if (Compare(presses, morseU)) {
    return 'u';

  }else
    if (Compare(presses, morseV)) {
    return 'v';

  }else
    if (Compare(presses, morseW)) {
    return 'w';

  }else
    if (Compare(presses, morseX)) {
    return 'x';

  }else
    if (Compare(presses, morseY)) {
    return 'y';

  }else
    if (Compare(presses, morseZ)) {
    return 'z';

  } else {
    Serial.println("Not a real character!!!");
    return ' ';
  }
}

bool Compare(int array1[], int array2[]) {
  for (int i = 0; i < 4; i++) {
    if (array1[i] != array2[i]) {
      return false;
    }
  }
  return true;
}
