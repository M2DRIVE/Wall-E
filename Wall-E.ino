#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h" 

const int playPin = 13;
const int skipPin = 12;
int playRead = 0;
int skipRead = 0;
int currentTrack = 1;
boolean isPlaying = false;

SoftwareSerial mySoftwareSerial(4, 5);
DFRobotDFPlayerMini mp3module;

void setup() {  
  Serial.begin(9600);
  mySoftwareSerial.begin(9600);
  
  pinMode(playPin, INPUT);
  pinMode(skipPin, INPUT);

  Serial.println(F("Initializing DFPlayer ..."));
  
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

void loop() {
  playRead = digitalRead(playPin);   
  skipRead = digitalRead(skipPin);
  
  if (playRead == HIGH) {
    if (!isPlaying) {
      Serial.println("Playing track " + String(currentTrack));
      mp3module.play(currentTrack);
    }

    else {
      Serial.println("Stopping track " + String(currentTrack));
      mp3module.reset();
    }

    isPlaying = !isPlaying; 
    delay(500);
  } 
  
  else if (skipRead == HIGH) {
    currentTrack = (currentTrack++ % 3) + 1;
    if(isPlaying)
      mp3module.play(currentTrack);
    Serial.println("Skipping to track " + String(currentTrack));
  }
}