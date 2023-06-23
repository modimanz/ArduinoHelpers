//
// Created by mreg on 6/22/2023.
//

/**
 * In this example, the DataLogger class's constructor initializes the serial connection with the specified baud rate.
 * The logData method logs a single data point to the serial port, and there's also an overloaded version that logs
 * multiple data points from an array.
 *
 * This is a simple example that only logs data to the serial port. In a more complex application, you might want to
 * log data to an SD card, send it over a network connection, or even upload it to a cloud service. You'd also likely
 * want to log additional information, like a timestamp for each data point and possibly a label or identifier for
 * the data.
 *
 * Also, keep in mind that logging data can be slow, especially if you're logging to an SD card or over a network
 * connection. If your application requires high-speed data logging, you may need to use a different approach, like
 * a circular buffer to store data points and a separate task to write them out in batches.
 */

DataLogger logger(9600);  // Data logger with a baud rate of 9600

void loop() {
    float dataPoint = analogRead(A0);  // Replace this with actual data point
    logger.logData(dataPoint);

    delay(1000);  // Wait for 1 second before logging the next data point
}