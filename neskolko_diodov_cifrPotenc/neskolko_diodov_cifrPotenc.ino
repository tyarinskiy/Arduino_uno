// подключаем SPI библиотеку
#include <SPI.h>

// устанавливаем слев селектор в пин 10
// остальные пины задаются автоматически при подкл библ SPI
int SS = 10;

void setup() {
  pinMode(SS, OUTPUT);
  // инициализируем класс SPI
  SPI.begin();
  
}

// пишем новую функцию для управления светодиодами, т.к. она будет использоваться в нескольких местах
void setLed(int reg, int level) // void потому что она ничего не возвращает. она просто выполнит что-то
// reg это номер регистра на чипе, всего их 4, но мы используем только 3 их номера соответственно 0,1,2,3
// level от 0 до 255 т.к. потенциометр 8 битный, а 256 - это 8 бит 
{
  digitalWrite(SS, LOW);  // выбираем слейв с которым будем работать. Слейв селектор активен в LOW
  // значит нам надо притянуть контакт к LOW это значит что мы будем общаться с этим устройством
  // пока контакт в LOW мы общаемся с этим устройством и если у нас несколько на одной линии мы можем общаться со всеми сразу
  SPI.transfer(reg);  // функция для отправки инфы, посылаем на чип сигналы. здесь кокое устройство
  SPI.transfer(level); // чип ждет сначала один байт с регистром и затем 1 байт со значением которое пишем в него
  digitalWrite(SS, HIGH); // устанавл слейв селектор снова в хай, т.е. деактивируем его
}

void loop() {

  for (int i=0; i<=2; i++)         // пробегаем по каждому подключенному регистру
  {
    for (int j=50; j<=255; j++)    //увеличиваем яркость на светодиоде. от 50 т.к. до он даже не включится
    {
      setLed(i, j);    // использ нашу функцию чтоб нарастить яркость светодиодов
      delay(20);
    }
    delay(500);   //задержка пока светод годгорит
    for (int j=255, j=50, j--)     // гасим светодиоды
    {
      setLed(i,j);
      delay(20);
    }
  }

}