//выводим значение контакта по ком порту. схема с кнопкой.


int buttonPin = 8; 

void setup() {
  Serial.begin(9600);     // устанавливаем сериал соединение
  pinMode(buttonPin, OUTPUT);

}

void loop() {
 Serial.println(digitalRead(buttonPin));    //печатаем значения со входа
 delay(100);

}
