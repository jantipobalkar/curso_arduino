#define TRG 13
#define ECO 14

#define LED 19
#define LEDALERTA 22

#define BUZZER 2

#define MAX_DIST 700

int valorLedAlerta = 0;
float distancia = 0.0;
float timeOut = MAX_DIST * 60;
int velSonido = 340;

int intervalos[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};



void setup() {
  
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(LEDALERTA, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(TRG, OUTPUT);
  pinMode(ECO, INPUT);

}

void loop() {
  
  digitalWrite(LED, 1);

  int umbral;
  distancia = getSonar();
  umbral = getIntervalo(distancia);
  if(umbral <= 100 ){
    pitar(umbral);
  }
  valorLedAlerta = map(distancia, 0, 300, 0, 255);
  analogWrite(LEDALERTA, 255 - valorLedAlerta);
  Serial.println("La distancia es " + String(distancia));
  digitalWrite(LED, 0);
  delay(500);
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

int getIntervalo(float lejos){

  int salida = 1000;
  for(int i = 0; i < 10; i++){

    if(lejos < intervalos[i]){
      salida = intervalos[i];
      break;
    }

  }
return salida; 

}

void pitar(int umbral){

  for(int i = 0; i < 5 ; i++){

    digitalWrite(BUZZER, 1);
    delay(50);
    digitalWrite(BUZZER, 0);
    delay(10* umbral);

  }

}