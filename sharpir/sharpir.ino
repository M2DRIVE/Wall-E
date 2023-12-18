#include <SharpDistSensor.h>

const byte sensorPin = A0;

const byte medianFilterWindowSize = 5;
SharpDistSensor sensor(sensorPin, medianFilterWindowSize);

int sampleCounter = 0;
const int threshold = 390;

enum State {
  INIT,
  FIRST_DROP,
  FIRST_PEAK,
  SECOND_DROP,
  SECOND_PEAK
};

State currentState = INIT;

void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned int distance = sensor.getDist();

  switch (currentState) {
    case INIT:
      if (distance < threshold) {
        currentState = FIRST_DROP;
      }
      break;

    case FIRST_DROP:
      if (distance > threshold) {
        currentState = FIRST_PEAK;
      }
      break;

    case FIRST_PEAK:
      if (distance < threshold) {
        currentState = SECOND_DROP;
      }
      break;

    case SECOND_DROP:
      if (distance > threshold) {
        currentState = SECOND_PEAK;
      }
      break;

    case SECOND_PEAK:
      if (distance < threshold) {
        // Pattern detected
        digitalWrite(2, HIGH);
        delay(500);
        digitalWrite(2, LOW);
        currentState = INIT;
      }
      break;
  }

  if (sampleCounter == 30) {
    currentState = INIT;
    sampleCounter = 0;
  } else {
    sampleCounter++;
  }

  Serial.println(distance);
  delay(20);
}
