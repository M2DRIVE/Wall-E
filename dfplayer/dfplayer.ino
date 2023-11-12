#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h" 

SoftwareSerial mySoftwareSerial(4, 5);
DFRobotDFPlayerMini mp3module;

void setup(){
  Serial.begin(9600);
  mySoftwareSerial.begin(9600);
  
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!mp3module.begin(mySoftwareSerial)) { 
    Serial.println("Unable to connect to module!");
    Serial.println("Check cable connections and");
    Serial.println("make sure SD Card is inserted");
    while(1);
  }
  
  Serial.println("Succesfully connected to DFPlayer Mini");
  
  mp3module.setTimeOut(500); 
  mp3module.volume(25);
  mp3module.EQ(DFPLAYER_EQ_NORMAL); 
  mp3module.outputDevice(DFPLAYER_DEVICE_SD); 
  
  delay(100);
}

void loop(){

  mp3module.play(1); 
  delay(5000);
}