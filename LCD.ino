// original source: Aubrey Ashton
// last change: 4/4/2020

#include <LiquidCrystal.h>
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

#define ON 0x1
#define OFF 0x0

void setup() {
  // Debugging output
  Serial.begin(9600);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  lcd.clear();

  lcd.setCursor(0,0);
    lcd.print("Team 14, Y'all!!");
}

// DisplayCase keeps track of how many times left/right buttons have been pressed
int DisplayCase = 0;
// Page keeps track of how many times up/down has been pressed
int Page = 0;

void loop() {
  uint8_t buttons = lcd.readButtons();

// I made four display cases:
// 0: Welcome Screen
// 1: Temp Screen
// 2: Light Screen
// 3: Soil Moisture
//    - under Soil Moisture, there are three cases:
//    - Plant 1
//    - Plant 2
//    - Plant 3


// Navigating left/right will change the value for DisplayCase: 
  if (buttons & BUTTON_RIGHT) {
       DisplayCase = DisplayCase +1;
  //Serial.print(DisplayCase);  
  }
  if (buttons & BUTTON_LEFT) {
         DisplayCase = DisplayCase -1;
  //Serial.print(DisplayCase);  
  }

// Navigating up/down will change the value for Page, 
// which will change which plant's soil moisture we read
  if (buttons & BUTTON_DOWN) {
         Page = Page + 1;
  //Serial.print(Page);  
  }
  if (buttons & BUTTON_UP) {
         Page = Page - 1;
  //Serial.print(Page);  
  }

// Because we want continuous looping (and no unexpected cases) anytime DisplayCase or Page 
// go outside their expected ranges, we set them to the other end of their ranges.
// EX: if left is pressed on the leftmost case, we will go to the rightmost case.
  if (DisplayCase < 0){
    DisplayCase = 3;
  }
  if (DisplayCase > 3){
    DisplayCase = 0;
  }

// Again, we want continuous looping for Page:
  if (Page < 0){
    Page = 2;
  }
  if (Page > 2){
    Page = 0;
  }

  switch(DisplayCase){
    
    // Welcome Screen:
    case 0:
      lcd.setCursor(0, 0);
      lcd.print("Howdy, Smart    ");
      lcd.setCursor(0, 1);
      lcd.print("Terrarium User! ");
    break;

    // Temperature:
    case 1:
      lcd.setCursor(0, 0);
      lcd.print("Internal Temp:  ");
      lcd.setCursor(0, 1);
      lcd.print("Warm            ");
      break;

    // Light Reading:
    case 2:
      lcd.setCursor(0, 0);
      lcd.print("Ambient Light:  ");
      lcd.setCursor(0, 1);
      lcd.print("Bright          ");
      break;

    // Soil Moisture:
    case 3:
      switch(Page){
        case 0:
        lcd.setCursor(0, 0);
        lcd.print("Soil Moisture:  ");
        lcd.setCursor(0, 1);
        lcd.print("Plant 1: Wet    ");
        break;
        case 1:
        lcd.setCursor(0, 0);
        lcd.print("Soil Moisture:  ");
        lcd.setCursor(0, 1);
        lcd.print("Plant 2: Dry    ");
        break;
        case 2:
        lcd.setCursor(0, 0);
        lcd.print("Soil Moisture:  ");
        lcd.setCursor(0, 1);
        lcd.print("Plant 3: Good   ");
        break;
      }
      break;
    
  }
}
