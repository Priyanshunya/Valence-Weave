#ifndef CONFIG_H
#define CONFIG_H

// --- ESP32-S3 Pin Mapping (Matched to schematic v1.0) ---

// Strain Gauge AFE (TLV9004 Op-Amp Outputs)
#define STRAIN_LONG_PIN    4   // OUT1 -> GPIO4 (ADC1)
#define STRAIN_TRANS_PIN   5   // OUT2 -> GPIO5 (ADC1)
#define STRAIN_DIAG_PIN    6   // OUT3 -> GPIO6 (ADC1)

// Bridge Excitation Control (P-MOSFET AO3401)
#define MOSFET_CTRL_PIN    18  // Excite Ctrl -> GPIO18

// I2C Bus (LSM6DS3TR-C IMU)
#define IMU_SDA_PIN        1   // I2C_SDA -> GPIO1
#define IMU_SCL_PIN        2   // I2C_SCL -> GPIO2
#define IMU_INT_PIN        21  // IMU_INT -> GPIO21

// SPI Bus & Control (SX1262 LoRa Transceiver)
#define LORA_CS_PIN        10  // SPI_NSS -> GPIO10
#define LORA_MOSI_PIN      11  // SPI_MOSI -> GPIO11
#define LORA_SCK_PIN       12  // SPI_SCK -> GPIO12
#define LORA_MISO_PIN      13  // SPI_MISO -> GPIO13
#define LORA_RST_PIN       14  // RST -> GPIO14
#define LORA_BUSY_PIN      15  // BUSY -> GPIO15
#define LORA_DIO1_PIN      16  // DIO1 -> GPIO16

#define LORA_FREQ          865E6 // 865-867 MHz ISM Band

#endif
