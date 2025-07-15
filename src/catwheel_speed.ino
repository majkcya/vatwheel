// Simple speed measurement for a cat wheel using an ESP32 and a hall sensor
// Connect the hall sensor output to GPIO 15 (can be changed)

const int sensorPin = 15;       // Hall sensor connected to GPIO 15
const float wheelDiameter = 0.3; // Diameter of the wheel in meters (example value)

volatile unsigned long lastPulseTime = 0;
volatile unsigned long pulseInterval = 0;

void IRAM_ATTR onPulse() {
  unsigned long currentTime = micros();
  pulseInterval = currentTime - lastPulseTime;
  lastPulseTime = currentTime;
}

void setup() {
  Serial.begin(115200);
  pinMode(sensorPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(sensorPin), onPulse, FALLING);
}

void loop() {
  // Convert pulse interval to speed
  // Speed = Circumference / time
  noInterrupts();
  unsigned long interval = pulseInterval;
  interrupts();

  if (interval > 0) {
    float wheelCircumference = wheelDiameter * 3.1415926f;
    float speed = wheelCircumference / (interval / 1000000.0f); // m/s
    float speedKmH = speed * 3.6f;
    Serial.print("Speed: ");
    Serial.print(speedKmH, 2);
    Serial.println(" km/h");
  }
  delay(500);
}
