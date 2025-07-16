#include <DHT.h>

#define LED 4

#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

float temp = 0.0;
float hum = 0.0;

void setup() {
  
  Serial.begin(115200);
  dht.begin();
  pinMode(LED, OUTPUT);

}

void loop() {

  digitalWrite(LED, 1);
  temp = dht.readTemperature();
  hum = dht.readHumidity();
  delay(100);
  digitalWrite(LED, 0);
  Serial.print("Temperatura : ");
  Serial.println(temp);
  Serial.println("Humedad: " + String(hum));

  delay(5000);

}
