#define POT 14
#define LED 4
#define ALERTA 32
#define FREC 25
#define PITO 21

int valorFrec = 0;
int valorPitidos = 0;
int valorPot = 0;
int valorLed = 0;


void setup() {
  
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(POT, INPUT);
  pinMode(ALERTA, OUTPUT);
  pinMode(FREC, INPUT);
  pinMode(PITO, OUTPUT);
}

void loop() {
  
delay(valorFrec);

  valorLed = map(valorPot, 0, 4096, 0, 255);
  

  valorPot = analogRead(POT);
  analogWrite(LED, valorLed);
  Serial.println("Pot es:  " + String(valorPot));
  Serial.println("Valor Led es:  " + String(valorLed));

  if (valorPot > 2000) {
  digitalWrite(ALERTA, 1);}
  else {
  digitalWrite(ALERTA,  0);
  }

  Serial.println();

  valorFrec = analogRead(FREC);
  valorPitidos = map(valorFrec, 0, 4095, 0, 5000);
  digitalWrite(PITO, 1);
  
  delay(valorFrec);

  digitalWrite(PITO, 0);


  Serial.println("Frec es:  " + String(valorFrec));
  Serial.println("Valor Pitidos es:  " + String(valorPitidos));


  ;
}
