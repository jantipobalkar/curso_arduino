#define AZUL 12
#define VERDE 13
#define ROJO 15

void setup() {

  pinMode(AZUL, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(ROJO, OUTPUT);

}

void loop() {
  
  /*
  //ROJO
  
  digitalWrite(ROJO, 0);
  digitalWrite(VERDE, 1);
  digitalWrite(AZUL, 1);

  delay(500);

//VERDE

  digitalWrite(ROJO, 1);
  digitalWrite(VERDE, 0);
  digitalWrite(AZUL, 1);

  delay(500);

  //AZUL
    
  digitalWrite(ROJO, 1);
  digitalWrite(VERDE,1);
  digitalWrite(AZUL, 0);

  delay(500);
  
    //CYAN
    
  digitalWrite(ROJO, 1);
  digitalWrite(VERDE,0);
  digitalWrite(AZUL, 0);

  delay(500);

    //AMARILLO
    
  digitalWrite(ROJO, 0);
  digitalWrite(VERDE,0);
  digitalWrite(AZUL, 1);

  delay(500);
    
    //MAGENTA
    
  digitalWrite(ROJO, 0);
  digitalWrite(VERDE,1);
  digitalWrite(AZUL, 0);

  delay(500);

  //BLANCO
    
  digitalWrite(ROJO, 0);
  digitalWrite(VERDE, 0);
  digitalWrite(AZUL, 0);

  delay(500);

  */

int r = 0;
int g = 0;
int b = 0;

  for(;;){

    r = random(0, 255);
    g = random(0, 255);
    b = random(0, 255); 

    analogWrite(ROJO, r);
    analogWrite(VERDE, g);
    analogWrite(AZUL,  b);
    
    delay(1000);
      }

}
