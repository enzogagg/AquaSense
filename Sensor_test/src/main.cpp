#include <Arduino.h>
#include "temperature.h"
#include "tds.h"
#include "level.h"
#include "turbidity.h"

void setup() {
    Serial.begin(115200);
    initTemperatureSensor();
    initTdsSensor();
    initLevelSensor();
    initTurbiditySensor();
}

void loop() {
    float tempC = readTemperatureC();
    float tds = readTdsValue(tempC);
    float turbidity = readTurbidityNTU();
    Serial.print("Température: ");
    Serial.print(tempC);
    Serial.println(" °C");
    Serial.print("TDS Value: ");
    Serial.print(tds, 0);
    Serial.println(" ppm");
    Serial.print("Turbidité: ");
    Serial.print(turbidity, 2);
    Serial.println(" NTU");
    if (isLiquidDetected()) {
        Serial.println("Liquide détecté !");
    } else {
        Serial.println("Pas de liquide.");
    }
    delay(1000);
}