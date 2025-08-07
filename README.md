# ESP32 BLE HID Device

This Arduino project implements a Bluetooth Low Energy (BLE) Human Interface Device (HID). It allows your ESP32 board to function as a Bluetooth input device like Mr. Robot USB Rubber Ducky.

## Features

- Bluetooth Low Energy (BLE) connectivity
- HID protocol implementation
- Low power consumption
- Easy to customize input configurations
- Multiple triggers (3 GPIO pins) for different payloads
- Simple hardware trigger mechanism using jumper wires

## Requirements

### Hardware
- ESP32 Board: https://amzn.to/47p9iie
- Micro USB cable for programming: https://amzn.to/457DnBF
- Jumper wires for trigger connections: https://amzn.to/45FinSU

Disclosure: I earn small amount from qualifying purchases as an Amazon Associate.

### Hardware Connections
1. Connect one jumper wire from GND pin
2. Connect other jumper wires to GPIO pins: as your requirement.
   - Trigger 1: GPIO 16
   - Trigger 2: GPIO 17
   - Trigger 3: GPIO 18
3. When you want to activate a trigger, touch both jumper wires

### Software
- Arduino IDE: https://www.arduino.cc/en/software/

### Arduino IDE Setup
1. Open Arduino IDE Preferences
2. Add ESP32 board URL in Additional Board Manager URLs:
   ```
   https://espressif.github.io/arduino-esp32/package_esp32_index.json
   ```
3. Go to Tools -> Board Manager
4. Search for "ESP32" and install version 2.0.15

### Required Libraries
1. ESP32 BLE Keyboard Library:
   - Download from: https://github.com/T-vK/ESP32-BLE-Keyboard
   - In Arduino IDE: Sketch -> Include Library -> Add .ZIP Library
   - Select the downloaded library file

## Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/[your-username]/blehid.git
   ```
2. Open `blehid.ino` in Arduino IDE
3. Select your board and port - ESP32-Dev Module
4. Upload the code to your Arduino board

## Usage

1. Power up your Arduino board
2. The device will start advertising as a BLE HID device
3. Connect to the device from your computer/tablet/phone's Bluetooth settings
4. Activate the trigger

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## Disclaimer

This project is intended for educational purposes only. I'm not responsible for any actions or consequences resulting from the use of this code. Users are responsible for ensuring compliance with all applicable laws and regulations when using this project.

## Acknowledgments

- Arduino community for their excellent libraries and documentation
- Contributors to the BLE HID specifications
