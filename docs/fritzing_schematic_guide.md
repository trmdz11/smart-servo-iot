# Fritzing Schematic Guide

## Diagram to Recreate in Fritzing
Use the wiring shown in `images/wiring_diagram.svg`.

## Components to Add
1. ESP32 development board
2. SG90 servo motor
3. Breadboard
4. Jumper wires
5. Optional external 5V power supply

## Connections
| ESP32 | Servo Motor |
|---|---|
| GPIO18 | Signal |
| 5V | VCC |
| GND | GND |

## Wire Colors
- Signal wire: Blue or orange
- VCC wire: Red
- GND wire: Black or grey

## Important
If the servo motor behaves unpredictably, use an external 5V power source. The ESP32 and external power source must share a common ground.

## Suggested Diagram Title
Smart Servo IoT Controller Wiring Diagram
