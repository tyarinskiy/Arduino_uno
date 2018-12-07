// цифр датчик температуры и влажности DHT11

#include "DHT.h"
#define dhtPin 11  

DHT dht(dhtPin, DHT11);  // инициализация датчика

void setup() {
  Serial.begin(9600);
  dht.begin();  // нащанчаем указанный выше пин как выходной и обнуляем счетчик замеров
  Serial.println("Тест DHT11");

}

void loop() {

  delay(5000);
  float h = dht.readHumidity();   // измеряем влажность
  float t = dht.readTemperature();  // измеряем температуру
  if (isnan(h) || isnan(t)) //если значения не числа (не можем считать nan)
  {
    Serial.print("Не могу считать");  
    return;   //прерывает эту функцию и возвращает ся к основной
  }
  Serial.print("Влажность: ");
  Serial.print(h);
  Serial.println("%");
  Serial.print("Температура: ");
  Serial.print(t);
  Serial.println("С");

}
