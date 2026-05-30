# Smart Servo IoT Controller Project Report

## Introduction
The Smart Servo IoT Controller is a personal embedded systems project developed during my free time. It explores the use of ESP32, WiFi communication, browser-based interfaces, and servo motor control.

## Problem Statement
Traditional servo control requires direct physical access or wired control. This project explores how a servo motor can be controlled wirelessly through a simple web interface.

## Objective
The main objective was to build a low-cost IoT prototype that demonstrates remote hardware control using an ESP32 microcontroller.

## Methodology
The project was developed in two stages.

### Version 1
A basic web interface was embedded directly into the Arduino firmware. This allowed simple lock and unlock control through a browser.

### Version 2
The system was improved with a separated frontend interface, API endpoints, and a modern dashboard design.

## Hardware Design
The ESP32 outputs a PWM signal to the servo motor through GPIO18. The servo receives power from the 5V supply and shares a common ground with the ESP32.

## Software Design
The ESP32 runs a web server. In Version 1, the HTML is embedded in the Arduino code. In Version 2, the ESP32 serves separate frontend files and responds to API requests.

## Challenges
- Understanding ESP32 WiFi configuration
- Controlling servo movement reliably
- Structuring frontend and firmware logic
- Designing a clean user interface
- Avoiding hardcoded sensitive credentials

## Conclusion
This project strengthened my understanding of embedded systems, IoT communication, microcontroller programming, and web-based hardware control.
