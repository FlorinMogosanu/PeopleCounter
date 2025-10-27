# 📟 People Counter

This project details the construction of an Arduino-based digital people counter, designed to monitor and manage access within a defined space. To offer flexibility, the project was created in two variants: a full version, which uses an LCD display with an I2C interface for real-time visual feedback, and a second minimalist version, without a display.

The main goal is to provide an efficient solution for counting people, solving the problem of capacity management in locations such as stores, conference rooms, or small events.



---
## ✨ Key Features

* **🔐 Password Authentication:** Prevents unauthorized operation of the counter.
* **🔢 Manual Counting:** Dedicated buttons for incrementing and decrementing the number of people.
* **📈 Set Maximum Limit:** The authorized user can set a maximum occupancy limit.
* **💡 LED Alert:** An LED (in both versions) indicates the status (e.g., limit reached).
* **✌️ Two Versions:**
    * *LCD Version:* Displays the current count, limit, and status on an LCD screen.
    * *Serial Monitor Version:* A minimalist version, without an LCD, which reports the status via the Arduino IDE's Serial Monitor.
      
---

## 🎥 Project Demo

Watch the video below to see the project in action, demonstrating both the LCD and Serial Monitor versions.

**[🔗 Watch the Project Demo on YouTube](LINK_CATRE_YOUTUBE)**

---

## 🛠️ Required Components

* Arduino UNO
* Breadboard
* 4x4 Keypad
* 3 x Push Buttons
* 1 x LED
* 1 x 220 Ω Resistor
* Jumper wires
* (Optional) 16x2 LCD Display with I2C module

---

## 🤖 Tinkercad Versions & Simulations

The project is available in two configurations. You can access the connection diagram, source code, and live simulation for each version on Tinkercad:

1.  **I2C LCD Version**

    This version provides complete visual feedback on an LCD screen, displaying the current number of people, the set maximum limit, and status messages.

    🔗 **[Access the Tinkercad Project (LCD Version)](https://www.tinkercad.com/things/8FEf5qmovq3-peoplecounterlcd?sharecode=uWe_OX7uKhxNCmx7V0eGeWhqBQdnMWAdLNvE5qi2tNY)**

2.  **No LCD Version (Minimalist)**

    This minimalist version operates without a display. All interactions (password confirmation, setting the limit, current count) are communicated through the Arduino IDE's Serial Monitor.

    🔗 **[Access the Tinkercad Project (Serial Monitor Version)](https://www.tinkercad.com/things/4Gp6lyKljIT-peoplecounterserialmonitor?sharecode=zfMz3hoVoag6uf6rjem5o9vwPaEnICcV_d4_Z1VHTf0)**
