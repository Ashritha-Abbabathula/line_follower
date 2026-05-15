# 🚗 Line Follower Robot

![Arduino](https://img.shields.io/badge/Arduino-Uno-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![Language](https://img.shields.io/badge/Language-C%2B%2B%2FArduino-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen?style=for-the-badge)

An Arduino-based autonomous robot that follows a black line on a white surface using two IR sensors, with intelligent last-direction recovery when the line is lost.

---

## 📸 Demo

> _Add photos/videos of the robot in action here_

![Front view](assets/Image1.jpg)
![Side view](assets/Image2.jpg)
![Working demo](assets/Video3.mp4)

---

## ⚙️ How It Works

The robot reads two IR sensors mounted at the front. Based on which sensor detects the line, it steers the motors accordingly:

| Left IR | Right IR | Action |
|---------|----------|--------|
| ON | ON | Move straight |
| ON | OFF | Turn left |
| OFF | ON | Turn right |
| OFF | OFF | Recover using last known direction |

When both sensors lose the line, the robot uses the **last turn direction** to recover — rather than stopping or spinning randomly.

---

## 🧰 Components

| Component | Quantity |
|-----------|----------|
| Arduino Uno | 1 |
| IR Sensor Module | 2 |
| L298N Motor Driver | 1 |
| DC Motors | 2 |
| Chassis + Wheels | 1 set |
| 9V / Li-ion Battery | 1 |
| Jumper Wires | As needed |

---

## 📌 Pin Configuration

| Pin | Function |
|-----|----------|
| A0 | Left IR Sensor |
| A5 | Right IR Sensor |
| 13 | ENA (Right Motor Enable) |
| 8 | IN1 |
| 7 | IN2 |
| 12 | ENB (Left Motor Enable) |
| 6 | IN3 |
| 4 | IN4 |

---

## 🔌 Circuit Diagram

> _Add your circuit diagram image here_

<!-- ![Circuit](assets/circuit.png) -->

---

## 🚀 Getting Started

### Prerequisites
- [Arduino IDE](https://www.arduino.cc/en/software)
- Arduino Uno board

### Upload the Code
1. Clone this repository:
   ```bash
   git clone https://github.com/Ashritha-Abbabathula/line_follower.git
   ```
2. Open `track_runner.ino` in the Arduino IDE
3. Select **Board**: Arduino Uno and the correct **Port**
4. Click **Upload**

---

## 🎛️ Tuning Parameters

You can adjust these constants in `track_runner.ino` to suit your surface and motors:

```cpp
const int IR_THRESHOLD = 500;   // Adjust based on your IR sensor sensitivity
const int BASE_SPEED   = 100;   // Forward speed (0–255)
const int TURN_SPEED   = 110;   // Turning speed (0–255)
```

---

## 📁 File Structure

```
line_follower/
├── track_runner.ino      # Main Arduino sketch
├── assets/               # Photos, videos, circuit diagrams
│   ├── Image1
│   └── Image2
│   └── Video1
│   └── Video2
│   └── Video3
└── README.md
```

---

## 👩‍💻 Author

**Ashritha Abbabathula**  
[![GitHub](https://img.shields.io/badge/GitHub-Ashritha--Abbabathula-181717?style=flat&logo=github)](https://github.com/Ashritha-Abbabathula)

---

## 📄 License

This project is open source and available under the [MIT License](LICENSE).
