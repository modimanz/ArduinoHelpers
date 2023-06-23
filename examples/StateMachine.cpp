//
// Created by mreg on 6/22/2023.
//

/**
 * This StateMachine class's constructor initializes the Arduino pin as an output. The setState method changes the
 * current state of the state machine. The update method updates the state machine based on the current state. If the
 * state is OFF, it turns the LED off. If the state is ON, it turns the LED on. If the state is BLINKING, it toggles
 * the LED every 500 milliseconds. Note that update method should be called in the main loop of the program.
 *
 * This class only represents a very basic state machine. For more complex systems, you may want to use a more
 * sophisticated state machine library or framework that provides features like nested states, entry/exit actions,
 * guard conditions, etc.
 */

StateMachine led(13);  // State machine for LED on pin 13

void setup() {
    Serial.begin(9600);
}

void loop() {
    led.update();

    // Test switching between states every 5 seconds
    if (millis() / 5000 % 3 == 0) {
        led.setState(StateMachine::OFF);
    } else if (millis() / 5000 % 3 == 1) {
        led.setState(StateMachine::ON);
    } else {
        led.setState(StateMachine::BLINKING);
    }
}