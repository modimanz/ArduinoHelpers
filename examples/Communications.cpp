//
// Created by mreg on 6/22/2023.
//

/**
 * In this example, the Communications class's constructor initializes the serial connection with the specified baud r
 * ate. The sendMessage method sends a message over the serial connection. The isMessageAvailable method checks if a
 * message is available to read, and the readMessage method reads a message from the serial connection.
 *
 * Again, this is a simple example that only covers basic serial communication. Depending on your application, you
 * might need to handle other types of communication, like WiFi, Bluetooth, I2C, SPI, etc. You'd also likely want
 * to add error handling and possibly other features, like the ability to send and receive different types of data,
 * not just strings.
*/

Communications comm(9600);  // Communications object with a baud rate of 9600

void loop() {
    if (comm.isMessageAvailable()) {
        String message = comm.readMessage();
        // Do something with the message
    }

    comm.sendMessage("Hello, world!");
    delay(1000);  // Wait for 1 second before sending the next message
}
