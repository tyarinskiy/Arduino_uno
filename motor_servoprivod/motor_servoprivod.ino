//включаем серво библиотеку
//создаем серво обЪект
#include <Servo.h>
Servo myServo;   //создаем новый серво объект с типом серво чтоб им управлять

//определяем контакт
int servoPin = 9;

void setup() {
  //нет необходимости обьявлять его выходом, это делает библиотека серво
  myServo.attach(servoPin);    //аттачим сервообъект к пину
  }

void loop() {
  // создаем программу которая будет поворачивать серво от 0 до 180
  // с шагом 20 градусов
  for (int i = 0; i <= 180; i=i+20)   
  //после 180 он автоматически повернет в 0, библиотека сама решает сторону поворота
  // основываясь на текущей позиции и позиции куда хотим попасть
  {
    myServo.write(i);
    delay(1000);
  }
}