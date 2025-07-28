#define FOTOPIN 4
#define LED 2

int valorLuz = 0; 
int valorLed = 0; 

int umbral = 1000;

void setup() {
  
  pinMode(FOTOPIN, INPUT);
  pinMode(LED, OUTPUT);
  
}

void loop() {
  
  valorLuz = analogRead(FOTOPIN);
  valorLed = map(valorLuz, 0, 4095 , 0 , 255);
  //analogWrite(LED, valorLed);
  if(valorLuz > umbral){
    digitalWrite(LED, 1);
  }
    else{
      digitalWrite(LED, 0);

    }
  

  delay(200);

}
