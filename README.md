# Trepol
Controller for the Trepol extractor fan.

This is software for the Arduino to control a Trepol extractor fan using an Arduino Uno and a Raspberry Pi.
The function of the Arduino is to replace the original Trepol controler.
There are three buttons on the control panel which are read by the Arduino.
The functions of the extractor fan are powered on using relays conected to analog pins A0 - A5
The remaining pins of the Trepol control panel drive the little LEDs on the display, these LEDs share lines with the buttons. 

The Arduino USB will be used to communicate with a Raspberry Pi.
