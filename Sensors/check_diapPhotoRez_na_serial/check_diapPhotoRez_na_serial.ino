// проверяем чувствительность светодиодов. т.е. диапазон изменения фоторезистора

// int sensePin = 0; //аналоговое значение на конт 0

void setup() {

// analogReference(DEFAULT);   //не обязательно
  Serial.begin(9600);
}

void loop() {

  Serial.println(analogRead(0));
  delay(500);
}
