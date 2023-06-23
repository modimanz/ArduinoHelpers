//
// Created by modimanz on 6/22/2023.
//

#ifndef ARDUINOHELPERS_OUTPUTPULSE_H
#define ARDUINOHELPERS_OUTPUTPULSE_H

/**
 * @brief OutputPulse class for Arduino
 *
 * This class generates a pulse of a specified duration on a digital output pin.
 *
 */
class OutputPulse {
public:
    /**
     * @brief Construct a new OutputPulse object
     *
     * @param pin Number of the digital output pin to generate the pulse on
     */
    OutputPulse(int pin)
            : m_pin(pin) {
        pinMode(m_pin, OUTPUT);
        digitalWrite(m_pin, LOW);
    }

    /**
     * @brief Generate a pulse of the specified duration
     *
     * @param duration Duration of the pulse in milliseconds
     */
    void pulse(unsigned long duration) {
        digitalWrite(m_pin, HIGH);
        delay(duration);
        digitalWrite(m_pin, LOW);
    }

private:
    int m_pin;
};

#endif
