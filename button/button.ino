// const int buttonPin = 13;
// const int buttonPin1 = 12;
// int playRead = 0;
// int playState = 0;
// int skipTrack = 0;
// int currentTrack = 0;

// void setup() {
//     Serial.begin(9600);
//     Serial.println("Off");

//     pinMode(buttonPin, INPUT);
//     pinMode(buttonPin1, INPUT);
// }

// void loop() {
//     playRead = digitalRead(buttonPin);   
//     skipTrack = digitalRead(buttonPin1);

//     if (playRead == HIGH) {
//         if (playState == 0) 
//             Serial.println("Playing track " + String(currentTrack));
        
//         else 
//             Serial.println("Stopping track " + String(currentTrack));

//         playState ^= 1; 
//         delay(500);
//     } 
    
//     else if (skipTrack == HIGH) {
//         currentTrack = (currentTrack + 1) % 3;
//         Serial.println("Skipping to track " + String(currentTrack));
//         delay(500);
//     }
// }