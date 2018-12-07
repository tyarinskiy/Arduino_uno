
int motorPin = 9;

void setup() {
  pinMode (motorPin, OUTPUT);

}

void loop() {
  //раскруч мотор на максимум от 0 до 255
  for (int i=0; i<=255; i++)     //от 0 до 255 прибавляем по единице (i++)
  {
    analogWrite(motorPin, i);
    delay(10);                   //делаем движение мотора более плавным(задерж на миллисек)
  }
  //удерживаем его на максимальной скорости
  delay(500);
  //останавливаем от 255 до 0
  for (int i=255; i>=0; i--)
  {
    analogWrite(motorPin, i);
    delay(10);
  }
  //удеоживаем его на нуле
  delay(500);
}
