#include <Arduino.h>
/**
 * @file main.cpp
 * @brief Embedded Force Measurement System using FSR
 * @author Nitin Kumar
 * @date 2026-02-19
 *
 * @details
 * Reads analog force data from FSR sensor and
 * displays structured output via Serial Monitor.
 */

#include <Arduino.h>

#define FSR_PIN A0   // Define FSR pin properly

int value = 0;

void setup() {
    Serial.begin(9600);
    pinMode(FSR_PIN, INPUT);

    Serial.println("FSR Sensor System Initialized");
}

void loop() {

    // Read analog value
    value = analogRead(FSR_PIN);

    // Convert to voltage
    float voltage = value * (5.0 / 1023.0);

    // Print raw value
    Serial.print("ADC Value: ");
    Serial.print(value);

    Serial.print(" | Voltage: ");
    Serial.print(voltage);
    Serial.println(" V");

    // Pressure detection logic
    if (value > 200) {
        Serial.println("Pressure Detected!");
    } else {
        Serial.println("No Pressure");
    }

    Serial.println("-----------------------");

    delay(500);
}
