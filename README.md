# Arduino-Morse-Code-Translator

This project uses an Arduino microcontroller, two buttons, and a strand of multicolor LEDs organized in a 5x5 grid.  Using the input
of the button allows you to input a sequence in morse code, and then print out the result to the screen in letters.

Requirements:
-Arduino UNO Microcontroller
-25 LED Type: WS2811 in PIN 7 (Organized in grid pattern snaking up)
-2 Push Buttons:  
  Button 1:PIN 11 (Enters Morse Sequence using Short and Long Presses)
  Button 2: PIN 2 (Submits Morse Sequence)

When typing use Button 1 to type a sequence of morse code letters. The screen will display whether the press inputted is a long or a short
press by displaying a dot or a dash. Once you complete typing a letter, let the screen clear, and then you can begin inputting the next letter
in the sequence. Once you are complete, wait for the screen to clear once more, and then press button 2 to begin displaying the sequence. All
letters will be displayed for a few seconds in order, and then the screen will clear once more allowing you to input another sequence.

Warning:
Arduino has a very limited memory capacity so there is a cap of how many letters you can do during a cycle. If anyone knows of any optimizations
to fix this please create a pull request! 

Thanks so much and have fun!
