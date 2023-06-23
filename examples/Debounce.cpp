#include "myTimer.h"

/*
 * This code will print "Button is pressed" to the serial console whenever the button connected to pin 2 is pressed,
 * debouncing the button input so that transient changes are ignored. The debounce delay is set to 50 milliseconds,
 * which is a common value for physical buttons.
 * In this code, the Debounce class's constructor initializes the Arduino pin as an input. The read function reads the
 * state of the button and returns the debounced state. This means that it will only return HIGH or LOW if the button
 * has been in that state for longer than the debounce delay; otherwise, it will return the button's previous state.
 * This effectively ignores any changes that last less than the debounce delay, which are likely to be due to mechanical
 * "bounce".
 *
 */

Debounce button(2, 50);  // Button connected to pin 2, debounce delay of 50ms

void setup() {
    Serial.begin(9600);
}

void loop() {
    int buttonState = button.read();
    if (buttonState == HIGH) {
        Serial.println("Button is pressed");
    }
}