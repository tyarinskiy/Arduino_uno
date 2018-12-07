/* светодиод с кнопкой. кнопка просто замыкает цепь
*/

int switchPin = 8; //контакт к которму подключена кнопка

int ledPin = 12;  //контакт к которму подключен светодиод
int activBuz = 7; // активный динамик

void setup() 
{
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(activBuz, OUTPUT);
}

void loop() 
{
  if (digitalRead(switchPin) == HIGH) // если считываем с 8 контакта 1 
  {
    digitalWrite(ledPin, HIGH);       // то считаем, что на 12м контакте (диоде) 1
    
  }
  else
  {
    digitalWrite(ledPin, LOW);        // иначе на 12м 0 (он выключен)  
  }
    
}
