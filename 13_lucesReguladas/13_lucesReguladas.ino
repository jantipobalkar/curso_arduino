#define ROJO 25
#define RegROJO 22
#define VERDE 13
#define RegVERDE 5
#define AZUL 34
#define RegAZUL 15

int entRojo = 0;
int entVerde = 0;
int entAzul = 0;

int valorRojo = 1;
int valorVerde = 1;
int valorAzul = 1;


void setup() {
  Serial.begin(115200);
  
  pinMode(ROJO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(AZUL, OUTPUT);

  pinMode(RegROJO, INPUT);
  pinMode(RegVERDE, INPUT);
  pinMode(RegAZUL, INPUT);

}

void loop() {
  
  entRojo = analogRead(RegROJO);
  entVerde = analogRead(RegVERDE);
  entAzul = analogRead(RegAZUL);

valorRojo = map(entRojo, 0, 4095, 0, 255);
valorVerde = map(entVerde, 0, 4095, 0, 255);
valorAzul = map(entAzul, 0, 4095, 0, 255);


analogWrite(ROJO, valorRojo);
analogWrite(VERDE, valorVerde);
analogWrite(AZUL, valorAzulAzul);


/*
digitalWrite(ROJO, 1);
digitalWrite(VERDE, 1);
digitalWrite(AZUL, 1);
*/
Serial.println("Rojo: " + String(entRojo));
Serial.println("Verde: " + String(entVerde));
Serial.println("Azul: " + String(entAzul));
Serial.println();

Serial.println("RojoLED: " + String(valorRojo));
Serial.println("VerdeLED: " + String(valorVerde));
Serial.println("AzulLED: " + String(valorAzul));
Serial.println();

delay(200); 

}
