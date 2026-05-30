# Hardware Components

## Required Components
- ESP32 development board
- SG90 servo motor or similar
- Breadboard
- Jumper wires
- USB cable
- Optional external 5V power source

## Wiring
| ESP32 Pin | Component | Description |
|---|---|---|
| GPIO18 | Servo Signal | Sends PWM control signal |
| 5V | Servo VCC | Powers servo motor |
| GND | Servo GND | Common ground |

## Important Note
For more reliable servo operation, use an external 5V supply for the servo and connect the external supply ground to ESP32 ground.
