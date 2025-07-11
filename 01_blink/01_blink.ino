#define PIN_LED 2 
#define PIN_VERDE 12
int contador = 0 ;



void setup() {

  Serial.begin(115200);

  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_VERDE, OUTPUT);
}

void loop() {
  digitalWrite(PIN_LED, HIGH);
  digitalWrite(PIN_VERDE, LOW);
  Serial.println("Led Encedido.");
  delay(500);
  digitalWrite(PIN_LED, LOW);
  digitalWrite(PIN_VERDE, HIGH);
  Serial.println("Led Apagado.");
  delay(500);
  contador = contador + 1;
  
  // contador ++;

  Serial.println(contador);
}
