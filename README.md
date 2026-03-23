# Climate Control System

## Description
This project is a **Temperature-Based Climate Control System** built with Arduino.  
It reads temperature from a **DHT22 sensor** and controls a **stepper motor** to regulate airflow based on the measured temperature.

---

## Features
- Turns the motor **OFF** below 27°C  
- Gradually **increases motor speed** from 27°C to 40°C  
- Runs at **maximum speed** above 40°C  
- Serial monitor prints **temperature and PWM values** for monitoring  
- Simulation available on **Wokwi**  

---

## Hardware Required
- Arduino Uno (or compatible board)  
- DHT22 Temperature Sensor  
- Stepper Motor  
- A4988 Stepper Motor Driver  
- Jumper Wires  
- Breadboard (optional)

---

## Circuit Connections
- **DHT22 Data Pin → Arduino Pin 2**  
- **Stepper Motor STEP → Arduino Pin 9**  
- **Stepper Motor DIR → Arduino Pin 8**  
- Power supply for stepper motor according to motor specs  

*(Add a schematic or picture here if you want.)*

---

## Code
- `sketch.ino` contains the Arduino program.  
- Upload using the **Arduino IDE** or **Wokwi simulator**.

---

## How It Works
1. Arduino reads temperature from DHT22.  
2. `tempToPWM()` maps temperature to PWM values (0–255).  
3. Stepper motor speed is adjusted using **delayMicroseconds** based on PWM.  
4. Temperature and PWM values are printed to the Serial Monitor every 500ms.

---

## Simulation
- You can simulate the project on **[Wokwi]((https://wokwi.com/projects/459215377240700929))**. 
- Use the Serial Monitor in Wokwi to view temperature and PWM output.

---

## Author
**Sharan K U**
