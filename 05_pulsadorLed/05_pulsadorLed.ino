#define PULSADOR 13
#define LED 4
#define ZUMBADOR 15

int valorBoton = LOW; 
int estado = LOW;


void setup() {
  pinMode(PULSADOR, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(15, OUTPUT);
  Serial.begin(115200);

}

void loop() {
  
  valorBoton = digitalRead(PULSADOR);
  
  /*if(valorBoton == LOW){

    estado = !estado;
    digitalWrite(LED, estado);
  }

delay(500);

}*/

   if(valorBoton == LOW){
    digitalWrite(LED, HIGH);
    digitalWrite(ZUMBADOR, HIGH);
  }
    else{

      digitalWrite(LED, LOW);
      digitalWrite(ZUMBADOR, LOW);
    
        }
} 

  


