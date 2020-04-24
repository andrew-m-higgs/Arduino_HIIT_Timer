# Arduino_HIIT_Timer

This simple Arduino sketch performs as follows:
* When switch on the screen is drawn. Press the buttun to begin.
* A period of Warm Up begins (time set in code. Deafault is 180s)
* This is followed by a number of circuits (default is 4). for each circuit:
  * Each execise is run (default is 7). An exercise consists of 30s work out.
  * This is followed by 15s of rest after each exercise.
* Each circuit is followed by a 60s break.
* Then comes the Warm Down. This is also 180s.

This project aims to make a useful yet uncomplicated device to assist with staying fot at home.

## Arduino Version
The Arduino version requires:
* An Arduino.
* A switch
* A buzzer or and LED
* A screen (code uses a 20x4 LCD)
* A 10K variable resistor (if using the screen)

## The Standalone Version
The Standalone version requires:
* An ATMega328P chip (will work with other version as long as there are enough free pins)
* 16Mhz crystal
* 2 22pF capacitors
* 1x 10K resistor
* A switch
* A buzzer or and LED
* A screen (code uses a 20x4 LCD)
* A 10K variable resistor (if using the screen)

In the Drawings folder of this repository you will find Breadboard diagram from Fritzing (and the Fritzing project). I have complete the Breadboard but not the schematic or PCB. I have also included some as yet unfinished KiCAD drawings of both version mention above.

Hope you have fun building this.

