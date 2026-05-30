#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";

WebServer server(80);
Servo servoMotor;

const int servoPin = 18;
int currentAngle = 90;

void handleRoot() {
  String html = "";
  html += "<!DOCTYPE html><html>";
  html += "<head><title>Smart Servo Controller</title>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
  html += "<style>body{font-family:Arial;text-align:center;margin-top:50px;background:#f4f4f4;}";
  html += ".box{background:white;padding:30px;border-radius:12px;display:inline-block;box-shadow:0 4px 12px #ccc;}";
  html += "button{padding:15px 30px;margin:10px;font-size:18px;border:none;border-radius:8px;cursor:pointer;}";
  html += ".lock{background:#ef4444;color:white;}.unlock{background:#22c55e;color:white;}</style></head>";
  html += "<body><div class='box'><h1>Smart Servo Controller</h1>";
  html += "<p>Current Angle: " + String(currentAngle) + " degrees</p>";
  html += "<a href='/lock'><button class='lock'>LOCK</button></a>";
  html += "<a href='/unlock'><button class='unlock'>UNLOCK</button></a>";
  html += "</div></body></html>";
  server.send(200, "text/html", html);
}

void handleLock() {
  currentAngle = 0;
  servoMotor.write(currentAngle);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleUnlock() {
  currentAngle = 90;
  servoMotor.write(currentAngle);
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);
  servoMotor.attach(servoPin);
  servoMotor.write(currentAngle);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Connected to WiFi");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/lock", handleLock);
  server.on("/unlock", handleUnlock);
  server.begin();
}

void loop() {
  server.handleClient();
}
