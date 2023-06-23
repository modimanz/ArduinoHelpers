//
// Created by modimanz on 6/22/2023.
//

/**
 * In this example, the Sensor class's constructor initializes the analog pin. The read method reads the value from the
 * sensor. The value is in the range 0 - 1023 for a 10-bit ADC, which is the resolution of the Arduino Uno's ADC.
 *
 * This is a simple example for a generic analog sensor. For more complex sensors, like a temperature sensor that needs
 * to convert the analog reading to a temperature, or a digital sensor that communicates over I2C or SPI, you would
 * likely need to create a separate class for each type of sensor. The separate classes could all inherit from a common
 * Sensor interface, which could include methods like read, begin, etc. You could also add error checking to handle any
 * errors that might occur when reading from the sensor.
 */

Sensor lightSensor(A0);  // Light sensor connected to analog pin A0

void loop() {
    // Read the light level
    int lightLevel = lightSensor.read();

    // Do something with the light level
    // ...

    delay(1000);  // Wait for 1 second before reading the light level again
}

