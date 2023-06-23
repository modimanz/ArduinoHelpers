//
// Created by mreg on 6/22/2023.
//

/**
 * A data logger is a device that records data over time or in relation to location with a
 * built in instrument or sensor.
 */

#ifndef ARDUINOHELPERS_DATALOGGER_H
#define ARDUINOHELPERS_DATALOGGER_H
/**
 * @brief DataLogger class for Arduino
 *
 * This class implements a simple data logger that logs data to the serial port.
 *
 */
class DataLogger {
public:
    /**
     * @brief Construct a new DataLogger object
     *
     * @param baudRate Baud rate for the serial communication
     */
    DataLogger(long baudRate)
            : m_baudRate(baudRate) {
        Serial.begin(m_baudRate);
        while (!Serial) {;}  // Wait for the serial connection to be established
    }

    /**
     * @brief Log a single data point
     *
     * @param dataPoint The data point to log
     */
    void logData(float dataPoint) {
        Serial.println(dataPoint);
    }

    /**
     * @brief Log multiple data points
     *
     * @param dataPoints Array of data points to log
     * @param size Number of data points in the array
     */
    void logData(float dataPoints[], int size) {
        for (int i = 0; i < size; i++) {
            Serial.println(dataPoints[i]);
        }
    }

private:
    long m_baudRate;
};

#endif //ARDUINOHELPERS_DATALOGGER_H
