// скетч для проверки кодировки IR пульта

#include <IRremote.h>  // библиотека для IR приемника

IRrecv irrecv(A0);   //пин к которому подкл приемник
decode_results results;  // присваевает получаемым с пульта сигналы переменной резалтс

int bluePin = 4;
int yellPin1 = 5;
int yellPin2 = 6;
int redPin = 7;
int buzPin = 8;

void setup() {
  irrecv.enableIRIn(); // запускаем прием инфрокрасного сигнала
  pinMode(bluePin, OUTPUT);
  pinMode(yellPin1, OUTPUT);
  pinMode(yellPin2, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(buzPin, OUTPUT);
  
//  Serial.begin(9600);

}

void loop() {
  if (irrecv.decode(&results)) //если данные пришли то
  {
//    Serial.println(results.value);  //выводим значение по сериал
    if (results.value == 3772784863) digitalWrite(bluePin, !digitalRead(bluePin));  // 1 - голубой
    if (results.value == 3772817503) digitalWrite(yellPin1, !digitalRead(yellPin1)); // 2 - желт
    if (results.value == 3772801183) digitalWrite(yellPin2, !digitalRead(yellPin2)); // 3 - желт 2
    if (results.value == 3772780783) digitalWrite(redPin, !digitalRead(redPin)); // 4 - красн

    if (results.value == 3772793023)
    {
      tone(buzPin, 400);
      delay(300);
      tone(buzPin, 1200);
      delay(300);
    }
    if (results.value == 3772837903) noTone(buzPin);
    
    irrecv.resume();   //останавл прием и принимаем следующий сигнал. иначе первый будет сыпаться бесконечно
  }
  

}
