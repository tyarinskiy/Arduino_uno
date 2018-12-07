/* светодиод с кнопкой. прни нажатии кнопки диод переходит в противоположное состояние и остается в нем, 
  кнопка является переключателем
*/

int switchPin = 8;                   //контакт к которму подключена кнопка
int ledPin = 12;                     //контакт к которму подключен светодиод
boolean lastButton = LOW;            //добавляем переменную чтобы знать состояние кнопки на предыдущей иттерации. Изначально 0)
boolean ledOn = false;               //добавляем переменную чтобы запоминать состояния севтодиода

void setup() 
{
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  if (digitalRead(switchPin) == HIGH) && lastButton == LOW// если на кнопке 1 и предыд состояние 0 
  {
    ledOn = !ledOn;
    lastButton = HIGH;
  }
  else
  {
    lastButton = digitalWrite(switchPin);        // иначе считываем текущее  
  }
    digitalWrite(ledPin, ledOn);
}
