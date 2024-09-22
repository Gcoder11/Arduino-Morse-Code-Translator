//project.cpp - Put your project code here!
using namespace std;
#include "lights.h"
#include "project.h"

int arrayA[12] = {1, 4, 5, 8, 11, 12, 13, 14, 15, 18, 22, 23};
int arrayB[14] = {1, 2, 3, 4, 5, 8, 12, 13, 14, 15, 18, 22, 23, 24};
int arrayC[9] = {2, 3, 5, 8, 14, 15, 18, 22, 23};
int arrayD[12] = {2, 3, 4, 5, 8, 11, 14, 15, 18, 22, 23, 24};
int arrayE[13] = {1, 2, 3, 4, 5, 12, 13, 14, 15, 21, 22, 23, 24};
int arrayF[10] = {4, 5, 12, 13, 14, 15, 21, 22, 23, 24};
int arrayG[12] = { 1, 2, 3, 5, 8, 11, 12, 14, 15, 21, 22, 23}; //CHECK SHAPES AGAIN TOO
int arrayH[13] = {1, 4, 5, 8, 11, 12, 13, 14, 15, 18, 21, 24};
int arrayI[9] = {1, 2, 3, 7, 12, 17, 21, 22, 23};
int arrayJ[11] = {2, 3, 4, 5, 7, 12, 17, 21, 22, 23, 24};
int arrayK[10] = {1, 4, 5, 7, 13, 14, 15, 17, 21, 24};
int arrayL[8] = {1, 2, 3, 4, 5, 14, 15, 24};
int arrayM[13] = {0, 4, 5, 9, 10, 12, 14, 15, 16, 18, 19, 20, 24};
int arrayN[13] = {0, 4, 5, 8, 9, 10, 12, 14, 15, 16, 19, 20, 24};
int arrayO[10] = {2, 3, 5, 8, 11, 14, 15, 18, 22, 23};
int arrayP[10] = {4, 5, 12, 13, 14, 15, 18, 22, 23, 24};
int arrayQ[16] = {0, 1, 2, 3, 5, 8, 11, 14, 15, 18, 22, 23, 13, 16, 19, 21};
int arrayR[13] = {0, 4, 5, 8, 12, 13, 14, 15, 18, 22, 23, 24};
int arrayS[14] = {1, 2, 3, 4, 8, 11, 12, 13, 14, 15, 21, 22, 23, 24};
int arrayT[9] = {2, 7, 12, 17, 20, 21, 22, 23, 24};
int arrayU[10] = {2, 3, 5, 8, 11, 14,15,18, 21, 24};
int arrayV[9] = {2, 6, 8, 10, 14, 15, 19, 20, 24};
int arrayW[13] = {0, 4, 5, 6, 8, 9, 10, 12, 14, 15, 19, 20, 24};
int arrayX[9] = {0, 4, 6, 8, 12, 16, 18, 20, 24};
int arrayY[7] = {2, 7, 12, 16, 18, 20, 24};
int arrayZ[11] = {1, 2, 3, 4, 5, 13, 17, 21, 22, 23, 24};
int arrayBlank[25] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};



void DisplayText(char characters[]) {
  int* array;
  int counter = 0;

  int charactersToDisplay = 0;

  for (int i = 0; i < 15; i++) {
    if (characters[i] == ' ') {
      charactersToDisplay = i;
      i = 20;
    }
  }
  for (int i = 0; i < charactersToDisplay; i++) {
    int character = characters[i];
if (character == 'a') {
   array = arrayA;
   counter = 12;
 } else if (character == 'b') {
   array = arrayB;
   counter = 14;
 }
 else if (character == 'c') {
   array = arrayC;
   counter = 9;
 }
 else if (character == 'd') {
   array = arrayD;
   counter = 12;
 }
 else if (character == 'e') {
   array = arrayE;
   counter = 13;
 }else if (character == 'f') {
   array = arrayF;
   counter = 10;
 }
 else if (character == 'g') {
   array = arrayG;
   counter = 12;
 }
 else if (character == 'h') {
   array = arrayH;
   counter = 12;
 }
 else if (character == 'i') {
   array = arrayI;
   counter = 9;
 }
 else if (character == 'j') {
   array = arrayJ;
   counter = 11;
 }
 else if (character == 'k') {
   array = arrayK;
   counter = 10;
 }
 else if (character == 'l') {
   array = arrayL;
   counter = 8;
 }
 else if (character == 'm') {
   array = arrayM;
   counter = 13;
 }
 else if (character == 'n') {
   array = arrayN;
   counter = 13;
 }
 else if (character == 'o') {
   array = arrayO;
   counter = 10;
 }
 else if (character == 'p') {
   array = arrayP;
   counter = 10;
 }
 else if (character == 'q') {
   array = arrayQ;
   counter = 12;
 }
 else if (character == 'r') {
   array = arrayR;
   counter = 13;
 }
 else if (character == 's') {
   array = arrayS;
   counter = 13;
 }
 else if (character == 't') {
   array = arrayT;
   counter = 9;
 }
 else if (character == 'u') {
   array = arrayU;
   counter = 10;
 }
 else if (character == 'v') {
   array = arrayV;
   counter = 9;
 }
 else if (character == 'w') {
   array = arrayW;
   counter = 13;
 }
 else if (character == 'x') {
   array = arrayX;
   counter = 9;
 }
 else if (character == 'y') {
   array = arrayY;
   counter = 7;
 }
 else if (character == 'z') {
   array = arrayZ;
   counter = 11;
 } else {
   array = arrayBlank;
   counter = 24;
 }

    
  for (int i = 0; i < 25; i++) {
    leds[i]=CRGB::Black;
  }



  for (int i = 0; i < counter; i++) {

    leds[array[i]]=CRGB::Red;
  }
  FastLED.delay(1000);
  for (int i = 0; i < 25; i++) {
    leds[i]=CRGB::Black;
  }
  FastLED.show();
  }

}



