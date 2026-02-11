#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeMonoOblique9pt7b.h>
#define SCREEN_WIDTH 128 
#define  SCREEN_HEIGHT 64 

#define OLED_RESET     4  // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH,  SCREEN_HEIGHT, &Wire, OLED_RESET);

#define sensor    A0 

int gasLevel  = 0;         //int variable for gas level
String quality =""; 


void air_sensor()           //Function to read gas sensor value and determine air quality
{
  gasLevel = analogRead(sensor);
  
  if(gasLevel<150){
    quality = "  GOOD!";
  }
  else if(gasLevel >=150 && gasLevel<180){
    quality = "Average";
  }
  else if (gasLevel >=181 && gasLevel<225){
    quality =  "  BAD!";
  }
  else if (gasLevel >=225 && gasLevel<300){
    quality  = "Very BAD!";
  }
    else if (gasLevel >=300 && gasLevel<350){
    quality  = "R.I.P";
  }
    else{
    quality = " Toxic";   
}
  
  display.setTextColor(WHITE);
  display.setTextSize(1);  
  display.setCursor(1,5);
  display.setFont();
  display.println("Air Quality:");
  display.setTextSize(1);
  display.setCursor(20,23);
  display.setFont(&FreeMonoOblique9pt7b);
  display.println(quality);
  display.println(gasLevel);  
  Serial.println(gasLevel);         //Print the gas sensor value to the Serial Monitor
  Serial.println(quality);          //Print the air quality description to the Serial Monitor, open serial montior using tools or Ctrl+Shift+M on Arduino IDE
}

void setup() {
  Serial.begin(9600);
  pinMode(sensor,INPUT);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c)) { // Address  0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
}
  display.clearDisplay();
  display.setTextColor(WHITE);
  
  display.setTextSize(1);
  display.setCursor(23, 20);
  display.println("Hello World");
  display.display();
  delay(1200);
  display.clearDisplay();
  
  display.setTextSize(2);
  display.setCursor(20, 20);
  display.println("by hk");
  display.display();
  delay(1000);
  display.clearDisplay();  

  display.setTextSize(1);
  display.setCursor(20, 20);
  display.println("Initialising...");
  display.display();
  delay(10000);
  display.clearDisplay();
}

void loop() {
delay(1000);
display.clearDisplay();
air_sensor();
display.display();  
}
