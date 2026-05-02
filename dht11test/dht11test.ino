#include "DHT.h"
#define DHTPIN 4            // Connect to Analog 104
#define DHTTYPE DHT11       // DHT11 Type

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println("DHT11 Sensor Test");
  dht.begin();
}

void loop() {

  // Set time to update data (optimal for this sensor: 2000ms)
  delay(2000);

  float humid = dht.readHumidity();
  float temp = dht.readTemperature();

  if (isnan(humid) || isnan(temp)) {
    Serial.println("Error reading DHT!");
    return;
  }

  Serial.printf("Temperature: %.2f°C\n", temp);
  Serial.printf("Humidity: %.2f%%\n", humid);
}
