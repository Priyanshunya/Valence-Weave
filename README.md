# ⚡ VALENCE WEAVE
**Edge-AI & Cyber-Physical Safety Node**

![License: MIT](https://img.shields.io/badge/Software_License-MIT-blue.svg)
![Hardware License](https://img.shields.io/badge/Hardware_License-CERN_OHL_W-orange.svg)
![MCU: ESP32-S3](https://img.shields.io/badge/Compute-ESP32--S3--MINI-success)
![Status: Stage 3](https://img.shields.io/badge/Vishwakarma-Stage_3-critical)

 **Track:** AI in Hardware & Manufacturing 

### 🎯 The Mission
Drastically mitigating industrial entrapment fatalities by replacing rigid Western IoT pendants with a zero-infrastructure, conductive strap-based wearable that triggers automated machine shutoffs in sub-100 milliseconds.

---

### 📊 Engineered Specifications (Targets)

| Parameter | Engineered Target | Validation Method |
| :--- | :--- | :--- |
| **System Stop Latency** | < 100 ms | End-to-End Oscilloscope Timing |
| **AI Inference** | < 12 ms | Core 1 ESP-NN SIMD Execution |
| **Sensor Interface** | High-Impedance | Quarter-Bridge Analog Signal Log |
| **Battery Autonomy** | 24+ Hours | Multi-Shift IMU Hardware Interrupt |
| **Thermal Cutoff Safety** | 50°C | BQ24090 NTC Hardware Sever |
| **Mass-Scale BOM** | < ₹1,500 | 10k Unit Tape & Reel Sourcing |

---

### 🧠 The 4-Layer Cyber-Physical Architecture

**01 | Sense (The Wearable Interface)**
*   **Conductive Strip Array:** A proprietary, multi-axis conductive textile strap that physically maps localized body strain.
*   **Industrial Sealing:** The conductive traces are fully sealed to isolate the sensor circuit from industrial grease and saline perspiration.

**02 | Condition (The Analog Front-End)**
*   **Precision Divider Topology:** High-impedance resistor networks that translate the physical stretch of the conductive strips into measurable voltage.
*   **Hardware Filtering:** Texas Instruments **TLV9004** CMOS Quad Op-Amp configured as a 2nd-order Sallen-Key low-pass filter ($f_c = 40\text{ Hz}$). Aggressively rejects 50Hz mains hum and motor induction noise.
*   **ESD Protection:** Transient voltage suppression (TVS) diodes mapped to every physical strap connector to protect the silicon from worker static discharge. 

**03 | Compute (Edge AI & Kinematics)**
*   **MCU Core:** Espressif **ESP32-S3-MINI-1** running a custom FreeRTOS dual-core pipeline.
*   **Task Isolation:** Core 0 handles system telemetry. Core 1 is strictly dedicated to INT8-quantized TinyML execution.
*   **Sensor Fusion:** Combines analog strain lag with digital kinematic data from the **ST LSM6DS3TR-C 6-Axis IMU** (via I2C) to filter out transient physical shocks and target a <2% false-positive rate.

**04 | Actuate (Telemetry & Isolation)**
*   **RF Layer:** Semtech **SX1262 LoRa** transceiver operating on the 865–867 MHz ISM band.
*   **Payload Security:** 16-byte AES-256 encrypted event packets designed to penetrate structural steel NLoS.
*   **Machine Interface:** Receiver node utilizes a PC817 optocoupler to trigger a fail-safe, Normally Closed (NC) 24V industrial contactor integrated into the machine E-stop loop.

---

### 🛡️ Intrinsic Hardware Safety & Power Logic
*   **Zero Magnetic Snags:** Avoids lethal iron-filing accumulation by strictly utilizing mechanical snap fasteners rather than magnetic pogo-pins for the strap interconnects.
*   **Thermal Runaway Defense:** Powered by a UN38.3 600mAh hard-shell prismatic cell. The TI BQ24090 PMIC utilizes an active NTC thermistor to physically sever the power circuit if ambient foundry temperatures cross 50°C.
*   **RTC Sleep Enforcement:** To maintain the 24-hour power budget, the ESP32-S3 utilizes its Real-Time Clock (RTC) domain (`GPIO18`) to hold a high-side P-Channel MOSFET (AO3401) closed, cutting excitation power to the conductive straps during micro-sleep cycles.
