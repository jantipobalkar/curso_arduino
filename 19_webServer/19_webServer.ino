#include <WiFi.h>
#include <WebServer.h>
#define LED2 2
#define LEDROJO 33
#define LEDAZUL 14
#define LEDVERDE 15


char * ssid = "Aula 1";
char * pwd = "Horus.2025";

WebServer server(80);

String home = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>Document</title></head><body><h1>Hola MUNDO.</h1><h2>A ver que pasa.</h2><a href=\"/segunda\">Vamos a la otra página</a><br><a href=\"/semaforo\">Vamos al semáforo.</a><br><a href=\"/led1\">Encender Led.</a><br><a href=\"/led0\">Vamos a apagar el Led.</a></body></html>";
String segunda = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>Document</title></head><body><h1>Hola mundo, esto es la segunda..</h1><h2>Esto es un h2</h2><a href=\"/\">Ir al home.</a></body></html>";


void setup() {
  
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pwd);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Conectado en la dirección: ");
  Serial.println(WiFi.localIP());

// Solicitudes web
  server.on("/", handle_OnConnect);
  server.on("/segunda", handle_Segunda);
  server.on("/led1", LED2A1);
  server.on("/led0", LED2A0);
  server.on("/semaforo", SEMAFORO);

  server.begin();
  Serial.println("Servidor web esta iniciado.");

  pinMode(LED2, OUTPUT);
  pinMode(LEDROJO, OUTPUT);
  pinMode(LEDAZUL, OUTPUT);
  pinMode(LEDVERDE, OUTPUT);
}

void loop() {
  
  server.handleClient();

}

//Funcion de respuesta a entrar al server

void handle_OnConnect(){

  server.send(200, "text/html", home);

}

void handle_Segunda(){

  server.send(200, "text/html", segunda);

}

void LED2A1(){

  digitalWrite(LED2, 1);
  server.send(200, "text/html", "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>Document</title></head><body><h1>Hola mundo, Led Encendido.</h1><h2>Esto es un h2</h2><a href=\"/\">Ir al home.</a></body></html>");

}

void LED2A0(){

  digitalWrite(LED2, 0);
  server.send(200, "text/html", "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>Document</title></head><body><h1>Hola mundo, Led Apagado.</h1><h2>Esto es un h2</h2><a href=\"/\">Ir al home.</a></body></html>");

}

void SEMAFORO(){

  server.send(200, "text/html", "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>Document</title></head><body><h1>Hola mundo, esto es un semáforo.</h1><h2>Esto es un h2</h2><a href=\"/\">Ir al home.</a></body></html>");
  digitalWrite(LEDROJO, 1);
  delay(1000);
  digitalWrite(LEDAZUL, 1);
  delay(1000);
  digitalWrite(LEDVERDE, 1);
  delay(1000);
  digitalWrite(LEDROJO, 0);
  delay(500);
  digitalWrite(LEDAZUL, 0);
  delay(500);
  digitalWrite(LEDVERDE, 0);
  delay(500);
}