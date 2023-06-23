AnalogInput sensor(A0);  // Sensor connected to analog pin A0

void setup() {
    Serial.begin(9600);
    sensor.calibrate(0.0048828125, 0);  // Calibrate for 0-5V range (for 10-bit ADC)
}

void loop() {
    float sensorVoltage = sensor.readCalibrated();
    Serial.print("Sensor voltage: ");
    Serial.println(sensorVoltage);
    delay(1000);
}