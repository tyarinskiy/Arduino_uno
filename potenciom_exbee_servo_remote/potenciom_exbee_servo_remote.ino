// управление потенциометром с одного ардуино сервой на другом. в качестве связи xbee

int potPin = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {

  int val = map(analogRead(potPin), 0, 1023, 0, 9);   // отображ значения с аналогового входа на значения от 0 до 9
// это значит что передаем 1 байт данных и не бедет трудностей на втором конце с обработкой. Получается, что
// мы передаем 9 разных значений для привода
  Serial.println(val);
  delay(50);  

}
