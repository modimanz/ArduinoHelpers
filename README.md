# ArduinoHelpers
Arduino Helpers

Some very basic concepts to help you get started.

1. __Debounce Class:__ Button inputs can sometimes "bounce", leading to multiple input readings from a single press. A debounce class could handle this, providing a clean signal you can use.


2. __AnalogInput Class:__ Reading analog signals can often require scaling and conversion to meaningful units. A class that does this could simplify your code.


3. __OutputPulse Class:__ If you're often creating pulses (e.g., for driving certain types of motors or for generating signals), a class to encapsulate the timing and control of these pulses could be useful.


4. __PID Controller Class:__ If you're doing any control systems work (like driving a robot arm to a specific position), a PID (Proportional-Integral-Derivative) controller can be very useful. It can be a bit tricky to get right, so wrapping it in a class can make your life easier.


5. __State Machine Class:__ Many embedded systems are most naturally modeled as state machines. A class to encapsulate a state machine can simplify your control flow and make your code easier to understand.


6. __Data Logger Class:__ If you're regularly logging data to an SD card or sending it over a network, a data logger class could handle the details of this and provide a simple interface for recording data.


7. __Communications Class:__ If you are using any form of communication protocol like I2C, SPI, Serial, etc., creating a class that manages these communication methods will be beneficial and could reduce code redundancy.


8. __Power Management Class:__ In battery-powered applications, managing power consumption is critical. A class that controls power to different parts of your system could help extend battery life.

