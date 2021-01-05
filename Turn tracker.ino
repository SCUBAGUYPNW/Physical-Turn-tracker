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
    Serial.print("Button Next Turn = ");
    Serial.print(lastButtonPress);
    Serial.print(", ");
    Serial.print("Button Next Round = ");
    Serial.print(buttonValRound);
    Serial.print(", ");
    Serial.print("Button Undo = ");
    Serial.println(buttonValUndo);

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

    //leds[9] = CHSV (96, 255, 192);
    //FastLED.show();
    if (buttonNextTurn == 1) {
        //  leds[currentLED] = CHSV (96, 255, 192);
        undoLED = currentLED;
        currentLED = currentLED + 1;
        lastButtonPress = 1;
        turnUndoVal = turnCount;
        turnCount = turnCount + 1;
        displayValTurn = turnCount;
        ;
        delay(dt);
    }
    if (buttonValRound == 1 && displayValTurn > 1) {
        lastButtonPress = 2;
        turnCount = 1;
        displayValTurn = turnCount;
        roundUndoVal = roundCount;
        roundCount = roundCount + 1;
        displayValRound = roundCount;
        delay(dt);
    }

    if (buttonValUndo == 1 && lastButtonPress == 1) {
        displayValTurn = turnUndoVal;
        turnCount = turnUndoVal;
        delay(dt);
    }

    if (buttonValUndo == 1 && lastButtonPress == 2) {
        displayValTurn = turnUndoVal + 1;
        turnCount = turnUndoVal + 1;
        displayValRound = roundUndoVal;
        roundCount = roundUndoVal;
        delay(dt);
    }


}
