#include <SoftwareSerial.h>
#include <DFPlayerMini_Fast.h>

SoftwareSerial mySoftwareSerial(12, 13); // RX, TX
DFPlayerMini_Fast mp3module;

const int stopPin = 2;
const int playPin = 3;
const int skipPin = 4;
const int voicePin = 5;

int playRead = 0;
int skipRead = 0;
int stopRead = 0;
int voiceRead = 0;
int currentTrack = 1;
int numOfSongs;

void setup(){
  Serial.begin(9600);
  mySoftwareSerial.begin(9600);
  mp3module.begin(mySoftwareSerial);

  pinMode(playPin, INPUT_PULLUP);
  pinMode(skipPin, INPUT_PULLUP);
  pinMode(stopPin, INPUT_PULLUP);
  pinMode(voicePin, INPUT_PULLUP);

  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!mp3module.begin(mySoftwareSerial, false)) { 
    Serial.println("Unable to connect to module!");
    Serial.println("Check cable connections and");
    Serial.println("make sure SD Card is inserted");
    while(1);
  }
  
  Serial.println("Successfully connected to DFPlayer Mini");

  numOfSongs = mp3module.numTracksInFolder(1);

  delay(100);
  numOfSongs = mp3module.numTracksInFolder(1);
  Serial.println(numOfSongs);
  mp3module.sleep();
  delay(1000);
}

void loop(){
  int volume = 15;
  mp3module.volume(volume);

  playRead = digitalRead(playPin);
  skipRead = digitalRead(skipPin);
  stopRead = digitalRead(stopPin);
  voiceRead = digitalRead(voicePin);

  if (stopRead == LOW) {
    Serial.println("Stopping track " + String(currentTrack));
    mp3module.stop();
    delay(100);
    mp3module.sleep();
    delay(500);
  }

  else if (playRead == LOW) {
    if (!mp3module.isPlaying()) {
      Serial.println("Playing track " + String(currentTrack));
      mp3module.wakeUp();
      mp3module.playFolder(1, currentTrack);
    } 
    // Pause Conditions
    else {
      if (mp3module.isPlaying())
      {
        mp3module.pause();
        Serial.println("Pausing track " + String(currentTrack));
      }

      else 
      {
        mp3module.resume();
        Serial.println("Resuming track " + String(currentTrack));
      }
    }

    delay(500);
  }

  else if (skipRead == LOW) {
    currentTrack = (currentTrack++ % numOfSongs) + 1;
    if (mp3module.isPlaying()) {
      mp3module.playFolder(1, currentTrack);
    }
    Serial.println("Skipping to track " + String(currentTrack));
    delay(500);
  }

  else if (voiceRead == LOW) {
    mp3module.wakeUp();
    int sayWallEChance = random(1 , 100);
    if(sayWallEChance <= 20) 
        mp3module.playFolder(2, 1);

    else {
        int randomVoiceLine = random(2, 19);
        mp3module.playFolder(2, randomVoiceLine);
    }
    delay(500);
  }

  Serial.println("Current Track : " +String(currentTrack) + "  |  State : " + String(mp3module.isPlaying()));
}
