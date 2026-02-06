#include <SPI.h>
#include <Wire.h>

#define sensor    A0 

int gasLevel  = 0;       
String quality =""; 

void air_sensor()
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
  
  Serial.println(gasLevel);
~  Serial.println(quality); 
}

void setup() {
  Serial.begin(9600);
  pinMode(sensor,INPUT);  
}

void loop() {
delay(1000);
air_sensor();
}