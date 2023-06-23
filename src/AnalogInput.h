//
// Created by modimanz on 6/22/2023.
//

#ifndef ARDUINOHELPERS_ANALOGINPUT_H
#define ARDUINOHELPERS_ANALOGINPUT_H

/**
 * @brief AnalogInput class for Arduino
 *
 * This class reads an analog input and provides methods to get the raw
 * reading or a scaled and offset reading.
 *
 */
class AnalogInput {
public:
    /**
     * @brief Construct a new AnalogInput object
     *
     * @param pin Number of the analog input pin to read
     */
    AnalogInput(int pin)
            : m_pin(pin), m_scaleFactor(1.0), m_offset(0.0) {
        pinMode(m_pin, INPUT);
    }

    /**
     * @brief Set the scaling and offset for the analog reading
     *
     * @param scaleFactor Factor to scale the reading by
     * @param offset Value to offset the reading by
     */
    void calibrate(float scaleFactor, float offset) {
        m_scaleFactor = scaleFactor;
        m_offset = offset;
    }

    /**
     * @brief Get the raw analog reading
     *
     * @return int Returns the raw analog reading (0 to 1023 for 10-bit ADCs)
     */
    int readRaw() {
        return analogRead(m_pin);
    }

    /**
     * @brief Get the scaled and offset analog reading
     *
     * @return float Returns the analog reading, scaled by the scale factor
     *               and offset by the offset
     */
    float readCalibrated() {
        return m_scaleFactor * readRaw() + m_offset;
    }

private:
    int m_pin;
    float m_scaleFactor;
    float m_offset;
};

#endif