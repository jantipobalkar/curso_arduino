#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SDA 13
#define SCL 14

#define ADDR  0x27  //0x3F  //0x27


void setup() {
  
    Serial.begin(115200);
 // byte count = 0;
  for(byte i = 0; i < 120; i++){
    Wire.beginTransmission(i);
    if(Wire.endTransmission() == 0){
      Serial.print("Dirección encontrada: ");
   //   Serial.print(i, DEC);
      Serial.print(" 0x");
      Serial.print(i, HEX);
     // count++;
      }
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
