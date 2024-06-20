#include <Servo.h>

Servo LeftEyeServo;
Servo RightEyeServo;
// Servo WristServo;
// Servo ArmServo;

const int LeftEyeServoPin = 9;
const int RightEyeServoPin = 10;
// const int WristServoPin = 0;
// const int ArmServoPin = 0;

void setup() {
  LeftEyeServo.attach(LeftEyeServoPin);
  RightEyeServo.attach(RightEyeServoPin);
  // WristServo.attach(WristServoPin);
  // ArmServo.attach(ArmServoPin);
  
  LeftEyeServo.write(90);
  RightEyeServo.write(90);
  // WristEyeServo.write(90);
  // ArmEyeServo.write(90);
  delay(3000);
  
  LeftEyeServo.write(90+70);
  RightEyeServo.write(90+70);
  // WristEyeServo.write(90);
  // ArmEyeServo.write(90);
  delay(3000);
  LeftEyeServo.write(90);
  RightEyeServo.write(90);
  // WristEyeServo.write(90);
  // ArmEyeServo.write(90);
}

void loop() {

}