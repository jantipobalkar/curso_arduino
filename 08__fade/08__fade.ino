#define LED1 12
#define LED2 21

void setup() {
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

}

void loop() {

  /*
  digitalWrite(LED_AZUL, HIGH);
  delay(1000);
  digitalWrite(LED_AZUL, LOW);
  delay(1000);
  */
  int contadorA = 0;
  int contadorB = 255;
  for(int i = 0 ; i < 255; i++){
    analogWrite(LED1, contadorA);
    analogWrite(LED2, contadorB);
    contadorA++;
    contadorB--;
    delay(20);
  }
  contadorA = 0;
  contadorB = 255;
  delay(1000);
   for(int i = 0 ; i < 255; i++){
    analogWrite(LED1, contadorB);
    analogWrite(LED2, contadorA);
    contadorA++;
    contadorB--;
    delay(20);
  }

  delay(1000);

/*
  digitalWrite(LED_AZUL, HIGH);
  delay(1000);
  for(int i = 255 ; i > 0; i--){
    analogWrite(LED_AZUL, i);
    delay(20);
  }


  digitalWrite(LED_AZUL, LOW);
  delay(1000);
  */
}
