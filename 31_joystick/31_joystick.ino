#define PIN_X 13
#define PIN_Y 12
#define PIN_SW 14
#define LED 2
#define LED_IZQ 21
#define LED_DER 4
#define LED_ARR 5
#define LED_ABJ 19


int cero_X = 2000;
int cero_Y = 2047;

void setup() {
  
  Serial.begin(115200);
  pinMode(PIN_X, INPUT);
  pinMode(PIN_Y, INPUT);
  pinMode(PIN_SW, INPUT_PULLUP);

  pinMode(LED, OUTPUT);
  pinMode(LED_DER, OUTPUT);
  pinMode(LED_IZQ, OUTPUT);
  pinMode(LED_ARR, OUTPUT);
  pinMode(LED_ABJ, OUTPUT);
}

void loop() {
  
  int valor_x = analogRead(PIN_X);
  int valor_y = analogRead(PIN_Y);
  int valor_z = digitalRead(PIN_SW);

  Serial.println("X, Y, Z: ");
  Serial.print(String(valor_x) + ", ");
  Serial.print(String(valor_y) + ", ");
  Serial.println(String(valor_z) + ".");
  delay(300);

  if(valor_x > 3000){

    Serial.println("Derecha: " + String(valor_x - cero_X));
    digitalWrite(LED_DER, 1);
    delay(200);
    digitalWrite(LED_DER, LOW);
  }

  if(valor_x < 100 ){
    Serial.println("Izquierda: " + String(valor_x - cero_X));
    digitalWrite(LED_IZQ, 1);
    delay(200);
    digitalWrite(LED_IZQ, LOW);
  }

  if(valor_y > 3000){

    Serial.println("Abajo: " + String(valor_y - cero_Y));
    digitalWrite(LED_ABJ, 1);
    delay(200);
    digitalWrite(LED_ABJ, LOW);
  }

  if(valor_y < 1000 ){
    Serial.println("Arriba: " + String(valor_y - cero_Y));
    digitalWrite(LED_ARR, 1);
    delay(200);
    digitalWrite(LED_ARR, LOW);
  }
  if( valor_z == 0){

  digitalWrite(LED_DER, 1);
  digitalWrite(LED_IZQ, 1);
  digitalWrite(LED_ARR, 1);
  digitalWrite(LED_ABJ, 1);
  delay(200);
  digitalWrite(LED_DER, 0);
  digitalWrite(LED_IZQ, 0);
  digitalWrite(LED_ARR, 0);
  digitalWrite(LED_ABJ, 0);
  }

  delay(200);

}
