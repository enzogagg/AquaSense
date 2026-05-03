#include <Arduino.h>
#include "temperature.h"
#include "tds.h"
#include "level.h"
#include "turbidity.h"
#include "relay.h"

unsigned long lastRelayToggle = 0;
const unsigned long RELAY_TOGGLE_INTERVAL = 3000;  // Bascule toutes les 3 secondes

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.println("\n\n=== Démarrage du système ===");
    initTemperatureSensor();
    initTdsSensor();
    initLevelSensor();
    initTurbiditySensor();
    initRelay();
}

void loop() {
    // Test du relais : basculer toutes les 3 secondes
    unsigned long currentMillis = millis();
    if (currentMillis - lastRelayToggle >= RELAY_TOGGLE_INTERVAL) {
        lastRelayToggle = currentMillis;
        toggleRelay();
    }

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