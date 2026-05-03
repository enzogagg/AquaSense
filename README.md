# 🌊 AquaSense: Intelligent Water Quality Monitoring

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Framework: ESPHome](https://img.shields.io/badge/Framework-ESPHome-green.svg)](https://esphome.io/)
[![Framework: PlatformIO](https://img.shields.io/badge/Framework-PlatformIO-blue.svg)](https://platformio.org/)
[![Hardware: ESP32](https://img.shields.io/badge/Hardware-ESP32-orange.svg)](https://www.espressif.com/en/products/socs/esp32)

**AquaSense** is a comprehensive IoT solution dedicated to real-time water quality monitoring. This project showcases cross-disciplinary expertise combining **Software Engineering (C++/YAML)**, **Analog Electronics**, and **Mechanical Design (3D CAD)**.

---

## 🌟 Project Highlights

- **Multi-Framework Architecture**: Native support for **PlatformIO (Pure C++)** for low-level control, and **ESPHome** for seamless Home Automation (Home Assistant) integration.
- **Advanced Signal Processing**: Implementation of 3rd-degree polynomial regression algorithms for TDS (Total Dissolved Solids) and Turbidity sensors to ensure data accuracy.
- **Industrial Design**: Custom-designed, 3D-printed enclosures and sensor mounts optimized for durability and easy maintenance in aquatic environments.
- **Mission-Critical Safety**: Integrated hardware and software "Fail-safe" logic for pump control to prevent flooding or dry running.

---

## 🛠️ Technical Expertise

### 1. Electronics & Sensors
The system is built around the **ESP32** microcontroller, managing multiple data protocols:
- **OneWire**: High-precision communication with the DS18B20 thermal probe.
- **ADC (Analog to Digital Converter)**: Optimized reading of turbidity and TDS analog values with software attenuation for maximum 3.3V precision.
- **Relay Control**: High-power actuator management with built-in duty cycle protection.

### 2. Algorithms & Mathematics
To ensure laboratory-grade reliability, the firmware processes raw analog signals into meaningful data:
- **TDS Conversion**: Utilizes a 3rd-degree polynomial regression curve to compensate for the non-linear response of analog TDS probes.
- **Turbidity Calibration**: Scalable linear calibration to provide precise NTU (Nephelometric Turbidity Units) readings.

### 3. Mechanical Design (CAD)
Source files (FreeCAD/STEP) provide a modular and industrial enclosure system:
- **Modular Controller Hub**: A multi-part assembly including a main box with integrated cooling vents and dedicated internal supports for electronics.
- **Branded Top Cover**: Custom embossed branding with a sleek, minimalist aesthetic.
- **Versatile Mounting**: Features an `eccentric bolt` system for secure attachment to various aquatic environments (tanks, sumps, etc.).
- **Optimized Sensor Kits**: Protective mounts for TDS and Turbidity probes designed to minimize interference with water flow.

---

## 🔌 Circuitry & Schematics

The system architecture ensures galvanic isolation for the actuators and precise signal levels for the sensors. Below is the logical wiring diagram:

```mermaid
graph LR
    %% Définition des couleurs
    classDef power fill:#e74c3c,stroke:#c0392b,stroke-width:2px,color:#fff;
    classDef esp fill:#3498db,stroke:#2980b9,stroke-width:3px,color:#fff;
    classDef component fill:#ecf0f1,stroke:#bdc3c7,stroke-width:2px;
    classDef shifter fill:#f39c12,stroke:#e67e22,stroke-width:2px,color:#fff;

    %% Composants Principaux
    Alim[Bloc Alimentation 5V 5A]
    ESP[ESP32 Dev Board]

    %% Groupes logiques
    subgraph Bloc_Puissance [Circuit de Puissance 5V]
        Relais[Module Relais 1 Canal]
        Pompe[Pompe à Membrane 5V]
    end

    subgraph Interface_Isolation [Sécurité des Signaux]
        Shifter[Level Shifter 3.3V vers 5V]
    end

    subgraph Capteurs_33V [Capteurs 3.3V]
        Niveau[Niveau XKC-Y25]
        Temp[Température DS18B20]
        TDS[Capteur TDS]
        Turb[Capteur Turbidité]
    end

    %% --- CÂBLAGE ALIMENTATION ---
    Alim -- "+5V" --> ESP
    Alim -- "+5V" --> Relais
    Alim -- "+5V (HV)" --> Shifter

    %% --- CÂBLAGE MASSE ---
    Alim -- "GND" --> ESP
    Alim -- "GND" --> Relais
    Alim -- "GND" --> Pompe
    Alim -- "GND" --> Shifter

    %% --- LOGIQUE POMPE ---
    ESP -- "3.3V (LV1) -> GPIO 33" --> Shifter
    Shifter -- "5V (HV1)" --> Relais
    Relais -- "NO (+5V)" --> Pompe

    %% --- DISTRIBUTION 3.3V ---
    ESP -- "3.3V" --> Shifter
    ESP -- "3.3V" --> Niveau
    ESP -- "3.3V" --> Temp
    ESP -- "3.3V" --> TDS
    ESP -- "3.3V" --> Turb

    ESP -- "GND" --> Niveau
    ESP -- "GND" --> Temp
    ESP -- "GND" --> TDS
    ESP -- "GND" --> Turb

    %% --- DATA SIGNALS ---
    Niveau -- "GPIO 18" --> ESP
    Temp -- "GPIO 19 (Pull-up 4.7kΩ)" --> ESP
    TDS -- "GPIO 35" --> ESP
    Turb -- "GPIO 34" --> ESP

    %% --- APPLICATION DES STYLES ---
    class Alim power;
    class ESP esp;
    class Relais,Pompe,Niveau,Temp,TDS,Turb component;
    class Shifter shifter;
```

---

## 🔧 Assembly & Hardware

The AquaSense enclosure is designed for durability and ease of maintenance. 

### 1. Hardware Requirements
- **Fasteners**: M3 Stainless Steel screws are used throughout to prevent corrosion in humid environments.
- **Mounting**: Brass heat-set inserts can be used for the internal supports to allow repeated assembly/disassembly without stripping the plastic.
- **Connectivity**: A panel-mount USB-C extension provides a robust external power interface while keeping the ESP32 protected inside.

### 2. Assembly Steps
1.  **Preparation**: Install M3 heat-set inserts (optional) into the `Main Controller Box`.
2.  **Electronics**: Secure the ESP32 Dev Board onto the `Electronic Card Support` tray.
3.  **Integration**: Slide the electronic tray into the main box and secure the cables through the dedicated ports.
4.  **Sealing**: Install the `Back Cover` for cable management and the `Top Cover` for final protection.
5.  **Deployment**: Use the `Eccentric Bolt` system to clamp the unit onto your tank or sump.

For a full list of components, see the [Bill of Materials (BOM)](BOM.md).

---

## 📂 Project Structure

```bash
├── 📂 firmware           # Firmware source code
│   ├── 📂 cpp            # Pure C++ Firmware (PlatformIO)
│   └── 📂 esphome        # Infrastructure as Code (YAML)
├── 📂 cad                # CAD Files (STL, STEP, FCStd)
├── 📂 assets            # Project images and diagrams
├── 📂 .github           # CI/CD Pipelines
└── LICENSE              # MIT License
```

---

## ⚙️ Installation & Deployment

### Option A: ESPHome (Recommended for Home Assistant)
1. Install ESPHome: `pip install esphome`
2. Copy `firmware/esphome/secrets.yaml.example` to `firmware/esphome/secrets.yaml` and fill in your credentials.
3. Deploy: `esphome run firmware/esphome/aquasense.yaml`

### Option B: PlatformIO (For C++ Development)
1. Open the `firmware/cpp` folder in VS Code with PlatformIO.
2. Compile and flash to your ESP32.

---

## 📊 Gallery & Showcase

| Industrial Enclosure | Branded Top Cover | Home Assistant Dashboard |
| :---: | :---: | :---: |
| ![Front View](assets/render_front_bottom.png) | ![Top View](assets/render_top_logo.png) | ![Dashboard](assets/dashboard.png) |

---

## 📝 License

This project is released under the **MIT License**. Feel free to use, modify, and distribute it for your own projects.

---

## 👤 Contact & Portfolio

**Enzo Gaggiotti**
- **Specialization**: IoT, Infrastructure, DevSecOps.
- [GitHub Profile](https://github.com/enzogagg)
