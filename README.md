
---

## 🔌 Automatic Load Sharing of Transformer with Protection (Arduino)

### 📖 Project Overview

This project presents an **Arduino-based Automatic Load Sharing System** for transformers with built-in **overload and overheat protection**. It ensures efficient power distribution by balancing load between multiple transformers and protecting them from damage due to excessive current or temperature.

### ⚙️ Features

* 🔄 Automatic load sharing between transformers
* ⚡ Overload detection and protection
* 🌡️ Overheat monitoring using temperature sensors
* 🖥️ Real-time data display on LCD
* 🤖 Fully automated system using Arduino
* 🔒 Improves transformer safety and lifespan

### 🧠 How It Works

The system uses an **Arduino microcontroller** to continuously monitor current and temperature of each transformer.

* If one transformer becomes **overloaded**, the system transfers part of the load to another transformer using relays.
* If the temperature exceeds a safe limit, the system **disconnects the transformer** to prevent overheating damage.

This ensures balanced operation and protects the system from failure.

### 🧰 Components Used

* Arduino Uno
* Current Sensor (INA219 / ACS712)
* Temperature Sensor (LM35 / DS18B20)
* Relay Module
* LCD Display (16x2 I2C)
* Power Supply
* Transformers (for demonstration)

### 🖼️ System Diagram

<img width="479" height="230" alt="image" src="https://github.com/user-attachments/assets/88da4242-52e4-444c-8def-afc622adadb9" />


### 💻 Code

The Arduino code is available in this repository. It reads sensor data, processes conditions, and controls relays accordingly.

### 🚀 Applications

* Power distribution systems
* Industrial transformer protection
* Smart grid systems
* Load management systems

### 📌 Future Improvements

* IoT-based remote monitoring
* Mobile app integration
* Fault detection with alerts

### 👨‍💻 Author



-Arafat Hossain Rupok--

