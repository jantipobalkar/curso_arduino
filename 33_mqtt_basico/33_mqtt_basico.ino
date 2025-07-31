#include <WiFi.h>
#include <PubSubClient.h>



char * ssid = "Aula 1";
char * pwd = "Horus.2025";

//MQTT

char* mqtt_server = "192.168.0.25";
int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

char* mqtt_topic_sub = "curso_arduino/#";
char* mqtt_topic_pub = "curso_arduino/peinado";
char* mqtt_client_id = "ESP_Peinado";

static unsigned long lastMsg = 0;
unsigned long now;

void setup(){
  
  
  Serial.begin(115200);
  //Conoectarse al wifi
  WiFi.begin(ssid, pwd);
  while (WiFi.status() != WL_CONNECTED) {

    delay(500);
    Serial.print(".");

  }

  Serial.print("\n");
  Serial.println("Conectado con la ip: ");
  Serial.println(WiFi.localIP());

  //MQTT

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  

}

void loop() {

  if (Serial.available()) {
  String mensaje = Serial.readStringUntil('\n');  
  if (mensaje.length() > 0) {
    client.publish(mqtt_topic_pub, mensaje.c_str());
    Serial.println("Peinado desde Serie: " + mensaje);
  }
}

  
 if(!client.connected()){
    reconnect();
  }  
  client.loop();
  
 /* now = millis();
  if(now - lastMsg > 10000){
    lastMsg = now; 
    String mensaje = "Hola, soy Peinado.";
  
  client.publish(mqtt_topic_pub, mensaje.c_str());
  Serial.println("Mensaje enviado: " + mensaje);
  Serial.println(millis());
  } */
 
}



  void reconnect(){
    while(!client.connected()){
      Serial.println("Reconectando...");
      if(client.connect(mqtt_client_id)){
        Serial.println("Conectado a MQTT");
        client.subscribe(mqtt_topic_sub);
      }
      else{
        Serial.println("Fallo de conexión.");
        Serial.println("Error: " + client.state());
        delay(5000);
      }

    }
  }


void callback(char* topic, byte* payload, unsigned int length){

    Serial.print("Mensaje recibido en [");
    Serial.print(topic);
    Serial.print("]:");
    for(int  i = 0; i < length; i++){
      Serial.print((char)payload[i]);

    }
  Serial.println();
  
  }
