//
// Created by modimanz on 6/22/2023.
//

#ifndef ARDUINOHELPERS_MYTIMER_H
#define ARDUINOHELPERS_MYTIMER_H

// Define the MyTimer class
class MyTimer {
public:
    // The default constructor initializes the start time and interval to zero
    MyTimer() : m_startTime(0), m_interval(0) {}

    // The set_interval method sets the timer interval in milliseconds and
    // also records the current time as the start time
    void set_interval(unsigned long interval) {
        m_interval = interval;          // Set the interval duration
        m_startTime = millis();         // Record the current time as the start time
    }

    // The elapsed method checks if the interval has passed since the last
    // time it was called (or since the interval was set, if it has never been called)
    bool elapsed() {
        // If interval is not set (i.e., it's zero), return false
        if (m_interval == 0) {
            return false;
        }

        // If the current time minus the start time is greater or equal to the interval
        // this means the specified interval duration has passed
        if (millis() - m_startTime >= m_interval) {
            m_startTime = millis();       // Reset the start time for the next interval
            return true;                  // Return true since the interval has passed
        } else {
            return false;                 // Return false since the interval hasn't passed
        }
    }

private:
    unsigned long m_startTime;        // The start time of the timer
    unsigned long m_interval;         // The interval duration in milliseconds
};

#endif