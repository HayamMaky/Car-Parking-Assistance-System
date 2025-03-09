# Car Parking Sensor Using ATmega32, Ultrasonic Sensor, LCD Display, LEDs, and Buzzer

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Hardware Components](#hardware-components)
- [Operation Description](#operation-description)
- [System Requirements](#system-requirements)
- [Drivers Requirements](#drivers-requirements)
- [Installation & Usage](#installation--usage)
- [Contributors](#contributors)

---

## Overview
The Car Parking Sensor project is designed to help drivers detect obstacles and avoid collisions while parking. This system uses an ATmega32 microcontroller to process distance measurements from an ultrasonic sensor, displaying the results on an LCD. Visual and auditory warnings are provided by three LEDs and a buzzer as an obstacle gets closer.

---

## Features
- **Ultrasonic Distance Measurement**: Measures the distance between the car and obstacles using an HC-SR04 ultrasonic sensor.
- **LCD Display**: Shows the measured distance in centimeters and displays "Stop" if the distance is less than 5 cm.
- **LED Indicators**: Three LEDs (Red, Green, and Blue) indicate proximity with different behaviors.
- **Buzzer Alert**: Sounds when an obstacle is too close (≤ 5 cm).
- **Dynamic LED Behavior**:
  - **Distance ≤ 5 cm**: All LEDs flash, buzzer sounds, and LCD displays "Stop."
  - **6 cm ≤ Distance ≤ 10 cm**: All LEDs remain ON; no buzzer.
  - **11 cm ≤ Distance ≤ 15 cm**: Red and Green LEDs ON; Blue LED OFF.
  - **16 cm ≤ Distance ≤ 20 cm**: Only the Red LED ON.
  - **Distance > 20 cm**: All LEDs and buzzer remain OFF.

---

## Hardware Components
- **Microcontroller**: ATmega32
- **Ultrasonic Sensor**: HC-SR04
- **LCD Display**: 16x2 LCD in 4-bit mode
- **LEDs**: Red, Green, and Blue LEDs
- **Buzzer**

### Pin Connections
- **ATmega32:**
  - **LCD Display:**
    - RS: PA1
    - E: PA2
    - Data (D4-D7): PA3, PA4, PA5, PA6
  - **LEDs:**
    - Red LED: PC0
    - Green LED: PC1
    - Blue LED: PC2
  - **Buzzer:**
    - Connected to PC5 (via transistor control)
  - **Ultrasonic Sensor:**
    - Echo: PD6
    - Trigger: PD7

---

## Operation Description
- The ultrasonic sensor emits an ultrasonic wave and listens for its reflection from nearby objects.
- The ATmega32 calculates the distance by measuring the time taken for the echo to return.
- The measured distance is continuously displayed on the LCD in centimeters.
- Based on the distance, the system controls the LEDs and buzzer as follows:
  - **Distance ≤ 5 cm:** All LEDs flash, buzzer sounds, and LCD shows "Stop."
  - **6 cm ≤ Distance ≤ 10 cm:** All LEDs are turned ON; buzzer remains off.
  - **11 cm ≤ Distance ≤ 15 cm:** Red and Green LEDs ON; Blue LED OFF.
  - **16 cm ≤ Distance ≤ 20 cm:** Only the Red LED is ON.
  - **Distance > 20 cm:** All LEDs and buzzer remain OFF.

---

## System Requirements
- **Microcontroller:** ATmega32
- **System Frequency:** 16 MHz
- The project is implemented using a layered model architecture.

---

## Drivers Requirements

### GPIO Driver
- Configure and control pin directions for sensors, LEDs, LCD, and buzzer.

### ICU (Input Capture Unit) Driver
- Configure the ICU with a frequency of F_CPU/8 and detect the rising edge as the first edge.
- Integrate `ICU_init` and `ICU_setCallBack` functions within the ultrasonic driver.

### Buzzer Driver
- **Functions:**
  - `void Buzzer_init(void)`: Initialize the buzzer pin and turn off the buzzer.
  - `void Buzzer_on(void)`: Activate the buzzer.
  - `void Buzzer_off(void)`: Deactivate the buzzer.
- The buzzer pin is configurable to any microcontroller port and pin.

### LCD Driver
- Use the 4-bit mode LCD driver.
- **Pin Configuration:**
  - RS: PA1
  - E: PA2
  - Data (D4-D7): PA3, PA4, PA5, PA6
- The LCD displays the distance in centimeters and shows "Stop" when the distance is less than 5 cm.

### Ultrasonic Driver
- **Functions:**
  - `void Ultrasonic_init(void)`: Initialize the ICU, set the callback, and configure the trigger pin as output.
  - `void Ultrasonic_Trigger(void)`: Send the trigger pulse to the ultrasonic sensor.
  - `uint16 Ultrasonic_readDistance(void)`: Trigger the sensor, start measurement via the ICU driver, and return the measured distance in centimeters.
  - `void Ultrasonic_edgeProcessing(void)`: Callback function for the ICU to calculate the pulse duration.
- The trigger pin is configurable to any microcontroller port and pin.

---

## Installation & Usage
1. Assemble the hardware according to the provided pin connections.
2. Compile the project using your preferred AVR development environment (e.g., Atmel Studio or AVR-GCC).
3. Flash the compiled firmware to the ATmega32 using a USB programmer.
4. Power on the system to begin real-time distance measurement and alert operations.
