// скетч для проверки кодировки IR пульта

#include <IRremote.h>  // библиотека для IR приемника

IRrecv irrecv(A0);   //пин к которому подкл приемник
decode_results results;  // присваевает получаемым с пульта сигналы переменной резалтс
 
void setup() {
  irrecv.enableIRIn(); // запускаем прием инфрокрасного сигнала

  Serial.begin(9600);

}

void loop() {
  if (irrecv.decode(&results)) //если данные пришли то
  {
    Serial.println(results.value);  //выводим значение по сериал
    irrecv.resume();   //останавл прием и принимаем следующий сигнал. иначе первый будет сыпаться бесконечно
  }
  

}
