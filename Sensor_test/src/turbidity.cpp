#include <Arduino.h>

#define TURBIDITY_SENSOR_PIN 34
#define TURBIDITY_SAMPLE_COUNT 10


const float V_clear = 2.465;
const float V_turbid = 0.699;
const float NTU_max = 3000.0;

void initTurbiditySensor() {
  pinMode(TURBIDITY_SENSOR_PIN, INPUT);
}

float readTurbidityVoltage() {
  long sum = 0;
  for (int i = 0; i < TURBIDITY_SAMPLE_COUNT; i++) {
    sum += analogRead(TURBIDITY_SENSOR_PIN);
    delay(5);
  }
  float sensorValue = sum / (float)TURBIDITY_SAMPLE_COUNT;

  // Conversion ADC ESP32 (0–4095 -> 0–3.3V)
  return sensorValue * (3.3 / 4095.0);
}

float readTurbidityNTU() {
  float voltage = readTurbidityVoltage();

  if (V_clear == V_turbid) return 0;

  // Inversion : plus le liquide est trouble, plus le voltage diminue
  float ntu = (V_clear - voltage) * (NTU_max / (V_clear - V_turbid));

  if (ntu < 0) ntu = 0;
  if (ntu > NTU_max) ntu = NTU_max;

  Serial.print("Voltage: ");
  Serial.print(voltage, 3);
  Serial.print(" V  |  Turbidité: ");
  Serial.print(ntu, 2);
  Serial.println(" NTU");

  return ntu;
}