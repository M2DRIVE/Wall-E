#include <Servo.h>

Servo LeftEye;
Servo RightEye;

const int LeftEyeServoPin = 9;
const int RightEyeServoPin = 6;

void setup() {
    Serial.begin(9600);

    Serial.println("------------------");
    Serial.println("Servos Attached");
    LeftEye.attach(LeftEyeServoPin);
    RightEye.attach(RightEyeServoPin);
    
    delay(100);

    Serial.println("Servos Default");
    LeftEye.write(90);
    RightEye.write(85);

    delay(1000);

    Serial.println("Servos Calibrated");
    LeftEye.write(90+11.5);
    RightEye.write(85-11.5);

    delay(2000);

    Serial.println("Eyes Moved Up");
    LeftEye.write(90+51);
    RightEye.write(85-51);

    delay(500);

    Serial.println("Eyes Moved Down");
    LeftEye.write(90+11.5);
    RightEye.write(85-11.5);

    delay(500);

    Serial.println("Eyes Moved Up");
    LeftEye.write(90+51);
    RightEye.write(85-51);

    delay(500);

    Serial.println("Eyes Moved Down");
    LeftEye.write(90+11.5);
    RightEye.write(85-11.5);

}

void loop() {}