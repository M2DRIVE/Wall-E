#include <Servo.h>

Servo WristServo;
Servo ArmServo;

const int WristServoPin = 11;
const int ArmServoPin = 10;

void setup() {
  Serial.begin(9600);
  ArmServo.attach(ArmServoPin);
  WristServo.attach(WristServoPin);
  Serial.println("--------------------");
  Serial.println("Servos Attached");
  
  delay(500);

  ArmServo.write(90);
  WristServo.write(150);
  Serial.println("Servos Calibrated");

  delay(2000);

  //ArmServo.write(90+70);
  for(int angle = 90; angle <= 90+70; angle += 1) {
    ArmServo.write(angle);
    delay(3);
  }
  Serial.println("Arm Moved Up");

  delay(1500);

  WristServo.write(90-45);
  Serial.println("Wrist Turn Down");

  delay(750);

  WristServo.write(150);
  Serial.println("Wrist Turn Up");

  delay(750);

  WristServo.write(90-45);
  Serial.println("Wrist Turn Down");
  
  delay(750);

  WristServo.write(150);
  Serial.println("Wrist Turn Up");

  delay(2000); 

  //ArmServo.write(90);
  for(int angle = 90+70; angle >= 90; angle -= 1) {
    ArmServo.write(angle);
    delay(3);
  }
  Serial.println("Arm Moved Down");
}

void loop() {

}