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
char relayPins[] = {A0, A1, A2, A3, A4, A5};

// The pins going to the LEDs on the Trepol dislay
int displayLightZero = 3;
int displayLightOne = 5;
int displayLightTwo = 6;
int displayLightThree = 7;
int displayLightFour = 8;
int displayLightFive = 9;
int displayLightSix = 10;
byte displayLightPins[] = {3, 5, 6, 7, 8, 9, 10};

byte buttonStatusLights;
byte buttonStateOnOff;
byte buttonStateUpDown;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButtonLight, INPUT);
  pinMode(pushButtonOnOff, INPUT);
  pinMode(pushButtonUpDown, INPUT);


for(int i = 0; i < 5; i++) {
    pinMode(relayPins[i], OUTPUT);
  }
  
/*
 
for(int i = 0; i < 7; i++) {
    pinMode(displayLightPins[i], OUTPUT);
}
*/


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

  if (not digitalRead(pushButtonLight))
  {
    Serial.println("Light button has been pressed");
      buttonLightPressed();
  }

  if (not digitalRead(pushButtonOnOff))
  {
    Serial.println("OnOff button has been pressed");
      buttonOnOffPressed();
  }

  if (not digitalRead(pushButtonUpDown))
  {
    Serial.println("UpDown button has been pressed");
      buttonUpDownPressed();
  }

  Serial.print("Light status: ");
  if (buttonStatusLights)
  {
  Serial.println("Light");
  }
  else
  {
  Serial.println("Dark");
  }

  Serial.print("On Off status: ");
  if (buttonStateOnOff)
  {
  Serial.println("On");
  }
  else
  {
  Serial.println("Off");
  }
  
  Serial.print("Up Down status: ");
  if (buttonStateUpDown)
  {
  Serial.println("Up");
  }
  else
  {
  Serial.println("Down");
  }

  int buttonStatusLights;
  int buttonStateOnOff;
  int buttonStateUpDown;
 

  blinknLights();
  delay(1000);        // delay in between reads for stability
}

int blinknLights(){
  
  }

int buttonLightPressed(){
  if (buttonStatusLights)
   {
    buttonStatusLights = 0;
    digitalWrite(A0, LOW);
   }
   else
   {
    buttonStatusLights = 1;
    digitalWrite(A0, HIGH);
   }
  }


int buttonOnOffPressed(){
    if (buttonStateOnOff)
   {
    buttonStateOnOff = 0;
    digitalWrite(A1, LOW);
   }
   else
   {
    buttonStateOnOff = 1;
    digitalWrite(A1, HIGH);
   }
  }

int buttonUpDownPressed(){
    if (buttonStateUpDown)
   {
    buttonStateUpDown = 0;
    digitalWrite(A2, LOW);
   }
   else
   {
    buttonStateUpDown = 1;
    digitalWrite(A2, HIGH);
   }
  }
