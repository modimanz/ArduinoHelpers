/*
 * This OutputPulse class's constructor initializes the Arduino pin as an output and sets it LOW. The pulse method
 * generates a pulse of a specified duration on the pin by setting the pin HIGH, delaying for the specified duration,
 * and then setting the pin back to LOW.
 * Please note that delay() function used here is blocking, which means that it will halt the execution of your program
 * for the duration of the delay. If you want to avoid blocking, you'll need to use a different approach, such as the
 * millis() function to keep track of time and changing the state of the pin when the desired duration has passed,
 * similar to the timer class in the previous examples.
 */

OutputPulse myPulse(13);  // Generate pulses on digital pin 13

void loop() {
    myPulse.pulse(500);  // Generate a pulse of 500ms duration
    delay(1000);  // Wait for 1 second before generating the next pulse
}
