#include <WiFi.h>
#include <WebServer.h>
#include <SPIFFS.h>
#include <ESP32Servo.h>

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";

WebServer server(80);
Servo servoMotor;

const int servoPin = 18;
int currentAngle = 90;

void serveFile(const char* path, const char* contentType) {
  File file = SPIFFS.open(path, "r");
  if (!file) {
    server.send(404, "text/plain", "File not found");
    return;
  }
  server.streamFile(file, contentType);
  file.close();
}

void handleSetAngle() {
  if (!server.hasArg("angle")) {
    server.send(400, "application/json", "{\"error\":\"Missing angle parameter\"}");
    return;
  }
  int angle = server.arg("angle").toInt();
  if (angle < 0 || angle > 180) {
    server.send(400, "application/json", "{\"error\":\"Angle must be between 0 and 180\"}");
    return;
  }
  currentAngle = angle;
  servoMotor.write(currentAngle);
  String response = "{";
  response += "\"angle\":" + String(currentAngle) + ",";
  response += "\"status\":\"updated\"";
  response += "}";
  server.send(200, "application/json", response);
}

void handleStatus() {
  String response = "{";
  response += "\"device\":\"Smart Servo IoT Controller\",";
  response += "\"status\":\"online\",";
  response += "\"angle\":" + String(currentAngle) + ",";
  response += "\"ip\":\"" + WiFi.localIP().toString() + "\"";
  response += "}";
  server.send(200, "application/json", response);
}

void setup() {
  Serial.begin(115200);
  servoMotor.attach(servoPin);
  servoMotor.write(currentAngle);

  if (!SPIFFS.begin(true)) {
    Serial.println("SPIFFS mount failed");
    return;
  }

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

  server.on("/", []() { serveFile("/index.html", "text/html"); });
  server.on("/style.css", []() { serveFile("/style.css", "text/css"); });
  server.on("/script.js", []() { serveFile("/script.js", "application/javascript"); });
  server.on("/api/set-angle", handleSetAngle);
  server.on("/api/status", handleStatus);
  server.begin();
}

void loop() {
  server.handleClient();
}
