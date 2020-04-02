#include <LiquidCrystal.h>

/*********************

Example code for the Adafruit RGB Character LCD Shield and Library

This code displays text on the shield, and also reads the buttons on the keypad.

**********************/

// include the library code:
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

// These #defines make it easy to set the backlight color
#define ON 0x1
#define OFF 0x0

void setup() {
  // Debugging output
  Serial.begin(9600);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  lcd.clear();

  lcd.setCursor(0,0);
    lcd.print("Pls save me");
   
    }

void loop() {
  /*lcd.scrollDisplayRight();
  delay(100);*/
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
 
  uint8_t buttons = lcd.readButtons();

 Serial.print("buttons");
 
    if (buttons & BUTTON_UP) {
      lcd.print("UP");
      Serial.print(buttons);
      delay(500);
      lcd.setBacklight(ON);
    }
    if (buttons & BUTTON_DOWN) {
      lcd.print(BUTTON_DOWN);
      Serial.print(buttons);
      lcd.setBacklight(ON);
    }
    if (buttons & BUTTON_LEFT) {
      lcd.print(BUTTON_LEFT);
      Serial.print(buttons);
      lcd.setBacklight(ON);
    }
    if (buttons & BUTTON_RIGHT) {
       lcd.print(BUTTON_RIGHT);
       Serial.print(buttons);
       lcd.setBacklight(ON);
    }
    if (buttons & BUTTON_SELECT) {
      lcd.print(BUTTON_SELECT);
      Serial.print(buttons);
      lcd.setBacklight(ON);
    }
  
}
