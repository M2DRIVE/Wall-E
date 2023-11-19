#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h" 

const int playPin = 13;
const int skipPin = 12;
const int pausePin = 11;
const int potentiometer = 5;

int playRead = 0;
int skipRead = 0;
int pauseRead = 0;

int currentTrack = 1;

SoftwareSerial mySoftwareSerial(4, 5);
DFRobotDFPlayerMini mp3module;

void setup() {  
  Serial.begin(9600);
  mySoftwareSerial.begin(9600);
  
  pinMode(playPin, INPUT);
  pinMode(skipPin, INPUT);
  pinMode(pausePin, INPUT);

  Serial.println(F("Initializing DFPlayer ..."));
  
  if (!mp3module.begin(mySoftwareSerial)) { 
    Serial.println("Unable to connect to module!");
    Serial.println("Check cable connections and");
    Serial.println("make sure SD Card is inserted");
    while(1);
  }
  
  Serial.println("Succesfully connected to DFPlayer Mini");
  
  mp3module.setTimeOut(500); 
  //mp3module.volume(17);  
  mp3module.EQ(DFPLAYER_EQ_NORMAL); 
  mp3module.outputDevice(DFPLAYER_DEVICE_SD);
  
  delay(100);
}

void loop() {
  int volume = map(analogRead(potentiometer), 5, 1010, 0, 30);
  mp3module.volume(volume);

  playRead = digitalRead(playPin);   
  skipRead = digitalRead(skipPin);
  pauseRead = digitalRead(pausePin);

  // 512 Not Playing
  // 513 Playing
  // 514 Paused

  if (playRead == HIGH) {
    if (mp3module.readState() == 512) {
      Serial.println("Playing track " + String(currentTrack));
      mp3module.play(currentTrack);
    }

    else {
      Serial.println("Stopping track " + String(currentTrack));
      mp3module.stop();
    }

    delay(500);
  } 
  
  else if (skipRead == HIGH) {
    currentTrack = (currentTrack++ % 3) + 1;   
    if(mp3module.readState() == 513 || mp3module.readState() == 514)
      mp3module.play(currentTrack);
    Serial.println("Skipping to track " + String(currentTrack));   
    delay(500);
  }

  else if (pauseRead == HIGH) {
    // Consider switching to a switch statement
    if(mp3module.readState() == 512) {
      mp3module.play(currentTrack);
      Serial.println("Playing track " + String(currentTrack));
    }

    else if(mp3module.readState() == 513) {
      mp3module.pause();
      Serial.println("Pausing track " + String(currentTrack));
    }

    else if(mp3module.readState() == 514) {
      mp3module.start();
      Serial.println("Resuming track " + String(currentTrack));
    }

    delay(500);
  }
  
  //Serial.println(String(volume));
  Serial.println(String(mp3module.readState()));
}