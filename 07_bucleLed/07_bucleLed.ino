#define LED 2
#define CONTROL 4

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(CONTROL, OUTPUT);

}


void loop() {

  digitalWrite(CONTROL, HIGH);
  delay(1000);
  digitalWrite(CONTROL, LOW);
   int duracion = 100;
   
   for(int i = 0; i < 501; i += 100){
    digitalWrite(LED, HIGH);
    delay(duracion);
    digitalWrite(LED, LOW);
    delay(duracion / 2 );
    duracion = duracion + i;
   }
  
}
