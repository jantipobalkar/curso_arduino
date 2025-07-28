#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SDA 13
#define SCL 14

#define ADDR  0x27  //0x3F  //0x27

LiquidCrystal_I2C lcd(ADDR, 16, 2);

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
  Wire.begin(SDA, SCL);
//  Wire.beginTransmission(ADDR); esto depende del modelo

  lcd.init();
  lcd.noBacklight();
  delay(1000);
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hola Mundo");
  lcd.setCursor(0, 1);
  lcd.print("Que pasa?");

}

void loop() {
  
  /*lcd.display();
  delay(500);
  lcd.noDisplay();
  delay(500);*/ 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: º ");
  lcd.print((char)223); 
  lcd.print("Waa");
  lcd.setCursor(0, 1);
  lcd.print("Hum: %");
  delay(5000);
}
