#include <DHT.h>
#include <WiFi.h>
#include <HTTPClient.h>

#define LED 4
#define LEDROJO 21

#define SENSORPIN 13
#define DHTTYPE DHT11

DHT sensor(SENSORPIN, DHT11);

float temp = 0.0;
float hum = 0.0;

WiFiClient clienteWifi;
HTTPClient http;

char * servidor = "http://192.168.0.69:5000/datos";

char * ssid = "Aula 1";
char * pwd = "Horus.2025";

void setup() {
  Serial.begin(115200);
  sensor.begin();

  pinMode(LED, OUTPUT);
  pinMode(LEDROJO, OUTPUT);

  WiFi.begin(ssid, pwd);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println(".");

  } 
  Serial.println("Conectado con la dirección: ");
  Serial.println(WiFi.localIP());
}

void loop() {

  digitalWrite(LED, 1);
  temp = sensor.readTemperature();
  hum = sensor.readHumidity();

  postData(temp, hum, "Jose Peinado2");
  
  delay(200);

  digitalWrite(LED, 0);
  
  Serial.println("Temperatura: " + String(temp));
  Serial.println("Humedad: " + String(hum));
  Serial.println("");

  delay(5000);

}

void postData(float t, float h, String per){

  String parametros = "temp=" + String(t) + "&hum=" + String(h) + "&persona=" + per;
  int httpCode;
  String payload;

  if(WiFi.status() == WL_CONNECTED){
    http.begin(clienteWifi, servidor);
    http.addHeader("Content-Type","application/x-www-form-urlencoded");
    
    httpCode = http.POST(parametros);
    payload = http.getString();

    Serial.print("HTTP Code: ");
    Serial.println(httpCode);
    Serial.print("Mensaje de Error: ");
    Serial.println(payload);
    Serial.println("");

    if(httpCode != 200){
      digitalWrite(LEDROJO, 1);
      delay(3000);
      digitalWrite(LEDROJO, 0);
    }
  }

}