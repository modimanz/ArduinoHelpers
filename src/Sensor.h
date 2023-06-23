//
// Created by modimanz on 6/22/2023.
//
/**
 *  In general, a Sensor class might be abstract because the code to read from a sensor can vary widely between
 *  different types of sensors. However, for this example, let's create a Sensor class for reading from a simple
 *  analog sensor, like a potentiometer or a light sensor.
 */

#ifndef ARDUINOHELPERS_SENSOR_H
#define ARDUINOHELPERS_SENSOR_H
/**
 * @brief Sensor class for Arduino
 *
 * This class implements a simple sensor reader for a generic analog sensor.
 *
 */
class Sensor {
public:
    /**
     * @brief Construct a new Sensor object
     *
     * @param pin Analog pin the sensor is connected to
     */
    Sensor(int pin)
            : m_pin(pin) {
        pinMode(m_pin, INPUT);
    }

    /**
     * @brief Read the value from the sensor
     *
     * @return int The sensor value (0 - 1023 for 10-bit ADC)
     */
    int read() {
        return analogRead(m_pin);
    }

private:
    int m_pin;
};

#endif //ARDUINOHELPERS_SENSOR_H
