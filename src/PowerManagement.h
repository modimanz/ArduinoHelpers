//
// Created by mreg on 6/22/2023.
//

#ifndef ARDUINOHELPERS_POWERMANAGEMENT_H
#define ARDUINOHELPERS_POWERMANAGEMENT_H
/**
 * @brief PowerManagement class for Arduino
 *
 * This class implements a simple power management by putting the Arduino into
 * a low power sleep mode to conserve energy.
 *
 */
class PowerManagement {
public:
    /**
     * @brief Construct a new PowerManagement object
     *
     */
    PowerManagement() {}

    /**
     * @brief Puts the Arduino into sleep mode
     *
     */
    void sleep() {
        // The following line of code requires the <avr/sleep.h> library
        set_sleep_mode(SLEEP_MODE_PWR_DOWN);
        sleep_enable();

        // Disable all of the possible wake up sources, just in case
        ADCSRA &= ~(1<<ADEN);  // Disable ADC, saves ~230uA
        power_all_disable();  // Turn off as much as possible

        // Now enter sleep mode
        sleep_mode();

        // The program will continue from here after waking up
        sleep_disable();  // First thing to do is disable sleep

        // Re-enable everything we've just disabled
        power_all_enable();
        ADCSRA |= (1<<ADEN);
    }
};

#endif //ARDUINOHELPERS_POWERMANAGEMENT_H
