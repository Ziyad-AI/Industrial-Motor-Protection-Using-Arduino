# Industrial Motor Protection System Using Arduino

## 📌 Project Overview
This project is an Arduino-based industrial motor protection prototype designed to prevent motor damage caused by overheating and overload conditions.

## 🏭 Problem Statement
Industrial motors are vulnerable to failure due to excessive temperature rise and abnormal current draw. Such failures lead to unexpected downtime and financial loss.

## ⚙ System Architecture
The system continuously monitors:
- Motor Temperature (LM35 Sensor)
- Motor Current (Analog Current Sensor)

If any parameter exceeds predefined threshold values, the system:
- Deactivates motor via relay
- Activates buzzer alarm
- Displays fault message via Serial Monitor

## 🛠 Hardware Components
- Arduino UNO
- LM35 Temperature Sensor
- Current Sensor
- Relay Module
- Buzzer

## 💻 Software Used
- Arduino IDE
- Embedded C Programming

## 🔄 Working Logic
1. Read sensor data
2. Convert analog values
3. Compare with threshold limits
4. Trigger protection mechanism if abnormal condition detected

## 🚀 Future Scope
- IoT-based remote monitoring
- Cloud data logging
- Predictive maintenance analytics
- GSM fault notification system
