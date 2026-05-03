#include <Arduino.h>
#include "relay.h"

void initRelay() {
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Relais initialisé sur PIN " + String(RELAY_PIN));
}

void writeRelayLevel(bool highLevel) {
    digitalWrite(RELAY_PIN, highLevel ? HIGH : LOW);
    delay(2);
    Serial.print("GPIO");
    Serial.print(RELAY_PIN);
    Serial.print(" = ");
    Serial.println(digitalRead(RELAY_PIN) == HIGH ? "HIGH" : "LOW");
}

void enableRelay() {
    writeRelayLevel(true);
    Serial.println("Relais ACTIVÉ");
}

void disableRelay() {
    writeRelayLevel(false);
    Serial.println("Relais DÉSACTIVÉ");
}

void toggleRelay() {
    int currentState = digitalRead(RELAY_PIN);
    writeRelayLevel(currentState == LOW);
    Serial.println(currentState == LOW ? "Relais ACTIVÉ" : "Relais DÉSACTIVÉ");
}

int getRelayState() {
    return digitalRead(RELAY_PIN);
}
