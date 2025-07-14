#define ROJO 14
#define AZUL 12
#define VERDE 13
#define CONTROL 2


void setup() {
  pinMode(ROJO, OUTPUT);
  pinMode(AZUL, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(CONTROL, OUTPUT);
  Serial.begin(115200);
}


void loop() {
  //Rojo encendido 

  digitalWrite(CONTROL, HIGH);
  digitalWrite(ROJO, HIGH);
  Serial.print("Rojo encendido.\n");
  delay(50);
  digitalWrite(CONTROL, LOW);
  delay(5000);
  digitalWrite(ROJO, LOW);

  //Azul encendido

  digitalWrite(CONTROL, HIGH);
  digitalWrite(AZUL, HIGH);
  Serial.print("Azul encendido.\n");
  delay(50);
  digitalWrite(CONTROL, LOW);
  delay(500);
  digitalWrite(AZUL, LOW);
  delay(500);
  digitalWrite(AZUL, HIGH);
  delay(500);
  digitalWrite(AZUL, LOW);
  delay(500);
  digitalWrite(AZUL, HIGH);
  delay(500);
  digitalWrite(AZUL, LOW);


  //Verde encendido

  digitalWrite(CONTROL, HIGH);
  digitalWrite(VERDE, HIGH);
  Serial.print("Verde encendido.\n");
  delay(50);
  digitalWrite(CONTROL, LOW);
  delay(5000);
  digitalWrite(VERDE, LOW);
  
}
