// original source: Saeed Hosseini @ Electropeak
// changed by Aubrey Ashton
// last change: 3/17/2020

#define SensorPin A0 //defining sensor input to board 
float SoilMoisture = 0; // initializing a value of zero for the measured moisture levels

void setup() { 
//exchange messages with the Serial Monitor at a data rate of 9600 bits per second
 Serial.begin(9600); 
}


void loop() {
// in the loop below, 100 samples are taken with 1ms of delay between each sample and added to the variable named SoilMoisture
  for (int i = 0; i <= 100; i++) 
 { 
   SoilMoisture = SoilMoisture + analogRead(SensorPin); 
   delay(1); 
 } 
 
 // the average of the SoilMoisture readings is taken by dividing the variable by the number of samples (100)
 sensorValue = sensorValue/100.0; 
 
 Serial.println(sensorValue); //the reading is printed to the Serial Monitor
 delay(30); // delay 30ms
}
