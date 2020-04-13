// original source: Saeed Hosseini @ Electropeak
// changed by Aubrey Ashton
// last change: 4/13/2020

int SensorPin = A0; 
float SoilMoisture = 0; 

void setup() { 
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
 SoilMoisture = SoilMoisture/100.0; 
 
 Serial.println(SoilMoisture); //the reading is printed to the Serial Monitor
 delay(30); // delay 30ms
}
