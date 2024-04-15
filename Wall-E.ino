#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <SharpDistSensor.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>
#include <Servo.h>
#include <SPI.h>


// #define cs 2
// #define dc 3
// #define rst 4
// #define mosi A4
// #define sclk A5

const int stopPin = 5;
const int playPin = 6;
const int skipPin = 7;
const int potentiometer = A1;

// const byte sensorPin = A0;

// const int LeftEyeServoPin = 8;
// const int RightEyeServoPin = 9;
// const int WristServoPin = 10;
// const int ArmServoPin = 11;

// // Servos
// Servo LeftEyeServo;
// Servo RightEyeServo;
// Servo WristServo;
// Servo ArmServo;

// DFPlayer Mini
int playRead = 0;
int skipRead = 0;
int stopRead = 0;
int currentTrack = 1;

SoftwareSerial mySoftwareSerial(12, 13);
DFRobotDFPlayerMini mp3module;

const int numOfSongs = 10;

// // Sharp IR Sensor
// const byte medianFilterWindowSize = 5;
// SharpDistSensor sensor(sensorPin, medianFilterWindowSize);

// int sampleCounter = 0;
// const int threshold = 390;

// enum State
// {
//   INIT,
//   FIRST_DROP,
//   FIRST_PEAK,
//   SECOND_DROP,
//   SECOND_PEAK
// };

// State currentState = INIT;

// OLED Screen
// Adafruit_SSD1331 display = Adafruit_SSD1331(cs, dc, mosi, sclk, rst);

// const unsigned char epd_bitmap_New_Project [] PROGMEM = {
// 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21, 0x08, 0x00, 0x00, 0x00, 
// 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x10, 0x01, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 	0x00, 0x00, 0x00, 0x09, 0x20, 0x01, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x09, 
// 	0x21, 0x01, 0xd0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x02, 0x00, 0x00, 0x00, 
// 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0xc4, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 	0x00, 0x00, 0x08, 0x1f, 0xf0, 0x21, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x3c, 
// 	0x78, 0x41, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x30, 0x19, 0x80, 0x00, 0x00, 
// 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x1c, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 	0x00, 0x00, 0x00, 0x60, 0x0c, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x60, 
// 	0x0d, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x0c, 0x00, 0x00, 0x00, 
// 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x1c, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 	0x00, 0x00, 0x03, 0x30, 0x19, 0x80, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x3c, 
// 	0x78, 0x41, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x1f, 0xf0, 0x20, 0x00, 0x00, 
// 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0xc4, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 	0x00, 0x00, 0x00, 0x80, 0x02, 0x00, 0xd0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x09, 
// 	0x21, 0x01, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x20, 0x00, 0x00, 0x00, 
// 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 	0x00, 0x00, 0x00, 0x21, 0x08, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 	0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 
// 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 	0x00, 0x00, 0x40, 0x00, 0x00, 0xff, 0xe3, 0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe1, 0xf0, 0x00, 
// 	0x00, 0xff, 0xe3, 0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe0, 0x00, 0x00, 0x00, 0xff, 0xe3, 0xc7, 
// 	0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe1, 0xf0, 0x00, 0x00, 0xff, 0xe3, 0xc7, 0x8f, 0x1e, 0x3c, 0x78, 
// 	0xf1, 0xe0, 0x50, 0x00, 0x00, 0xff, 0xe3, 0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe1, 0xf0, 0x00, 
// 	0x00, 0xff, 0xe3, 0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe0, 0x00, 0x00, 0x00, 0xff, 0xe3, 0xc7, 
// 	0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe1, 0xf0, 0x00, 0x00, 0xff, 0xe3, 0xc7, 0x8f, 0x1e, 0x3c, 0x78, 
// 	0xf1, 0xe0, 0xd0, 0x00, 0x00, 0xff, 0xe3, 0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe1, 0x70, 0x00, 
// 	0x00, 0xff, 0xe3, 0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe0, 0x00, 0x00, 0x00, 0xff, 0xe3, 0xc7, 
// 	0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe1, 0xf0, 0x00, 0x00, 0xff, 0xe3, 0xc7, 0x8f, 0x1e, 0x3c, 0x78, 
// 	0xf1, 0xe1, 0x10, 0x00, 0x00, 0xff, 0xe3, 0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe1, 0xd0, 0x00, 
// 	0x00, 0xff, 0xe3, 0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe0, 0x00, 0x00, 0x00, 0xff, 0xe3, 0xc7, 
// 	0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe1, 0xf0, 0x00, 0x00, 0xff, 0xe3, 0xc7, 0x8f, 0x1e, 0x3c, 0x78, 
// 	0xf1, 0xe1, 0x50, 0x00, 0x00, 0xff, 0xe3, 0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe1, 0x50, 0x00, 
// 	0x00, 0xff, 0xe3, 0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe0, 0x00, 0x00, 0x00, 0xff, 0xe3, 0xc7, 
// 	0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe0, 0x00, 0x00, 0x00, 0xff, 0xe3, 0xc7, 0x8f, 0x1e, 0x3c, 0x78, 
// 	0xf1, 0xe1, 0xf0, 0x00, 0x00, 0xff, 0xe3, 0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe1, 0x00, 0x00, 
// 	0x00, 0xff, 0xe3, 0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe1, 0x00, 0x00, 0x00, 0xff, 0xe3, 0xc7, 
// 	0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe0, 0x00, 0x00, 0x00, 0xff, 0xe3, 0xc7, 0x8f, 0x1e, 0x3c, 0x78, 
// 	0xf1, 0xe0, 0xf0, 0x00, 0x00, 0xff, 0xe3, 0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe1, 0x00, 0x00, 
// 	0x00, 0xff, 0xe3, 0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe0, 0xf0, 0x00, 0x00, 0xff, 0xe3, 0xc7, 
// 	0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe0, 0x00, 0x00, 0x00, 0xff, 0xe3, 0xc7, 0x8f, 0x1e, 0x3c, 0x78, 
// 	0xf1, 0xe1, 0xf0, 0x00, 0x00, 0xff, 0xe3, 0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe1, 0x00, 0x00, 
// 	0x00, 0xff, 0xe3, 0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
// 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
// };

// const unsigned int bitmapWidth = 96;
// const unsigned int bitmapHeight = 64;
// const unsigned int bitmapSize = bitmapWidth * bitmapHeight / 8; 

void setup() {
  Serial.begin(9600);
  mySoftwareSerial.begin(9600);

  // LeftEyeServo.write(90);
  // RightEyeServo.write(90);
  // WristServo.write(90);
  // ArmServo.write(90);

  pinMode(playPin, INPUT_PULLUP);
  pinMode(skipPin, INPUT_PULLUP);
  pinMode(stopPin, INPUT_PULLUP);
 
  Serial.println(F("Initializing DFPlayer ..."));

  if (!mp3module.begin(mySoftwareSerial)) {
    Serial.println("Unable to connect to module!");
    Serial.println("Check cable connections and");
    Serial.println("make sure SD Card is inserted");
    while (1);
  }

  Serial.println("Succesfully connected to DFPlayer Mini");

  mp3module.setTimeOut(500);
  mp3module.EQ(DFPLAYER_EQ_NORMAL);
  mp3module.outputDevice(DFPLAYER_DEVICE_SD);

  // Initialize OLED display with SPI
  // display.begin();
  // display.setRotation(0);                                       
  // display.fillRect(0, 0, display.width(), display.height(), 0); // Fill with black

  // // Draw bitmap
  // for (unsigned int y = 0; y < bitmapHeight; y++) {
  //   for (unsigned int x = 0; x < bitmapWidth; x++) {
  //     unsigned int index = y * (bitmapWidth / 8) + (x / 8);
  //     unsigned int bit = 7 - (x % 8);
  //     unsigned char pixel = pgm_read_byte(&epd_bitmap_New_Project[index]);
  //     if (pixel & (1 << bit))
  //       display.drawPixel(x, y, 0XFFE0); // Draw yellow pixel
  //   }
  // }

  delay(100);
}

void loop() {
  int volume = map(analogRead(potentiometer), 5, 1010, 0, 30);
  mp3module.volume(volume);

  playRead = digitalRead(playPin);
  skipRead = digitalRead(skipPin);
  stopRead = digitalRead(stopPin);

  const int notPlaying = 512;
  const int playing = 513;
  const int paused = 514;

//   // Wave Detector
//   if(mp3module.readState() == notPlaying || mp3module.readState() == paused) {
//     unsigned int distance = sensor.getDist();
//     switch (currentState) {
//       case INIT:
//         if (distance < threshold) 
//           currentState = FIRST_DROP;
//         break;
  
//       case FIRST_DROP:
//         if (distance > threshold) 
//           currentState = FIRST_PEAK;
//         break;
  
//       case FIRST_PEAK:
//         if (distance < threshold) 
//           currentState = SECOND_DROP;
//         break;
  
//       case SECOND_DROP:
//         if (distance > threshold) 
//           currentState = SECOND_PEAK;
//         break;
  
//       case SECOND_PEAK:
//         if (distance < threshold) {
//           // Pattern detected
//           waveArm();
//           currentState = INIT;
//         }
//         break;
//       }

//       if (sampleCounter == 30) {
//         currentState = INIT;
//         sampleCounter = 0;
//       } 

//       else 
//         sampleCounter++;
//   }

  // Music Player
  if (stopRead == LOW) {
    Serial.println("Stopping track " + String(currentTrack));
    mp3module.stop();
    delay(500);
  }

  else if (playRead == LOW) {
    if (mp3module.readState() == notPlaying) {
      Serial.println("Playing track " + String(currentTrack));
      // mp3module.playFolder(1, currentTrack);
      mp3module.play(currentTrack);
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

    delay(500);
  }

  else if (skipRead == LOW) {
    currentTrack = (currentTrack++ % numOfSongs) + 1;
    if (mp3module.readState() == playing || mp3module.readState() == paused)
      mp3module.play(currentTrack);
    Serial.println("Skipping to track " + String(currentTrack));
    delay(500);
  }

  // Serial.println(String(volume));
  Serial.println(String(mp3module.readState()));
  Serial.println("Button State : " + String(stopRead));
  Serial.println("Volume : " + String(volume));
}

// void waveArm() {
//   mp3module.stop();
	
//   ArmServo.write(90+45);
//   delay(750);
//   WristServo.write(90+50);
//   delay(200);
//   WristServo.write(90);
//   delay(200);
//   WristServo.write(90+50);
//   delay(200);
//   WristServo.write(90);
//   delay(200);
//   ArmServo.write(90);
//   delay(1000);

//   int sayWallEChance = random(1 , 100);
//   if(sayWallEChance <= 20) 
//     mp3module.playFolder(2, 1);

//   else {
//     int randomVoiceLine = random(2, 19);
//     mp3module.playFolder(2, randomVoiceLine);
//   }

//   delay(1500);
//   moveEyes();
// }

// void moveEyes() {
//   LeftEyeServo.write(90+20);
//   RightEyeServo.write(90+20);
//   delay(200);
//   LeftEyeServo.write(90);
//   RightEyeServo.write(90);
//   delay(200);
//   LeftEyeServo.write(90+20);
//   RightEyeServo.write(90+20);
//   delay(200);
//   LeftEyeServo.write(90);
//   RightEyeServo.write(90);
// }
