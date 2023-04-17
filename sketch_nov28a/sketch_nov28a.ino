#include <OneWire.h>
#include <DallasTemperature.h>
// DS18B20 est connecté à la broche 16/RX2
const int oneWireBus = 16;
// Setup de l’instance oneWire pour communiquer avec les composants OneWire
OneWire oneWire(oneWireBus);
// reference à Dallas Temperature sensor
DallasTemperature sensors(&oneWire);

void setup() {
 // Start the Serial Monitor
 Serial.begin(115200);
 // Start the DS18B20 sensor
 sensors.begin();
}

void loop() {
 sensors.requestTemperatures();
 float temperatureC = sensors.getTempCByIndex(0);
 float temperatureF = sensors.getTempFByIndex(0);
 Serial.print(temperatureC);
 Serial.println("ºC");
 Serial.print(temperatureF);
 Serial.println("ºF");
 delay(5000);
}
