#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 15  // D15 de l'ESP32

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void initTemperatureSensor() {
  sensors.begin();
}

float readTemperatureC() {
  sensors.requestTemperatures();
  return sensors.getTempCByIndex(0);
}
