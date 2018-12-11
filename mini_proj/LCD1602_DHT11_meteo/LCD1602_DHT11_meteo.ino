// выводим данные с DHT11 на LCD
/*
 * RS: pin 12
 * E: pin 11
 * D4: pin 9
 * D5: pin 8
 * D6: pin 7
 * D7: pin 6
 */

#include <LiquidCrystal.h>

//инициализируем объект LCD
LiquidCrystal lcd(12,11,9,8,7,6);   // пины выше. lcd - название

#include "DHT.h"
#define dhtPin 3

// инициализируем DHT
DHT dht(dhtPin, DHT11);

// создаем символы для значка цельсия
byte degree[8] = {
  B00110,
  B01001,
  B01001,
  B00110,
  B00000,
  B00000,
  B00000,
};


void setup() {
  // запускаем lcd интерфейс. 16 и 2 - это 16 блоков и 2 строки
  lcd.begin(16,2);
  // печатаем надпись. 16 символов
  lcd.print("TEMP:");
  // создаем специальные символы для анимации
  lcd.createChar(0,degree);  // 0 порядковый номер

  dht.begin();
  
}

void loop() {

  delay(5000);
  int t = dht.readTemperature();  // считываем температуру
  if (isnan(t))  // есди значение битое ( не численное)
  {
    lcd.setCursor(0,1);  // 0 - номер колонки, 1 - номер строки(вторая)
    lcd.print("Не могу считать");
    return; 
  }
  
  //двигаем курсор в начало строки после прохода
  lcd.setCursor(0,1);  // 0 - номер колонки, 1 - номер строки(вторая)
  lcd.print(t);
  lcd.write((uint8_t)0);
  lcd.print("C");
  
}
