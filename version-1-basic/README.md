# Version 1: Basic Web Interface

## Overview
This version represents the original basic concept of the Smart Servo IoT Controller. The ESP32 hosts a simple web page directly from the Arduino firmware. Users can access the ESP32 IP address from a browser and control the servo motor using basic buttons.

## Features
- Simple browser-based control
- Embedded HTML inside Arduino code
- Servo lock and unlock buttons
- WiFi connection through ESP32
- Lightweight implementation

## How It Works
1. ESP32 connects to WiFi.
2. ESP32 starts a web server.
3. User opens the ESP32 IP address in a browser.
4. Browser displays a basic control page.
5. Button clicks send requests to the ESP32.
6. ESP32 moves the servo motor.

## Portfolio Description
This basic version was developed during my free time to explore IoT and embedded systems. It demonstrates how a microcontroller can host a simple web interface and control a physical servo motor through WiFi.
