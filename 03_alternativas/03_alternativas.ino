#define ROJO 14
#define AZUL 12
#define VERDE 13
int nota = 0;

void setup() {

  pinMode(ROJO, OUTPUT);
  pinMode(AZUL, OUTPUT);
  pinMode(VERDE, OUTPUT);
  Serial.begin(115200);
  delay(5000);

  
}

void loop() {

delay(3000);
  Serial.println("Ingresa una nota entre 0 y 10:");
  String input = Serial.readStringUntil('\n');
  nota = input.toInt();
  if(Serial.available() > 0){

    
     if(nota < 5 ){
      Serial.println("Suspenso.");
      digitalWrite(ROJO, HIGH);
      delay(3000);
      digitalWrite(ROJO, LOW);

    }

      else if(nota == 5){

      Serial.println("Aprobado.");
      digitalWrite(AZUL, HIGH);
      delay(3000);
      digitalWrite(AZUL, LOW);

      }

      else if(nota == 6 || nota == 7){

      Serial.println("Aprobado.");
      digitalWrite(VERDE, HIGH);
      delay(3000);
      digitalWrite(VERDE, LOW);

      }

      else if(nota == 8 || nota == 9){

      Serial.println("Notable.");
      digitalWrite(VERDE, HIGH);
      delay(3000);
      digitalWrite(VERDE, LOW);

      }

    else {
    Serial.println("Sobresaliente.");
      digitalWrite(VERDE, HIGH);
      delay(3000);
      digitalWrite(VERDE, LOW);
    }   
  }
}
  
