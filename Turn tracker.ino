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
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define NUM_LEDS 15


// Define I2C Address - change if reqiuired
const int i2c_addr = 0x3F;

// Defind LCD pinout
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Declair Variables
int buttonNextTurn = 5;
int buttonNextRound = 10;
int buttonUndo = 7;
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
int currentLED = 0;
int undoLED = 0;

CRGB leds[NUM_LEDS];



void setup()
{
    Serial.begin(9600);
    FastLED.addLeds<WS2812B, ledPin, RGB>(leds, NUM_LEDS);
    lcd.begin();
    pinMode(buttonNextTurn, INPUT);
    pinMode(buttonNextRound, INPUT);
    pinMode(buttonUndo, INPUT);
    lcd.clear();
    
   

}

// Add the main program code into the continuous loop() function
void loop() {
    
    buttonValTurn = digitalRead(buttonNextTurn);
    buttonValRound = digitalRead(buttonNextRound);
    buttonValUndo = digitalRead(buttonUndo);


    lcd.setCursor(0, 0);
    lcd.print(" Turn     Round");
    lcd.setCursor(0, 1);
    lcd.print(" ");
    lcd.print(displayValTurn);
    if (displayValTurn > 9) {
        lcd.print("       ");
    }
    else {
        lcd.print("        ");
    }
    lcd.print(displayValRound);



   // leds[currentLED] = CHSV (96, 255, 192);
      FastLED.clear();
    


   if (buttonValTurn == 0) {
    leds[currentLED] = CHSV (96, 255, 192);
    undoLED = currentLED;
    currentLED = currentLED + 1;
    lastButtonPress = 1;
    turnUndoVal = turnCount;
    turnCount = turnCount + 1;
    displayValTurn = turnCount;
    FastLED.show();
    delay(dt);
   }


    if (buttonValRound == 0 && displayValTurn > 1) {
        lastButtonPress = 2;
        turnCount = 1;
        currentLED = 0;
        leds[currentLED] = CHSV(96, 255, 192);
        FastLED.show();
        displayValTurn = turnCount;
        roundUndoVal = roundCount;
        roundCount = roundCount +1;
        displayValRound = roundCount;
        delay(dt);
    }

  if (buttonValUndo == 0 && lastButtonPress == 1) {
     displayValTurn = turnUndoVal;
     turnCount = turnUndoVal;
     currentLED = currentLED - 1;
     leds[currentLED] = CHSV(96, 255, 192);
     FastLED.show();
     delay(dt);
     }

   if (buttonValUndo == 0 && lastButtonPress == 2) {
    displayValTurn = turnUndoVal + 1;
    turnCount = turnUndoVal + 1;
    displayValRound = roundUndoVal;
    roundCount = roundUndoVal;
   delay(dt);
    }


}
