# 🚀 Ultrasonic Distance Sensor (HC-SR04) Project

A clean, robust C++ implementation for measuring distances using the **HC-SR04** ultrasonic sensor with microcontrollers (Arduino / ESP32). Features timeout handling for out-of-range detection and accurate distance calculations.

---

## 📌 Features

- ⚡ **Real-time Measurements:** Continuous distance sampling with a smooth 200 ms interval.
- 🛡️ **Timeout Handling:** Prevents code stalling when no object is within range using a 30 ms pulse timeout (~5 meters max range).
- 📐 **Accurate Calculation:** Uses the standard speed of sound in air ($0.034 \text{ cm}/\mu\text{s}$) for precise measurements.

---

## 🛠️ Hardware Wiring

| Sensor HC-SR04 | Microcontroller Pin (e.g., ESP32 / Arduino) |
| :--- | :--- |
| **VCC** | 5V / 3.3V |
| **TRIG** | Pin 5 |
| **ECHO** | Pin 18 |
| **GND** | GND |

---

## 💻 Source Code

```cpp
#define TRIG 5
#define ECHO 18   

// Speed of sound constant (cm/us)
#define SOUND_SPEED 0.034

void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);

  // Configure pin modes
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  // Ensure trigger pin starts LOW
  digitalWrite(TRIG, LOW);
  
  Serial.println("HC-SR04 ready to measure distance...");
}

void loop() {
  // Send a 10-microsecond HIGH pulse to trigger
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Read the duration of HIGH pulse on ECHO pin (timeout set to 30ms = 5m max range)
  long duration = pulseIn(ECHO, HIGH, 30000);

  // Check if signal timed out (no object in range)
  if (duration == 0) {
    Serial.println("Tidak ada objek (out of range)");
  } else {
    // Calculate distance in centimeters
    float distance = duration * SOUND_SPEED / 2;

    // Display result on Serial Monitor
    Serial.print("Jarak: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  // Delay before next measurement
  delay(200);
}
```

---

## 📐 Formula & Mathematics

The distance calculation is derived from the formula for speed, distance, and time:

$$\text{Distance (cm)} = \frac{\text{Pulse Duration }(\mu\text{s}) \times 0.034 \text{ cm}/\mu\text{s}}{2}$$

> **Note:** The division by $2$ accounts for the sound wave traveling to the object and back to the sensor.

---

## 🖥️ Expected Serial Output

```text
HC-SR04 ready to measure distance...
Jarak: 12.45 cm
Jarak: 12.50 cm
Tidak ada objek (out of range)
Jarak: 45.10 cm
```
