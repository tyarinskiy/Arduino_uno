// прога для управления цветом на экране компа через потенциометр с ардуино
//на компе программируем на языке processing сейчас не рассматриваю

int potPint = 0;

void setup() {

  Serial.begin(9600);    // открываем сериал соединение

}

void loop() {

  int val = map(analogRead(potPin), 0, 1023, 0, 255);  //отображаем 10ти битн значение с portPin 
//и отображаем от 0 до 255. Это РГБ цвета на экране.
  Serial.println(val);        // отправл значение на комп println выводит каждое значение в новую строку
  delay(50);               //задержка т.к. 9600 слишком большая скорость для АЦП наардуино. он не будет успевать преобразовывать
  

}
