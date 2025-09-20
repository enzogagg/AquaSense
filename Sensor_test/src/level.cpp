#include <Arduino.h>
#include "level.h"

#define LEVEL_SENSOR_PIN 18

void initLevelSensor() {
    pinMode(LEVEL_SENSOR_PIN, INPUT);
}

bool isLiquidDetected() {
    return digitalRead(LEVEL_SENSOR_PIN) == HIGH;
}