// выводим время по serial

#include <iarduino_RTC.h>
iarduino_RTC time(RTC_DS3231);

void setup() {
delay(300);
Serial.begin(9600);
time.begin();
}

void loop(){
if (millis() % 1000 == 0)
{
  Serial.println(time.gettime("d-m-Y, H:i:s, D"));
  delay(1);  // чтоб не выводить время немколько раз за 1мс
}
}
