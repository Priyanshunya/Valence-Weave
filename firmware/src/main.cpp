/*
 * Valence Weave - Core Firmware Node (Work in Progress)
 * Target: ESP32-S3-MINI-1
 * Status: Benchtop hardware bring-up and basic sensor logging phase.
 */

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include "config.h"

// Task handles for FreeRTOS core pinning
TaskHandle_t commsTaskHandle = NULL;
TaskHandle_t aiTaskHandle = NULL;

void commsTask(void *pvParameters) {
    // Core 0: LoRa telemetry loop & system housekeeping
    TickType_t xLastWakeTime;
    const TickType_t xFrequency = pdMS_TO_RTOS_TICKS(50); // 20Hz loop
    xLastWakeTime = xTaskGetTickCount();

    while (true) {
        vTaskDelayUntil(&xLastWakeTime, xFrequency);
    }
}

void aiTask(void *pvParameters) {
    // Core 1: High-speed analog sampling loop
    TickType_t xLastWakeTime;
    const TickType_t xFrequency = pdMS_TO_RTOS_TICKS(10); // 100Hz sampling target
    xLastWakeTime = xTaskGetTickCount();

    while (true) {
        // Read conditioned analog strain values from TLV9004 AFE outputs
        int longVal  = analogRead(STRAIN_LONG_PIN);
        int transVal = analogRead(STRAIN_TRANS_PIN);
        int diagVal  = analogRead(STRAIN_DIAG_PIN);

        /* 
         * NOTE: No AI model is trained or deployed at this stage.
         */
        
        vTaskDelayUntil(&xLastWakeTime, xFrequency);
    }
}

void setup() {
    Serial.begin(115200);
    delay(500);
    Serial.println("\n[INIT] Valence Weave Firmware v0.3-alpha (WIP)");

    // Setup bridge excitation pin (To power the e-textile divider network)
    pinMode(MOSFET_CTRL_PIN, OUTPUT);
    digitalWrite(MOSFET_CTRL_PIN, HIGH); 

    // Configure ADC input pins for strain gauges
    pinMode(STRAIN_LONG_PIN, INPUT);
    pinMode(STRAIN_TRANS_PIN, INPUT);
    pinMode(STRAIN_DIAG_PIN, INPUT);

    // Initialize I2C for LSM6DS3TR-C IMU (Pins 1 & 2)
    Wire.begin(IMU_SDA_PIN, IMU_SCL_PIN, 400000);

    // Pin Task 0 to Core 0 (Communications & RF Stack)
    xTaskCreatePinnedToCore(
        commsTask,
        "CommsTask",
        4096,
        NULL,
        2,
        &commsTaskHandle,
        0
    );

    // Pin Task 1 to Core 1 (Sensor Ingestion & Future Processing)
    xTaskCreatePinnedToCore(
        aiTask,
        "AITask",
        4096,
        NULL,
        3,
        &aiTaskHandle,
        1
    );

    Serial.println("[INIT] FreeRTOS scheduler running. Awaiting hardware bring-up.");
}

void loop() {
    // Empty: execution is handled entirely by FreeRTOS core tasks
    vTaskDelay(pdMS_TO_RTOS_TICKS(1000));
}
