#include <Servo.h>

Servo WristServo;
Servo ArmServo;

const int WristServoPin = 11;

const int angle = 180;

void setup() {
  Serial.begin(9600);
  WristServo.attach(WristServoPin);
  WristServo.write(angle);
}

void loop() {

}