MyTimer newTimer;

void setup() {
    Serial.begin(9600);
    newTimer.set_interval(1000);  // 1 second interval
}

void loop() {
    if (newTimer.elapsed()) {
        // your code here
        Serial.println("1 second has passed!");
    }
}