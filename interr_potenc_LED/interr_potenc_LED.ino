// использум аппаратные прерывания по кнопке для трех светодиодов
int buttonInt = 0; // использем 0е прерывание на 2м пине

int yellowLED = 11;
int redLED = 10;
int greenLED = 9;
int nullLED = 6;    // его нет но мы его задаем чтоб на чем-то остановится или сбросить на 0
volatile int selectedLED = greenLED; //определяем как volat это значит что оно может меняться в теле прогр
int potPin = 0; //потенциометр

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);

  //Подключаем прерывание
  attachInterrupt(buttonInt, swap, RISING); //swap -функция которую мы запускаем по прерыванию
  // RISING - тип прерывания см. ман.здесь восходящие т.е. на замыкание от low к HIGH
  
}

//функция прерывания при нажатии должна переключить светодиод и изменить selectedLED
void swap()
{
  if (selectedLED == greenLED)
    selectedLED = redLED;
  else if (selectedLED == redLED)
    selectedLED = yellowLED;
  else if (selectedLED == yellowLED)
    selectedLED = nullLED;
  else
    selectedLED = greenLED;
}

void loop() {

  int pot = analogRead(potPin);  // счит знач с потенц
  int bright = map(pot, 0, 1023, 0, 255);  // отображ значение с пот на светодиод
  analogWrite(selectedLED, bright); //пишем яркость на выбранный светодиод

}
