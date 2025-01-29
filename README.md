# Smart_AntiPoison_Cup 

**Arduino-based smart anti-poison detection cup using pH sensors, OLED display, LED light, and servo motor.**

##  Features
-  **Detects pH Level**: Checks for unsafe pH values in liquids.
-  **LED Warning System**: Blinks if pH is out of safe range.
-  **OLED Display**: Shows pH readings in real-time.
-  **Servo Motor Activation**: Closes lid when poison is detected.

##  Hardware Components
- **pH Sensor** (measures the acidity/basicity of liquid)
- **OLED Display** (shows pH readings)
- **LED Light** (alerts when pH is unsafe)
- **Servo Motor** (automatically locks lid)

##  Code Example
```cpp
float pHValue = 7 + ((2.5 - voltage) / 0.167);
Serial.print("pH Value: ");
Serial.println(pHValue);
## 🔄 Installation & Usage

1. **Clone this repository**:
   ```bash
   git clone https://github.com/LangM1ao/Smart_AntiPoison_Cup.git

2.  **Open smart_cup.ino in Arduino IDE.**

3.  **Connect your Arduino board.**

4.  **Upload the code to your device.**

5.  **Check the OLED display for pH readings!**

---

## 📜 License
This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

---

## 🤝 Contributing
Contributions are **welcome**!  
1. **Fork this repository** 📌  
2. **Create a new branch** (`git checkout -b feature-branch`)  
3. **Commit your changes** (`git commit -m "Added new feature"`)  
4. **Push to GitHub** (`git push origin feature-branch`)  
5. **Create a Pull Request**  

---

## 👤 Author
👨‍💻 Created by **LangM1ao**  
🔗 GitHub: [LangM1ao](https://github.com/LangM1ao)
