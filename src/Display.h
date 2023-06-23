//
// Created by modimanz on 6/22/2023.
//

#ifndef ARDUINOHELPERS_DISPLAY_H
#define ARDUINOHELPERS_DISPLAY_H
/**
 * @brief Display class for Arduino
 *
 * This class implements a simple display controller for a character LCD display.
 *
 */
#include <LiquidCrystal.h>

class Display {
public:
    /**
     * @brief Construct a new Display object
     *
     * @param rs The number of the pin connected to the RS line of the LCD
     * @param enable The number of the pin connected to the Enable line of the LCD
     * @param d4 The number of the pin connected to the D4 line of the LCD
     * @param d5 The number of the pin connected to the D5 line of the LCD
     * @param d6 The number of the pin connected to the D6 line of the LCD
     * @param d7 The number of the pin connected to the D7 line of the LCD
     */
    Display(int rs, int enable, int d4, int d5, int d6, int d7)
            : m_lcd(rs, enable, d4, d5, d6, d7) {
        m_lcd.begin(16, 2);  // Assume a 16x2 LCD
    }

    /**
     * @brief Write a message to the LCD
     *
     * @param message The message to display
     */
    void writeMessage(const String &message) {
        m_lcd.clear();
        m_lcd.setCursor(0, 0);
        m_lcd.print(message);
    }

private:
    LiquidCrystal m_lcd;
};

#endif //ARDUINOHELPERS_DISPLAY_H
