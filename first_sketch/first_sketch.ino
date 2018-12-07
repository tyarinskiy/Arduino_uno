
int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  //инициализация контакта в качестве выхода
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //устанавлваем цифровой выход
  digitalWrite(ledPin, HIGHT); //подаем 1 на пин
  delay(1000); //задержка 1сек
  digitalWrite(ledPin, LOW);
  delay(1000);
}
