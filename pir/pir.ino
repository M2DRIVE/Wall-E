void setup() {
    Serial.begin(9600);
    pinMode(3, INPUT);
}

void loop() {
    if(digitalRead(3) == HIGH)
        Serial.println("1");

    else 
        Serial.println("0");
}