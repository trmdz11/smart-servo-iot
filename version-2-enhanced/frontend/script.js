const slider = document.getElementById("servoSlider");
const angleValue = document.getElementById("angleValue");
const statusText = document.getElementById("statusText");
const ipText = document.getElementById("ipText");
const servoText = document.getElementById("servoText");
const logList = document.getElementById("logList");

function addLog(message) {
  const item = document.createElement("li");
  item.textContent = `${new Date().toLocaleTimeString()} - ${message}`;
  logList.prepend(item);
}

async function setAngle(angle) {
  angleValue.textContent = angle;
  slider.value = angle;
  servoText.textContent = `Moving to ${angle}°`;
  try {
    const response = await fetch(`/api/set-angle?angle=${angle}`);
    const data = await response.json();
    if (data.status === "updated") {
      servoText.textContent = `Angle set to ${data.angle}°`;
      addLog(`Servo angle updated to ${data.angle}°`);
    }
  } catch (error) {
    servoText.textContent = "Connection error";
    addLog("Failed to send command to ESP32");
  }
}

async function getStatus() {
  try {
    const response = await fetch("/api/status");
    const data = await response.json();
    statusText.textContent = data.status;
    ipText.textContent = data.ip;
    angleValue.textContent = data.angle;
    slider.value = data.angle;
    addLog("Connected to ESP32");
  } catch (error) {
    statusText.textContent = "Offline";
    addLog("Unable to reach ESP32");
  }
}

slider.addEventListener("input", (event) => setAngle(event.target.value));
getStatus();
