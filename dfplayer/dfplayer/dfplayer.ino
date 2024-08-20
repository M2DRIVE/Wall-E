#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h" 

SoftwareSerial mySoftwareSerial(12, 13);
DFRobotDFPlayerMini mp3module;

const int stopPin = 2;
const int playPin = 3;
const int skipPin = 4;
const int potentiometer = A1;

int playRead = 0;
int skipRead = 0;
int stopRead = 0;
int currentTrack = 1;
int numOfSongs;
int* shufflePlay; 
bool stopPressed = true;

void setup(){
  Serial.begin(9600);
  mySoftwareSerial.begin(9600);
  
  pinMode(playPin, INPUT_PULLUP);
  pinMode(skipPin, INPUT_PULLUP);
  pinMode(stopPin, INPUT_PULLUP);

  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!mp3module.begin(mySoftwareSerial)) { 
    Serial.println("Unable to connect to module!");
    Serial.println("Check cable connections and");
    Serial.println("make sure SD Card is inserted");
    while(1);
  }
  
  Serial.println("Succesfully connected to DFPlayer Mini");

  mp3module.setTimeOut(500); 
  mp3module.EQ(DFPLAYER_EQ_NORMAL); 
  mp3module.outputDevice(DFPLAYER_DEVICE_SD); 
  numOfSongs = mp3module.readFileCountsInFolder(1);

  delay(100);
  numOfSongs = mp3module.readFileCountsInFolder(1);
  Serial.println(numOfSongs);
  delay(100);

  randomSeed(analogRead(A2));

  shufflePlay = new int[numOfSongs];
  for(int i = 0; i < numOfSongs; i++) 
    shufflePlay[i] = i+1;

  //  for (int i = 0; i < numOfSongs; i++) {
  //   Serial.print("shufflePlay[");
  //   Serial.print(i);
  //   Serial.print("] = ");
  //   Serial.println(shufflePlay[i]);
  // }

  for (int i = 5; i < numOfSongs; i++) {
    int r = i + random(numOfSongs - i); 
    int temp = shufflePlay[i];
    shufflePlay[i] = shufflePlay[r];
    shufflePlay[r] = temp;
  }

  //  for (int i = 0; i < numOfSongs; i++) {
  //   Serial.print("shufflePlay[");
  //   Serial.print(i);
  //   Serial.print("] = ");
  //   Serial.println(shufflePlay[i]);
  // }
}

void loop(){
  // int volume = map(analogRead(potentiometer), 5, 1010, 0, 30);
  // volume = constrain(volume, 0, 30);
  // mp3module.volume(volume);
  mp3module.volume(0);

  playRead = digitalRead(playPin);
  skipRead = digitalRead(skipPin);
  stopRead = digitalRead(stopPin);

  const int notPlaying = 512;
  const int playing = 513;
  const int paused = 514;

  if (stopRead == LOW) {
    Serial.println("Stopping track " + String(currentTrack));
    mp3module.stop();
    stopPressed = true;
    delay(500);
  }

  else if (playRead == LOW) {
    if (mp3module.readState() == notPlaying) {
      Serial.println("Playing track " + String(currentTrack));
      mp3module.playFolder(1, shufflePlay[currentTrack-1]);
    } 
    // Pause Conditions
    else {
      if (mp3module.readState() == playing)
      {
        mp3module.pause();
        Serial.println("Pausing track " + String(currentTrack));
      }

      else if (mp3module.readState() == paused)
      {
        mp3module.start();
        Serial.println("Resuming track " + String(currentTrack));
      }
    }

    mp3module.readState();
    stopPressed = false;
    delay(500);
  }

  // Skip conditions
  else if (skipRead == LOW) {
    currentTrack = (currentTrack++ % numOfSongs) + 1;
    if (mp3module.readState() == playing || mp3module.readState() == paused) {
      mp3module.playFolder(1, shufflePlay[currentTrack-1]);
    }
    Serial.println("Skipping to track " + String(currentTrack));
    delay(500);
  }

  if(mp3module.readState() == notPlaying && !stopPressed) {
    currentTrack = (currentTrack++ % numOfSongs) + 1;
    mp3module.playFolder(1, shufflePlay[currentTrack-1]);
    Serial.println("Skipping to track " + String(currentTrack));
  }
  Serial.println("Current Track : " +String(currentTrack) + "  |  State : " + String(mp3module.readState()) + "  |  Stop Pressed : " + String(stopPressed));
}
