//
// Created by modimanz on 6/22/2023.
//
/**
 * In this example, the MotorControl class's constructor initializes the pins. The setSpeed method controls the speed
 * and direction of the motor. A positive speed makes the motor spin in one direction, while a negative speed makes
 * it spin in the other direction.
 *
 * This is a very simple example that only controls one motor. For more complex applications, you might want to add
 * more features to this class. For example, you could add methods for accelerating or decelerating the motor smoothly,
 * for controlling two motors at once for a differential drive robot, etc. You could also add error checking to make
 * sure the speed is within the valid range.
 *
 * Remember to connect the grounds of your Arduino and motor power supply together when you're using an external power
 * supply for the motor. This is necessary to ensure that the voltage levels are referenced to the same ground point.
 */

MotorControl motor(2, 3, 4);  // Motor connected to pins 2, 3 and 4

void loop() {
    // Make the motor spin forward at full speed
    motor.setSpeed(255);

    delay(2000);

    // Make the motor spin in reverse at half speed
    motor.setSpeed(-128);

    delay(2000);
}
