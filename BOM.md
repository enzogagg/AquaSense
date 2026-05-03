# Bill of Materials (BOM) - AquaSense

This document lists all the components required to build the AquaSense monitoring system.

## 1. Electronics

| Component | Description | Qty | Note |
| :--- | :--- | :---: | :--- |
| **ESP32 DevKit V1** | Main Microcontroller (WiFi/BT) | 1 | |
| **DS18B20 Probe** | Waterproof Temperature Sensor | 1 | OneWire protocol |
| **Analog TDS Sensor** | Total Dissolved Solids sensor | 1 | Includes adapter board |
| **Turbidity Sensor** | Analog Turbidity Sensor | 1 | Includes adapter board |
| **Liquid Level Sensor** | XKC-Y25 Photoelectric | 1 | Non-contact level sensing |
| **Level Shifter** | 4-channel 3.3V <-> 5V | 1 | For Relay/Pump logic |
| **Relay Module** | 5V Single Channel Relay | 1 | For pump control |
| **Resistor 4.7kΩ** | Pull-up resistor for OneWire | 1 | For DS18B20 |
| **Power Supply** | 5V 5A DC Adapter | 1 | High current for pump/relays |

## 2. Mechanical & 3D Printing

| Part | Material | Qty | Note |
| :--- | :--- | :---: | :--- |
| **Main Controller Box** | PETG / PLA | 1 | Industrial design with cooling vents |
| **Top Cover** | PETG / PLA | 1 | Features embossed branding |
| **Back Cover** | PETG / PLA | 1 | Cable management and port access |
| **Electronic Card Support** | PETG / PLA | 1 | Internal tray for ESP32 mounting |
| **Eccentric Bolt** | PETG / PLA | 1 | Custom clamping mechanism |
| **Sensor Holder (TDS)** | PETG / PLA | 1 | Custom mount |
| **Sensor Holder (Turbidity)** | PETG / PLA | 1 | Custom mount |
| **Temperature Probe Clip** | PETG / PLA | 1 | |

## 3. Hardware & Fasteners

| Item | Type | Qty | Note |
| :--- | :--- | :---: | :--- |
| **M3 Screws** | Stainless Steel | 6-8 | For covers and internal mounts |
| **M3 Heat-Set Inserts** | Brass | 6-8 | Optional - For superior durability |
| **USB-C Extension** | Panel Mount | 1 | (As seen in CAD) For external power |

## 4. Miscellaneous

- Jumper Wires (Dupont) or Custom PCB
- Waterproof glands (for sensor cables)
- Solder & Soldering Iron
- **3D Printing Filament**: PETG is strongly recommended for its water resistance and mechanical strength.
