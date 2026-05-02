#include "DHT.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#define DHTPIN 4            // Connect to Analog 104
#define DHTTYPE DHT11       // DHT11 Type

DHT dht(DHTPIN, DHTTYPE);
const char* ssid = "YOUR_NETWORK_SSID";                         // Type your network details
const char* password = "YOUR_NETWORK_PASSWORD";                 // Type your network details
const char* serverName = "http://YOUR_SERVER_IP:5000/sensor";   // Type your server details

void setup() {
  Serial.begin(115200);
  dht.begin();
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Successfully connected!");
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

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/json");

    StaticJsonDocument<200> doc;
    doc["temperature"] = temp;
    doc["humidity"] = humid;
    String requestBody;
    serializeJson(doc, requestBody);

    int httpResponseCode = http.POST(requestBody);
    if (httpResponseCode > 0) {
      Serial.printf("Server answer: %d\n", httpResponseCode);
    } else {
      Serial.printf("Reading error! %s\n", http.errorToString(httpResponseCode).c_str());
    }
    http.end();

    Serial.print("Temperature: %.2f°C\n", temp);
    Serial.print("Humidity: %.2f%%\n", humid);
  }
}
