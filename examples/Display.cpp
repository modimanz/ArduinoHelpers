//
// Created by modimanz on 6/22/2023.
//

/**
 * In this example, the Display class's constructor initializes the LCD. The writeMessage method clears the display,
 * sets the cursor to the beginning of the first line, and writes the message to the LCD.
 *
 * This is a simple example for a character LCD display. For more complex displays, like a graphical LCD or an OLED
 * display, you would likely need to create a separate class for each type of display. The separate classes could all
 * inherit from a common Display interface, which could include methods like writeMessage, drawLine, drawCircle, etc.
 * You could also add error checking to handle any errors that might occur when communicating with the display.
 */

Display lcd(12, 11, 5, 4, 3, 2);  // LCD connected to pins 12, 11, 5, 4, 3, and 2

void loop() {
    // Write a message to the LCD
    lcd.writeMessage("Hello, world!");

    delay(2000);  // Wait for 2 seconds before displaying the next message
}

