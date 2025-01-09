#include <Servo.h>

Servo WristServo;
Servo ArmServo;

const int WristServoPin = 11;
const int ArmServoPin = 10;

const int upAngle = 90;
const int downAngle = 0;

void setup() {
  Serial.begin(115200);
  ArmServo.attach(ArmServoPin);
  
  WristServo.attach(WristServoPin);
  WristServo.write(upAngle);

  Serial.println("--------------------");
  Serial.println("Servos Attached");
  Serial.print("Reading ");
  Serial.println(WristServo.read());
  delay(1500);

  ArmServo.write(90);
  Serial.println("Servos Calibrated");

  delay(2000);

  ArmServo.write(90+70);
  // for(int angle = 90; angle <= 90+70; angle += 1) {
  //   ArmServo.write(angle);
  //   delay(3);
  // }
  Serial.println("Arm Moved Up");

  delay(1500);

  WristServo.write(downAngle);
  Serial.println("Wrist Turn Down");

  delay(750);

  WristServo.write(upAngle);
  Serial.println("Wrist Turn Up");

  delay(750);

  WristServo.write(downAngle);
  Serial.println("Wrist Turn Down");
  
  delay(750);

  WristServo.write(upAngle);
  Serial.println("Wrist Turn Up");

  delay(2000); 

  ArmServo.write(90);
  // for(int angle = 90+70; angle >= 90; angle -= 1) {
  //   ArmServo.write(angle);
  //   delay(3);
  // }
  Serial.println("Arm Moved Down");
}

void loop() {

}