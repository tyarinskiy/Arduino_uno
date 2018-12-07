/* 
*/

int movPin = 3; //контакт к которму подключена кнопка

int ledPin = 12;  //контакт к которму подключен светодиод
int activBuz = 7; // активный динамик

void setup() 
{
  pinMode(movPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(activBuz, OUTPUT);
}

void loop() 
{
  if (digitalRead(movPin) == HIGH) // если считываем с 8 контакта 1 
  {
    digitalWrite(ledPin, HIGH);       // то считаем, что на 12м контакте (диоде) 1
//    digitalWrite(activBuz, HIGH);
    tone(activBuz, 400);
    delay(300);
//    tone(activBuz, 800);
//    delay(300);  
    tone(activBuz, 1200);
    delay(300);  
  }
  else
  {
    digitalWrite( ledPin, LOW);        // иначе на 12м 0 (он выключен)
    noTone(activBuz);  
  }
    
}
