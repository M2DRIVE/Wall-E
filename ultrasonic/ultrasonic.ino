const int TRIG_PIN = 11;
const int ECHO_PIN = 12;

// Anything over 400 cm (23200 us pulse) is "out of range"
const unsigned int MAX_DIST = 23200;
const float MAX_DISTANCE_INCHES = 30.0;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long t1;
  unsigned long t2;
  unsigned long pulse_width;
  float cm;
  float inches;

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  while (digitalRead(ECHO_PIN) == 0);

  t1 = micros();
  while (digitalRead(ECHO_PIN) == 1);
  t2 = micros();
  pulse_width = t2 - t1;

  cm = pulse_width / 58.0;
  inches = pulse_width / 148.0;

  if (pulse_width > MAX_DIST) {
    Serial.println("Out of range");
  } else if (inches > MAX_DISTANCE_INCHES) {
    Serial.println("Distance greater than 30 inches. Ignoring value.");
  } else {
    Serial.print(cm);
    Serial.print(" cm \t");
    Serial.print(inches);
    Serial.println(" in");
  }

  delay(60);
}

boolean isWave() {
  
}