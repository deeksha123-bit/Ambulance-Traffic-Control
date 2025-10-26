// Traffic light for Lane 1
int red1 = 10;
int yellow1 = 9;
int green1 = 8;
int blue1 = 11;
int buzzer1 = A0; // Buzzer for Lane 1

// Traffic light for Lane 2
int red2 = 6;
int yellow2 = 5;
int green2 = 4;
int blue2 = 3;
int buzzer2 = A1; // Buzzer for Lane 2

// Traffic light for Lane 3
int red3 = 12;
int yellow3 = 1;
int green3 = 13;
int blue3 = 7;
int buzzer3 = A2; // Buzzer for Lane 3

void setup() {
    // Configure pins for Lane 1
    pinMode(buzzer1, OUTPUT);
    pinMode(red1, OUTPUT);
    pinMode(yellow1, OUTPUT);
    pinMode(green1, OUTPUT);
    pinMode(blue1, OUTPUT);

    // Configure pins for Lane 2
    pinMode(buzzer2, OUTPUT);
    pinMode(red2, OUTPUT);
    pinMode(yellow2, OUTPUT);
    pinMode(green2, OUTPUT);
    pinMode(blue2, OUTPUT);

    // Configure pins for Lane 3
    pinMode(buzzer3, OUTPUT);
    pinMode(red3, OUTPUT);
    pinMode(yellow3, OUTPUT);
    pinMode(green3, OUTPUT);
    pinMode(blue3, OUTPUT);
}

void loop() {
    // Cycle traffic lights for all three lanes
    controlTraffic(red1, yellow1, green1, blue1, buzzer1, red2, red3);
    controlTraffic(red2, yellow2, green2, blue2, buzzer2, red1, red3);
    controlTraffic(red3, yellow3, green3, blue3, buzzer3, red1, red2);
}

void controlTraffic(int red, int yellow, int green, int blue, int buzzer, int otherRed1, int otherRed2) {
    // Ensure other lanes are red
    digitalWrite(otherRed1, HIGH);
    digitalWrite(otherRed2, HIGH);

    // Turn green light on for this lane and ensure others are off
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(buzzer, LOW); // Ensure buzzer is off
    delay(5000); // Green light duration

    // Transition to yellow light
    digitalWrite(green, HIGH);
   digitalWrite(blue, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(buzzer, HIGH); // Warning sound during yellow light
    delay(3000); // Yellow light duration
    digitalWrite(buzzer, LOW);
  digitalWrite(yellow, HIGH);
  delay(1000);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(buzzer, LOW); 
  digitalWrite(red, HIGH);
    digitalWrite(green,LOW);
    digitalWrite(blue, LOW);
    digitalWrite(buzzer, LOW); 

    // Switch to red
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    delay(1000); // Red light stabilization
}
