# ⚡ VALENCE WEAVE
**Cyber-Physical Safety Node & Edge-AI Wearable**

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](#)
[![MCU: ESP32-S3](https://img.shields.io/badge/Compute-ESP32--S3--MINI-success)](#)
[![Domain: CPS](https://img.shields.io/badge/Domain-Cyber_Physical_Safety-informational.svg)](#)
[![Industry: 5.0](https://img.shields.io/badge/Industry-5.0_/_Human_Centric-blueviolet.svg)](#)
[![Edge AI: TinyML](https://img.shields.io/badge/Edge_AI-TinyML_/_ESP--NN-blue.svg)](#)

> **The Mission:** Drastically mitigate industrial entrapment fatalities by replacing rigid, infrastructure-heavy IoT pendants with a zero-infrastructure, stretch-variable wearable. Valence Weave triggers automated machine fail-safes in sub-100 milliseconds—30x faster than baseline human reaction time.

---

## 📊 Engineering Specifications

| Parameter | Engineered Target | Validation Architecture |
| :--- | :--- | :--- |
| **System Stop Latency** | `< 100 ms` | End-to-End Oscilloscope Timing / LoRa ISR |
| **AI Inference** | `< 12 ms` | Core 1 ESP-NN SIMD Execution |
| **Sensor Interface** | High-Impedance | Quarter-Bridge Analog Signal Log |
| **Battery Autonomy** | 24+ Hours | Multi-Shift IMU Hardware Interrupt (RTC) |
| **Thermal Cutoff Safety** | `50°C` | BQ24090 NTC Hardware Sever |
| **Mass-Scale BOM** | `< ₹1,500` | 10k Unit Tape & Reel Sourcing Projection |

---

## 🧠 The 4-Layer Cyber-Physical Architecture

### 01 | Sense (The Wearable Interface)
* **Stretch-Variable Array:** A proprietary, multi-axis conductive textile strap that physically maps localized biomechanical strain, translating physical entanglement into a continuous electrical signature.
* **Industrial Sealing:** The conductive traces are encapsulated behind a 100 µm Hydrophobic TPU membrane to completely isolate the sensing circuit from foundry grease, conductive dust, and saline perspiration.

### 02 | Condition (The Analog Front-End)
* **Precision Topology:** High-impedance resistor networks translate the physical stretch of the conductive matrix into measurable ADC voltages.
* **Hardware Filtering:** Texas Instruments **TLV9004** CMOS Quad Op-Amp configured as a 2nd-order Sallen-Key low-pass filter ($f_c = 40\text{ Hz}$)[cite: 47]. Aggressively rejects 50Hz mains hum and ambient motor induction noise before digitization.
* **ESD Protection:** Transient Voltage Suppression (TVS) diodes mapped to every physical strap connector to shield silicon from industrial static discharge. 

### 03 | Compute (Edge AI & Kinematics)
* **MCU Core:** Espressif **ESP32-S3-MINI-1** running a custom FreeRTOS dual-core pipeline[cite: 46, 47].
* **Task Isolation:** Core 0 strictly handles system RTOS tasks and LoRa telemetry. Core 1 is dedicated entirely to INT8-quantized TinyML execution.
* **Sensor Fusion:** Merges analog strain data with digital kinematics from the **ST LSM6DS3TR-C 6-Axis IMU** (via I2C)[cite: 46, 47] to filter out transient physical shocks (e.g., dropping a heavy box) and target a `<2%` false-positive trigger rate.

### 04 | Actuate (Telemetry & Isolation)
* **RF Layer:** Semtech **SX1262 LoRa** transceiver operating on the 865–867 MHz ISM band[cite: 46, 47].
* **Payload Security:** 16-byte AES-256 encrypted event packets engineered to penetrate structural steel NLoS (Non-Line-of-Sight) without relying on local foundry Wi-Fi.
* **Machine Interface:** The receiver node utilizes a PC817 optocoupler to trigger a fail-safe, Normally Closed (NC) 24V industrial contactor physically wired into the machinery's E-stop loop.

---

## 🛡️ Intrinsic Hardware Safety & Power Logic

* **Zero Magnetic Snags:** Avoids lethal iron-filing accumulation by strictly utilizing mechanical 4-point snap fasteners rather than magnetic pogo-pins for all interconnects.
* **Thermal Runaway Defense:** Powered by a UN38.3 600mAh hard-shell prismatic cell. The TI **BQ24090** PMIC utilizes an active NTC thermistor to physically sever the power circuit if ambient foundry temperatures cross 50°C[cite: 46, 47].
* **RTC Sleep Enforcement:** To enforce the 24-hour power budget, the ESP32-S3 utilizes its Real-Time Clock (RTC) domain to hold a high-side P-Channel MOSFET closed[cite: 46, 47], physically severing excitation power to the conductive straps during micro-sleep cycles.
