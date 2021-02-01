
int ledPin = 11;    // Specific to the Teensy 2.0.  Change as required.

void setup() {
    // initialize the digital pin as an output:
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);  // make sure the LED is off
}

void loop() {
    delay(1000);
    digitalWrite(ledPin, HIGH);  // make sure the LED is on
    Mouse.move(1, 0, 0);
    delay(20);
    Mouse.move(-1, 0, 0);
    digitalWrite(ledPin, LOW);  // make sure the LED is off
    delay(9000);
}
