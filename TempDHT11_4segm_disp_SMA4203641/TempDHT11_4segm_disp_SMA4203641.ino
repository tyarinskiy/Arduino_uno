// цифр датчик температуры и влажности DHT11

#include "DHT.h"
#define dhtPin 3

DHT dht(dhtPin, DHT11);  // инициализация датчика

int anodPins[] = {A1, A2, A3, A4};   // задаем пины для каждого разряда
#define firstPin 5
#define lastPin 12

byte arr[4];  // Переменная-массив для хранения данных, которые не нужно каждый раз пересчитывать
 
  // Для экономии памяти будем хранить данные в байтах
  //{A, B, C, D, E, F, G,DP} - дисплей перевернутый, поэтому все цифры перевернуты!
  byte seg[15] = 
  {
    0b11111100,  //Цифра 0
    0b00001100, //Цифра 1
    0b11011010, //Цифра 2
    0b10011110, //Цифра 3
    0b00101110, //Цифра 4
    0b10110110, //Цифра 5
    0b11110110, //Цифра 6
    0b00011100, //Цифра 7
    0b11111110, //Цифра 8
    0b10111110, //Цифра 9
    0b11110001, // знак C
    0b11100010, // знак t
    0b00100100, // знак %
    0b01100110, // знак р
    0b00000000  // пустой
  };


void setup() {
  for (int i = 0; i < 4; i++)   // аналоговын входы работают как цифров
  {
    pinMode(anodPins[i], OUTPUT);
  }
  for (int i = firstPin; i <= lastPin; i++)
  {
    pinMode(i, OUTPUT); 
  }
  
  Serial.begin(9600);

  dht.begin();  // нащанчаем указанный выше пин как выходной и обнуляем счетчик замеров
  Serial.println("Тест DHT11");


  int err[4] = 
  {
    0b00000000, //Пусто
    0b11110010, //E
    0b01000010, //r
    0b01000010, //r
  };

}

void displayMessage(byte dig[4]) {
   for (int i = 0; i < 4; i++)
  {
    for (int k = firstPin; k <= lastPin; k++)
    {
      digitalWrite(k, ((bitRead(dig[i], 7 - k) == 1) ? LOW : HIGH));
    }
    
  }
}
  
  

void loop() {

  delay(5000);
  float h = dht.readHumidity();   // измеряем влажность
  int t = dht.readTemperature();  // измеряем температуру
  if (isnan(h) || isnan(t)) //если значения не числа (не можем считать nan)
  {
    Serial.print("Не могу считать");  
    return;   //прерывает эту функцию и возвращает ся к основной
  } 
  arr[0] = seg[11];
  arr[3] = seg[10];
  arr[2] = seg[t % 10];
  if (t > 9)
  {
    arr[1] = seg[(int)(t / 10)];  
  }
  else arr[1] = seg[14];
  displayMessage(arr);
}  
 
 /* Serial.print("Влажность: ");
  Serial.print(h);
  Serial.println("%");
  Serial.print("Температура: ");
  Serial.print(t);
  Serial.println("С");
*/
