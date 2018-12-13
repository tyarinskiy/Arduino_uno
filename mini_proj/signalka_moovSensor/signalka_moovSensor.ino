/* 
 *  сигналка с сенсором движеня, пищалкой и мигалкой из светодиодов
*/

int movPin = 3; //контакт к которму подключена кнопка

int ledredPin = 12;  //контакт к которму подключен светодиод
int ledbluePin = 11; // светодиод сигнализирующий постановку на охрану
int activBuz = 7; // активный динамик

void setup() 
{
  pinMode(movPin, INPUT);
  pinMode(ledredPin, OUTPUT);
  pinMode(activBuz, OUTPUT);
  pinMode(ledbluePin, OUTPUT);
}

void loop() 
{
  
  if (digitalRead(movPin) == HIGH) // если считываем с 8 контакта 1 
  {
    digitalWrite(ledredPin, HIGH);       // то считаем, что на 12м контакте (диоде) 1
    digitalWrite(ledbluePin, LOW);    
    tone(activBuz, 400);
    delay(300);
    digitalWrite(ledredPin, LOW);
    digitalWrite(ledbluePin, HIGH);  
    tone(activBuz, 1200);
    delay(300);  
  }
  else
  {
    digitalWrite( ledredPin, LOW);        // иначе на 12м 0 (он выключен)
    digitalWrite(ledbluePin, LOW);
    noTone(activBuz);  
  }
    
}
