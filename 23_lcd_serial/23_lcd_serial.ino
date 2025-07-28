#include <DHT.h>
#include <DHT_U.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SDA 13
#define SCL 14
#define SENSOR 5
#define DHTTYPE DHT11
DHT dht(SENSOR, DHTTYPE);

float temp = 0.0;
float hum = 0.0;

#define ADDR  0x27  //0x3F  //0x27

LiquidCrystal_I2C lcd(ADDR, 16, 2);

void setup() {

  dht.begin();
  Serial.begin(115200);  
  Wire.begin(SDA, SCL);
//  Wire.beginTransmission(ADDR); esto depende del modelo
  lcd.init();
  lcd.clear();
  lcd.backlight();
  Serial.println("Empezamos");

}

void loop() {
  
  
  lcd.setCursor(0, 0);
  if(Serial.available() != 0){
    delay(100);
    lcd.clear();
    while(Serial.available() > 0){
      lcd.write(Serial.read());
  }
  delay(3000);
  lcd.clear();
  }

  temp = dht.readTemperature();
  hum = dht.readHumidity();
  // lcd.print("Temp: " + String(temp) + (char)223 +"C");
  // lcd.print("Hum: " + String(hum) + "%");
  lcd.print("Tem: ");
  lcd.print(temp);
  lcd.print(char(223));
  lcd.setCursor(0,1);
  lcd.print("Hum: ");
  lcd.print(hum);
  lcd.print("%");
  delay(3000);

}
