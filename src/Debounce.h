//
// Created by modimanz on 6/22/2023.
//

#ifndef ARDUINOHELPERS_DEBOUNCE_H
#define ARDUINOHELPERS_DEBOUNCE_H

/**
 * @brief Debounce class for Arduino
 *
 * This class debounces an input pin, so that transient LOW-HIGH-LOW sequences
 * (which often occur with physical buttons/switches) are ignored, and only
 * steady state changes are reported.
 *
 */
class Debounce {
public:
    /**
     * @brief Construct a new Debounce object
     *
     * @param pin Number of the input pin to debounce
     * @param debounceDelay Debounce delay in milliseconds
     */
    Debounce(int pin, long debounceDelay)
            : m_pin(pin), m_debounceDelay(debounceDelay), m_lastDebounceTime(0), m_lastState(LOW) {
        pinMode(m_pin, INPUT);
    }

    /**
     * @brief Read the debounced state of the input pin
     *
     * @return int Returns HIGH if the input is HIGH, and LOW if the input is LOW,
     *             but only if the input has been in that state for longer than
     *             the debounce delay.
     */
    int read() {
        int currentState = digitalRead(m_pin);
        if (currentState != m_lastState) {
            m_lastDebounceTime = millis();
        }

        if ((millis() - m_lastDebounceTime) > m_debounceDelay) {
            m_lastState = currentState;
        }

        return m_lastState;
    }

private:
    int m_pin;
    long m_debounceDelay;
    unsigned long m_lastDebounceTime;
    int m_lastState;
};

#endif