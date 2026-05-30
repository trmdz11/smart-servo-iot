# Version 2: Enhanced Scalable Interface

## Overview
This version improves the original Smart Servo IoT Controller by separating the frontend from the firmware. The interface includes a modern dashboard, angle slider, preset buttons, device status display, and activity log.

## Features
- Separate HTML, CSS, and JavaScript files
- Modern dashboard UI
- Servo angle slider
- Preset angle buttons
- Real-time status updates
- Activity log display
- Scalable file structure

## How It Works
1. ESP32 connects to WiFi.
2. ESP32 serves frontend files from SPIFFS.
3. Browser loads the dashboard interface.
4. JavaScript sends requests to the ESP32.
5. ESP32 updates the servo angle.
6. Dashboard reflects the latest command.

## Portfolio Description
This enhanced version expands the original project into a more scalable IoT dashboard. It separates firmware and frontend logic, improving maintainability and making the system easier to upgrade in the future.
