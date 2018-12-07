int sensePin = 0; //аналоговое значение на конт 0
int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);  // задаем только для цифрового пина, т.к. аналог по умолчанию как вход
}

void loop() {
  int val = analogRead(sensePin);  //получаем значение сенсора
  if (val < 750) digitalWrite(ledPin, HIGH); //вкл диод если значение <800(тень, см. предыдущий примерс выводом значений по кому
  else
  digitalWrite(ledPin, LOW);
}
