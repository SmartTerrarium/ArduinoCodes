// original source : http://kookye.com/2019/08/28/arduino-lesson-tmp36/
// changed by Aubrey Ashton
// last change: 4/13/2020

int sensorPin = A0;

void setup() { 
 Serial.begin(9600); 
}

void loop() {
  
 int reading = analogRead(sensorPin);  
 // converting that reading to voltage, for 3.3v arduino use 3.3
 float voltage = reading * 3.3;
 voltage /= 1024.0; 
 float temperatureC = (voltage - 0.5) * 100 ;
 float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
 Serial.print(temperatureF); Serial.println(" degrees F");
 delay(1000); //waiting a second
}
