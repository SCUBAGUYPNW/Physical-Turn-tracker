// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       Turn tracker.ino
    Created:	1/4/2021 20:58:56
    Author:     ROG-CODING-LAPT\scuba
*/

// Define User Types below here or use a .h file
//


// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files
//

// The setup() function runs once each time the micro-controller starts
#include <FastLED.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

//#define NUM_LEDS 15




// Define LCD pinout
const int  en = 2, rw = 1, rs = 0, d4 = 4, d5 = 5, d6 = 6, d7 = 7, bl = 3;

// Define I2C Address - change if reqiuired
const int i2c_addr = 0x3F;

LiquidCrystal_I2C lcd(0x27, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);
int buttonNextTurn = 10;
int buttonNextRound = 11;
int buttonUndo = 12;
int buttonValTurn;
int buttonValRound;
int buttonValUndo;
int dt = 1000;
int turnCount = 0;
int roundCount = 0;
int displayValTurn = 0;
int displayValRound = 0;
int turnUndoVal = 0;
int roundUndoVal = 0;
int lastButtonPress = 0;
const int ledPin = 8;
int currentLED = 9;
int undoLED = 0;

//CRGB leds[NUM_LEDS];



void setup()
{
    Serial.begin(9600);
    //FastLED.addLeds<WS2812B, ledPin, RGB>(leds, NUM_LEDS);
    lcd.begin(16, 2);
    pinMode(buttonNextTurn, INPUT);
    pinMode(buttonNextRound, INPUT);
    pinMode(buttonUndo, INPUT);
    lcd.clear();
    //FastLED.clear();

}

// Add the main program code into the continuous loop() function
void loop()
{


}
