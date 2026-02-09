#include <SPI.h>            //Library for SPI communication
#include <Wire.h>           //Library for I2C communication

#define sensor    A0        //Define the analog pin for the gas sensor

int gasLevel  = 0;          //Variable to store gas sensor value
String quality ="";         //Variable to store air quality description                                             

void air_sensor()           //Function to read gas sensor value and determine air quality
{
  gasLevel = analogRead(sensor);

  if(gasLevel<181){
    quality = "  GOOD!";
  }
  else if (gasLevel >=181 && gasLevel<225){
    quality =  "  Poor!";
  }
  else if (gasLevel >=225 && gasLevel<300){
    quality  = "Very bad!";
  }
    else if (gasLevel >=300 && gasLevel<350){
    quality  = "R.I.P";
  }
    else{
    quality = " Toxic";   
}
  
  Serial.println(gasLevel);         //Print the gas sensor value to the Serial Monitor
  Serial.println(quality);          //Print the air quality description to the Serial Monitor, open serial montior using tools or Ctrl+Shift+M on Arduino IDE
}

void setup() {                      //Initialize serial communication and set the sensor pin as input
  Serial.begin(9600);
  pinMode(sensor,INPUT);  
}

void loop() {
delay(1000);
air_sensor();
}