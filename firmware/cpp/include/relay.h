#ifndef RELAY_H
#define RELAY_H

// Pin pour le relais
#define RELAY_PIN 33

// Initialise le relais
void initRelay();

// Active le relais
void enableRelay();

// Désactive le relais
void disableRelay();

// Bascule l'état du relais
void toggleRelay();

// Ecrit un niveau logique brut sur la pin du relais (true=HIGH, false=LOW)
void writeRelayLevel(bool highLevel);

// Retourne l'état actuel du relais (HIGH ou LOW)
int getRelayState();

#endif
