STM32-Based 2A Ammeter with OLED Display and INA219 Current Sensor
This repository contains the full design, code, and hardware files for an ammeter project that measures currents up to 2A using an STM32 microcontroller, an INA219 current sensor, and displays real-time data on an OLED screen. The system features an adjustable load using a 10k potentiometer in series with a 330-ohm resistor, which is used for testing and calibration.

Features
Precise Current Measurement: Measures currents from 0A up to 2A using the INA219 current sensor.
Real-Time OLED Display: Current readings are displayed in real time on an OLED screen for immediate feedback.
Adjustable Load: A 10k potentiometer connected in series with a 330-ohm resistor allows for a tunable load, making the system versatile for various applications.
Protection: The series resistor protects the potentiometer from excessive current to prevent overheating or damage.
Modular Design: The design allows for easy future improvements, both in hardware and software.

Hardware
Components Required:
STM32 Microcontroller (any STM32 model that supports I2C communication, such as STM32F103, STM32F429)
INA219 Current Sensor: For accurate current and voltage measurement.
OLED Display: 128x64 OLED or similar (I2C interface).
330-ohm Resistor: Used in series with the potentiometer to limit current.
10k Potentiometer: Adjustable load for testing the current measurement range.
Power Supply: 3.3V (or according to your STM32 board).

Software:
Microcontroller Code:
Platform: STM32 using CMSIS and STD Peripheral library on IAR Embedded Workbench.

Libraries:
INA219 sensor library for I2C communication.
OLED display library (e.g., U8g2 or Adafruit SSD1306).

Functionality:
Initializes the INA219 for current measurements.
Reads current data and processes it on the STM32.
Displays the current value on the OLED in real-time.

Circuit Design
The circuit consists of:
The INA219 sensor is connected to the STM32 via I2C.
A 330-ohm resistor is placed in series with a 10k potentiometer to create an adjustable load.
The STM32 reads the current value from the INA219 and updates the OLED display.
Important Note: The 330-ohm resistor is used to protect the potentiometer from excessive current. Without this series resistor, the potentiometer could be damaged, as it may not be rated for high current.

Links
YouTube: https://www.youtube.com/watch?v=oZrPufdU3gE&ab_channel=MucahitEmbeddedSystems
Documentation: Detailed usage and wiring instructions can be found in the repository files.
License
This project is licensed under the MIT License - see the LICENSE file for details.
