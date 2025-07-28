#define VELOCIDAD 14
#define DRIPIN_1 12
#define DRIPIN_2 13  
#define ROJO 5
#define VERDE 4
#define AZUL 15
#define PARO 0 // valor
#define IZQUIERDA 1
#define DERECHA 2
#define POT 0 // pin

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SDA 23
#define SCL 22

#define ADDR 0x27    //0x3F  //

LiquidCrystal_I2C lcd(ADDR, 16, 2);


void setup() {
  
  Wire.begin(SDA, SCL);
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();

  pinMode(VELOCIDAD, OUTPUT);
  pinMode(DRIPIN_1, OUTPUT);
  pinMode(DRIPIN_2, OUTPUT);

  pinMode(ROJO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(AZUL, OUTPUT);

  pinMode(POT, INPUT);
  lcd.setCursor(0, 0);
  lcd.print("vamos a ver");
  delay(3000);
}

void loop() {
  
 // digitalWrite(VELOCIDAD, HIGH); // motor encendido
  cambioEstado(DERECHA);
  
  delay(5000);

  cambioEstado(PARO);
  delay(3000);

  cambioEstado(IZQUIERDA);
  delay(5000);

  cambioEstado(PARO);

  delay(3000);

}



void cambioEstado(int estadoNuevo){
  lcd.clear();
  switch(estadoNuevo){
    case PARO:
        
    analogWrite(VELOCIDAD, 0);  // apagar motor
    Serial.println("Motor Parado.");
    escribeLCD("Motor Apagado", 0);
    digitalWrite(ROJO, 1);
    digitalWrite(AZUL, 0);
    digitalWrite(VERDE, 0);
    break;

    case DERECHA:
      
      
      Serial.println("Giro derecha.");
      escribeLCD("Giro Derecha", 0);
      escribeLCD("Velocidad: " + String(leerPot()), 1);
      analogWrite(VELOCIDAD, leerPot());
      digitalWrite(ROJO, 0);
      digitalWrite(AZUL, 1);
      digitalWrite(VERDE, 0);
      digitalWrite(DRIPIN_1, 1);
      digitalWrite(DRIPIN_2, 0);

      break;
  case IZQUIERDA:

      
      Serial.println("Giro Izquierda.");
      escribeLCD("Giro Izquierda", 0);
      escribeLCD("Velocidad: " + String(leerPot()), 1);
      analogWrite(VELOCIDAD, leerPot());
      digitalWrite(ROJO, 0);
      digitalWrite(AZUL, 0);
      digitalWrite(VERDE, 1);
      digitalWrite(DRIPIN_1, 0);
      digitalWrite(DRIPIN_2, 1);

      break;
  }

}

int leerPot(){
  int valorPot = 0;
  int valorVel = 0; 
  valorPot = analogRead(POT);
  valorVel = map(valorPot, 0, 4095, 90, 255);
  Serial.println(valorPot);
  Serial.println(valorVel);
  return valorVel;

}

void escribeLCD(String mensaje, int fila){

  //lcd.clear();
  lcd.setCursor(0,fila);
  lcd.print(mensaje);

}