#define TRG 13
#define ECO 14

#define LED 19
#define LEDALERTA 22

#define MAX_DIST 700

int valorLedAlerta = 0;
float distancia = 0.0;
float timeOut = MAX_DIST * 60;
int velSonido = 340;

void setup() {
  
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(LEDALERTA, OUTPUT);

  pinMode(TRG, OUTPUT);
  pinMode(ECO, INPUT);

}

void loop() {
  
  digitalWrite(LED, 1);

  distancia = getSonar();
  valorLedAlerta = map(distancia, 0, 300, 0, 255);
  analogWrite(LEDALERTA, 255 - valorLedAlerta);
  Serial.println("La destancia es " + String(distancia));

  digitalWrite(LED, 0);
  delay(1000);
}


float getSonar(){

  unsigned long int pingTime = 0;
  float dist = 0.0;

  digitalWrite(TRG, 1);
  delayMicroseconds(10);
  digitalWrite(TRG, 0);

  pingTime = pulseIn(ECO, 1, timeOut);
  Serial.println("Ping time " + String(pingTime));
  dist = (float) pingTime * velSonido / 2 / 10000;
  return dist; // en centimitros.

}