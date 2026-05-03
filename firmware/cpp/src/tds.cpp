#include <Arduino.h>
#include "tds.h"

#define TdsSensorPin 2
#define VREF 5.0
#define SCOUNT 30

static int analogBuffer[SCOUNT];
static int analogBufferTemp[SCOUNT];
static int analogBufferIndex = 0;

void initTdsSensor() {
    pinMode(TdsSensorPin, INPUT);
}

static int getMedianNum(int bArray[], int iFilterLen) {
    int bTab[iFilterLen];
    for (byte i = 0; i < iFilterLen; i++)
        bTab[i] = bArray[i];
    int i, j, bTemp;
    for (j = 0; j < iFilterLen - 1; j++) {
        for (i = 0; i < iFilterLen - j - 1; i++) {
            if (bTab[i] > bTab[i + 1]) {
                bTemp = bTab[i];
                bTab[i] = bTab[i + 1];
                bTab[i + 1] = bTemp;
            }
        }
    }
    if ((iFilterLen & 1) > 0)
        bTemp = bTab[(iFilterLen - 1) / 2];
    else
        bTemp = (bTab[iFilterLen / 2] + bTab[iFilterLen / 2 - 1]) / 2;
    return bTemp;
}

float readTdsValue(float temperature) {
    // Remplir le buffer avec les dernières valeurs analogiques
    analogBuffer[analogBufferIndex] = analogRead(TdsSensorPin);
    analogBufferIndex++;
    if (analogBufferIndex == SCOUNT)
        analogBufferIndex = 0;

    // Copie pour le filtrage médian
    for (int i = 0; i < SCOUNT; i++)
        analogBufferTemp[i] = analogBuffer[i];

    float averageVoltage = getMedianNum(analogBufferTemp, SCOUNT) * (float)VREF / 1024.0;
    float compensationCoefficient = 1.0 + 0.02 * (temperature - 25.0);
    float compensationVoltage = averageVoltage / compensationCoefficient;
    float tdsValue = (133.42 * compensationVoltage * compensationVoltage * compensationVoltage
                    - 255.86 * compensationVoltage * compensationVoltage
                    + 857.39 * compensationVoltage) * 0.5;
    return tdsValue;
}