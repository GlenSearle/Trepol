/*
This is software for the Arduino to control a Trepol extractor fan using an Arduino Uno and a Raspberry Pi.
The function of the Arduino is to replace the original Trepol controler.
There are three buttons on the control panel which are read by the Arduino.
The functions of the extractor fan are powered on using relays conected to analog pins A0 - A5
The remaining pins of the Trepol control panel drive the little LEDs on the display, these LEDs share lines with the buttons. 

The Arduino USB will be used to communicate with a Raspberry Pi.
*/


// digital pins 2,4 & 7 has a push button attached to them.
int pushButtonLight = 2;
int pushButtonUpDown = 4;
int pushButtonOnOff = 7;


// Analog pins A0 to A5 have a male break out header and can be used for controlling relays.
// Give these better names!
int relayPinZero = A0;
int relayPinOne = A1;
int relayPinTwo = A2;
int relayPinThree = A3;
int relayPinFour = A4;
int relayPinFive = A5;

// The pins going to the LEDs on the Trepol dislay
int displayLightZero = 3;
int displayLightOne = 5;
int displayLightTwo = 6;
int displayLightThree = 7;
int displayLightFour = 8;
int displayLightFive = 9;
int displayLightSix = 10;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButtonLight, INPUT);
  pinMode(pushButtonOnOff, INPUT);
  pinMode(pushButtonUpDown, INPUT);

  pinMode(relayPinZero, OUTPUT);
  pinMode(relayPinOne, OUTPUT);
  pinMode(relayPinTwo, OUTPUT);
  pinMode(relayPinThree, OUTPUT);
  pinMode(relayPinFour, OUTPUT);
  pinMode(relayPinFive, OUTPUT);

  pinMode(displayLightZero, OUTPUT);
// This pin blocks two buttons.
//  pinMode(displayLightOne, OUTPUT);
  pinMode(displayLightTwo, OUTPUT);
  // This pin blocks a button
//  pinMode(displayLightThree, OUTPUT);
  pinMode(displayLightFour, OUTPUT);
  pinMode(displayLightFive, OUTPUT);
  pinMode(displayLightSix, OUTPUT);
  

// Red status LED.
//  pinMode(13, OUTPUT);

}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonStateLight = digitalRead(pushButtonLight);
  int buttonStateOnOff = digitalRead(pushButtonOnOff);
  int buttonStateUpDown = digitalRead(pushButtonUpDown);
  // print out the state of the button:
  Serial.print("Light button: ");
  Serial.println(buttonStateLight);
  Serial.print("OnOff button: ");
  Serial.println(buttonStateOnOff);
  Serial.print("UpDown: ");
  Serial.println(buttonStateUpDown);
  Serial.println("");
  delay(1000);        // delay in between reads for stability
}

int buttonLightPressed(){}

int buttonOnOffPressed(){}

int buttonUpDownPressed(){}


