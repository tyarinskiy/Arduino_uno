/* светодиод с кнопкой. прни нажатии кнопки диод переходит в противоположное состояние и остается в нем, 
  кнопка является переключателем. каждое нажатие увеличивает яркость. со стабилизацией и ШИМ
*/

int switchPin = 8;                   //контакт к которму подключена кнопка
int ledPin = 11;                     //контакт к которму подключен светодиод. Меняем на 11, т.к. не все поддерживают ШИМ (PVM) ~
boolean lastButton = LOW;            //добавляем переменную чтобы знать состояние кнопки на предыдущей иттерации. Изначально 0)
int ledLevel = 0;                    //Шим использ числовые знач от 0 до 255. определяет уровень между 0 и 1
boolean currentButton = LOW;

void setup() 
{
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

boolean debounce(boolean last)     /*добавляем функцию дребезг которй скармливаем значение булеан к которому будем обращатся 
                                      внутри функции по имени ласт. Это предыдущее значение переключателя (ласт)
                                    */
{
  boolean current = digitalRead(switchPin);  // определяем текущее значение перекл (кнопки)
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
     ledLevel = ledLevel + 51;                                       // уровень яркости предыдущий плюс 51 (на него делится 255, можно любое. сейчас 5 разных уровней)
//     lastButtan = HIGH; убираем т.к. значение определяет debounce
  }
  lastButton = currentButton;     
  if (ledLevel > 255) ledLevel = 0;               //если зачение максимальное выключаем светодиодlll
  analogWrite(ledPin, ledLevel);                  //
}
