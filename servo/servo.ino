#include <Servo.h>

Servo LeftEyeServo;
Servo RightEyeServo;
Servo WristServo;
Servo ArmServo;

const int LeftEyeServoPin = 0;
const int RightEyeServoPin = 0;
const int WristServoPin = 0;
const int ArmServoPin = 0;

void setup() {
  LeftEyeServo.attach(LeftEyeServoPin);
  RightEyeServo.attach(RightEyeServoPin);
  WristServo.attach(WristServoPin);
  ArmServo.attach(ArmServoPin);
  
  LeftEyeServo.write(90);
  RightEyeServo.write(90);
  WristEyeServo.write(90);
  ArmEyeServo.write(90);
}

void loop() {

}