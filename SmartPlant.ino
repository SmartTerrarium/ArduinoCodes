// author: Aubrey Ashton
// last change: 4/13/2020

#include <Wire.h>
#include <LiquidCrystal.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>

const int Solenoid1Pin = 3;
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();
int photocellPin = A2;     
int photocellReading;     
int soilmoisturePin = A0;
int tempPin = A1;
float SoilMoisture = 0; // actual soil moisture values

// to conveniently change backlight for LCD:
#define ON 0x1
#define OFF 0x0

void setup() {  
  Serial.begin(9600); 

  // LCD setup:
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  lcd.clear();

  // Solenoid Setup:
  pinMode(Solenoid1Pin, OUTPUT); //solenoid pin
  digitalWrite(Solenoid1Pin, LOW); //Make sure the valve is off
}

// Relevant to LCD:
  // DisplayCase keeps track of how many times left/right buttons have been pressed
  int DisplayCase = 0;
  // Page keeps track of how many times up/down has been pressed
  int Page = 0;

void loop() {
// Soil Moisture Sensor 1:
    for (int i = 0; i <= 100; i++) 
   { 
     SoilMoisture = SoilMoisture + analogRead(soilmoisturePin); 
     delay(1); 
   } 
   
   // the average of the SoilMoisture readings is taken by dividing the variable by the number of samples (100)
   SoilMoisture = SoilMoisture/100.0; 
   
   Serial.println(SoilMoisture); //the reading is printed to the Serial Monitor
   

// Temperature Sensor:

   int reading = analogRead(tempPin);  
   // converting that reading to voltage, for 3.3v arduino use 3.3
   float voltage = reading * 5;
   voltage /= 1024.0; 
   float temperatureC = (voltage - 0.5) * 100 ;
   float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
   Serial.print(temperatureF); Serial.println(" degrees F");


// Solenoid for Plant 1:
 /*   digitalWrite(Solenoid1Pin, HIGH);
    //Serial.print("Trying to open!");
    delay(2000);
    digitalWrite(Solenoid1Pin, LOW);
    //Serial.print("Stopping...");
    delay(2000);*/

// Light Sensor:
    photocellReading = analogRead(photocellPin);  
        if (photocellReading < 10) {
        Serial.println(" - Dark");
      } else if (photocellReading < 200) {
        Serial.println(" - Dim");
      } else if (photocellReading < 500) {
        Serial.println(" - Light");
      } else if (photocellReading < 800) {
        Serial.println(" - Bright");
      } else {
        Serial.println(" - Very bright");
      }
     // delay(1000);

// LCD Display Code:
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
    Serial.print(DisplayCase);  
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
delay(1000);

}
