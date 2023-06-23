//
// Created by modimanz on 6/22/2023.
//

#ifndef ARDUINOHELPERS_COMMUNICATIONS_H
#define ARDUINOHELPERS_COMMUNICATIONS_H
/**
 * @brief Communications class for Arduino
 *
 * This class implements a simple wrapper for the Arduino Serial class, which
 * can be used for communication between the Arduino and a computer or other
 * devices.
 *
 */
class Communications {
public:
    /**
     * @brief Construct a new Communications object
     *
     * @param baudRate Baud rate for the serial communication
     */
    Communications(long baudRate)
            : m_baudRate(baudRate) {
        Serial.begin(m_baudRate);
        while (!Serial) {;}  // Wait for the serial connection to be established
    }

    /**
     * @brief Send a message over the serial connection
     *
     * @param message The message to send
     */
    void sendMessage(const String &message) {
        Serial.println(message);
    }

    /**
     * @brief Check if a message is available to read
     *
     * @return true if a message is available, false otherwise
     */
    bool isMessageAvailable() {
        return Serial.available() > 0;
    }

    /**
     * @brief Read a message from the serial connection
     *
     * @return String The message that was read
     */
    String readMessage() {
        return Serial.readStringUntil('\n');
    }

private:
    long m_baudRate;
};

#endif //ARDUINOHELPERS_COMMUNICATIONS_H
