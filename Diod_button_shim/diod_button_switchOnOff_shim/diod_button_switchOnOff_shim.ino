/* светодиод с кнопкой. прни нажатии кнопки диод переходит в противоположное состояние и остается в нем, 
  кнопка является переключателем. Добавили стабилизацию кнопки.
*/

int switchPin = 8;                   //контакт к которму подключена кнопка
int ledPin = 12;                     //контакт к которму подключен светодиод
boolean lastButton = LOW;            //добавляем переменную чтобы знать состояние кнопки на предыдущей иттерации. Изначально 0)
boolean ledOn = false;               //добавляем переменную чтобы запоминать состояния севтодиода
boolean currentButton = LOW;

void setup() 
{
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

boolean debounce(boolean last);     /*добавляем функцию дребезг которй скармливаем значение булеан к которому будем обращатся 
                                      внутри функции по имени ласт. Это предыдущее значение переключателя (ласт)
                                    */
{
  boolean cuurent = digitalRead(switchPin);  // определяем текущее значение перекл (кнопки)
  if (last != current)
  {
    delay(5);                                 // даем кнопке время чтоб перестать скакать
    current = digitalRead(switchPin);         //считываем устаканившееся значение
  }
  return current;                             // дает нам стабилизирован знаечение
}

void loop() 
{
  currentButton = debounce(lastButton);
  if (lastButton == LOW && currentButton == HIGH) // по сути нажатие кнопки
  {
     ledOn = !ledOn;                                       // инвертируем
//     lastButtan = HIGH; убираем т.к. значение определяет debounce
     
  }
   
  lastButton = currentButton;     
  
  digitalWrite(ledPin, ledOn); 
}
