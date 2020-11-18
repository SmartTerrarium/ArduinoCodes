#include <Wire.h>
#define tempSensor A0
#define photocellPin A1
#define soilSensor A2
float sensorValue = 0;
float soilValue = 0;
float photocellReading = 0;
const int solenoidPin1 = 4;
const int solenoidPin2 = 3;
//const int solenoidPin3 = 5;
const int soilPin = 2;


void setup() {
  Serial.begin(9600); //Just for testing 
  pinMode(solenoidPin1, OUTPUT); //solenoid pin
  digitalWrite(solenoidPin1, LOW); //Make sure the valve is off
  pinMode(solenoidPin2, OUTPUT); //solenoid pin
  digitalWrite(solenoidPin2, LOW); //Make sure the valve is off
  //pinMode(solenoidPin3, OUTPUT); //solenoid pin
  //digitalWrite(solenoidPin3, LOW); //Make sure the valve is off
  pinMode(soilPin, OUTPUT); //solenoid pin
  digitalWrite(soilPin, LOW); //Make sure the valve is off
}

void loop() {
 
 //SOLENOIDS
    digitalWrite(solenoidPin1, HIGH);
    Serial.println("Opening Solenoid - Plant 1! \n");
    delay(6000);
    digitalWrite(solenoidPin1, LOW);
    Serial.print("Closing Solenoid - Plant 1... \n");
    delay(2000);

    digitalWrite(solenoidPin2, HIGH);
    Serial.print("Opening Solenoid - Plant 2! \n");
    delay(6000);
    digitalWrite(solenoidPin2, LOW);
    Serial.print("Closing Solenoid - Plant 2... \n");
    delay(2000);

/* AS THE THIRD SOLENOID HAS A LEAK, THIS PORTION OF THE TEST CODE IS NOT USED
  digitalWrite(solenoidPin3, HIGH);
    Serial.print("Opening Solenoid - Plant 3! \n");
    delay(6000);
    digitalWrite(solenoidPin3, LOW);
    Serial.print("Closing Solenoid - Plant 3... \n");
    delay(2000);

    */
    
//TEMPERATURE
     int reading = analogRead(tempSensor);  
 // converting that reading to voltage, for 5v arduino use 5
 Serial.print("Reading temperature... \n");
 float voltage = reading * 5;
 voltage /= 1024.0; 
 float temperatureC = (voltage - 0.5) * 100 ;
 float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
 Serial.print(temperatureF); Serial.println(" degrees F \n");
delay(4000);

//LIGHT 
photocellReading = analogRead(photocellPin);  
 
  Serial.print("Reading light sensor... \n");
  //Serial.println(photocellReading);     // the raw analog reading
 
  if (photocellReading < 30) {
    Serial.println("Plant is not in the sun \n");
  } else if (photocellReading > 30) {
    Serial.println("Plant is in the sun \n");
  }
  delay(4000);
  */
  for(int j = 0; j<=10; j++){
// SOIL 
digitalWrite(soilPin, HIGH);
       delay(1000);
Serial.print("Reading Soil Moisture - Plant 1 \n");
for (int i = 0; i <= 100; i++) 
 { 
   soilValue = soilValue + analogRead(soilSensor); 
   delay(10); 
 } 
 soilValue = soilValue/100.0; 
 Serial.print(soilValue); 
 Serial.print(" in mV. \n");
digitalWrite(soilPin, LOW);
 delay(2000);
  }
}
