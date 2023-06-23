//
// Created by modimanz on 6/22/2023.
//

#ifndef ARDUINOHELPERS_MOTORCONTROL_H
#define ARDUINOHELPERS_MOTORCONTROL_H
/**
 * @brief MotorControl class for Arduino
 *
 * This class implements a simple motor controller for a DC motor using an
 * H-bridge.
 *
 */
class MotorControl {
public:
    /**
     * @brief Construct a new MotorControl object
     *
     * @param pin1 First input pin for the H-bridge
     * @param pin2 Second input pin for the H-bridge
     * @param pinPWM PWM pin for controlling the speed
     */
    MotorControl(int pin1, int pin2, int pinPWM)
            : m_pin1(pin1), m_pin2(pin2), m_pinPWM(pinPWM) {
        pinMode(m_pin1, OUTPUT);
        pinMode(m_pin2, OUTPUT);
        pinMode(m_pinPWM, OUTPUT);
    }

    /**
     * @brief Set the speed and direction of the motor
     *
     * @param speed Speed of the motor (-255 to 255). Negative for reverse direction.
     */
    void setSpeed(int speed) {
        bool direction = speed >= 0;
        digitalWrite(m_pin1, direction);
        digitalWrite(m_pin2, !direction);
        analogWrite(m_pinPWM, abs(speed));
    }

private:
    int m_pin1;
    int m_pin2;
    int m_pinPWM;
};

#endif //ARDUINOHELPERS_MOTORCONTROL_H
