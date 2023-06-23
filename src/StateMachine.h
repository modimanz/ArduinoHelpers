//
// Created by mreg on 6/22/2023.
//

#ifndef ARDUINOHELPERS_STATEMACHINE_H
#define ARDUINOHELPERS_STATEMACHINE_H
/**
 * @brief StateMachine class for Arduino
 *
 * This class implements a simple state machine for an LED.
 * The LED can be in one of three states: OFF, ON, or BLINKING.
 *
 */
class StateMachine {
public:
    enum State {OFF, ON, BLINKING};

    /**
     * @brief Construct a new StateMachine object
     *
     * @param pin Number of the digital output pin to control the LED
     */
    StateMachine(int pin)
            : m_pin(pin), m_state(OFF), m_lastToggleTime(0) {
        pinMode(m_pin, OUTPUT);
    }

    /**
     * @brief Set the state of the state machine
     *
     * @param state Desired state
     */
    void setState(State state) {
        m_state = state;
    }

    /**
     * @brief Update the state machine, should be called in the main loop
     */
    void update() {
        switch(m_state) {
            case OFF:
                digitalWrite(m_pin, LOW);
                break;
            case ON:
                digitalWrite(m_pin, HIGH);
                break;
            case BLINKING:
                if (millis() - m_lastToggleTime > 500) {
                    digitalWrite(m_pin, !digitalRead(m_pin));
                    m_lastToggleTime = millis();
                }
                break;
        }
    }

private:
    int m_pin;
    State m_state;
    unsigned long m_lastToggleTime;
};

#endif //ARDUINOHELPERS_STATEMACHINE_H
