//
// Created by mreg on 6/22/2023.
//

#ifndef ARDUINOHELPERS_PIDCONTROLLER_H
#define ARDUINOHELPERS_PIDCONTROLLER_H
/**
 * @brief PIDController class for Arduino
 *
 * This class implements a simple PID (Proportional-Integral-Derivative) controller.
 * PID controllers are commonly used in control systems to automatically adjust a
 * process to meet a setpoint using feedback.
 *
 */
class PIDController {
public:
    /**
     * @brief Construct a new PIDController object
     *
     * @param Kp Proportional gain
     * @param Ki Integral gain
     * @param Kd Derivative gain
     */
    PIDController(float Kp, float Ki, float Kd)
            : m_Kp(Kp), m_Ki(Ki), m_Kd(Kd), m_integral(0), m_previousError(0) {}

    /**
     * @brief Calculate the PID control value
     *
     * @param setpoint Desired setpoint
     * @param pv Actual process variable
     * @return float Returns the control value that should be used to adjust the process
     */
    float calculate(float setpoint, float pv) {
        float error = setpoint - pv;
        float pOut = m_Kp * error;

        m_integral += error;
        float iOut = m_Ki * m_integral;

        float derivative = error - m_previousError;
        float dOut = m_Kd * derivative;

        m_previousError = error;

        return pOut + iOut + dOut;
    }

private:
    float m_Kp;
    float m_Ki;
    float m_Kd;
    float m_integral;
    float m_previousError;
};

#endif //ARDUINOHELPERS_PIDCONTROLLER_H
