# ESP32Servo

A lightweight C++ library to control servo motors with PWM using ESP32's built-in `ledc` module.  
This library allows you to control multiple servo motors with customizable resolution and frequency.

## 📦 Features

- Supports multiple servos (each on its own PWM channel)
- Customizable PWM frequency (default: 50 Hz)
- Customizable resolution (default: 10 bits)
- Control via microseconds (like `writeMicroseconds(1500)`)

## 📁 Project Structure

```text

ESP32Servo/
├── src/
│   ├── ESP32Servo.h
│   └── ESP32Servo.cpp
├── README.md
├── library.properties

```

## 🚀 Installation

Copy the `ESP32Servo` folder into your Arduino `libraries` directory or install it as a PlatformIO library.

## 🧰 Usage

### Include the library

```cpp

#include <ESP32Servo.h>
```

### Example: Controlling a single servo

```cpp
ESP32Servo myServo;

void setup() {
  ESP32Servo::setFrequency(50);     // Set frequency to 50Hz (typical for servos)
  ESP32Servo::setResolution(10);    // Set resolution to 10 bits

  myServo.attach(13, 0);            // Attach servo to pin 13, channel 0
  myServo.writeMicroseconds(1500);  // Center the servo
}

void loop() {
  myServo.writeMicroseconds(1000);  // Move to one end
  delay(1000);
  myServo.writeMicroseconds(2000);  // Move to the other end
  delay(1000);
}
```

### Controlling Multiple Servos

Just create multiple instances of `ESP32Servo`, each with its own pin and channel.

## 🛠️ API Reference

| Method                  | Description                                       |
| ----------------------- | ------------------------------------------------- |
| `attach(pin, channel)`  | Attach servo to GPIO pin and PWM channel          |
| `writeMicroseconds(us)` | Send pulse width in microseconds (e.g. 1000–2000) |
| `setFrequency(freqHz)`  | Set global PWM frequency                          |
| `setResolution(bits)`   | Set global PWM resolution in bits (e.g. 8–16)     |

## 🧪 Tested On

- ESP32 DEVKIT DOIT V1

- Arduino IDE & PlatformIO

## 📜 License

MIT License
