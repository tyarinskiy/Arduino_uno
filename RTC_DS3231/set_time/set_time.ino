// задаем  время DS3231

#include <iarduino_RTC.h>
iarduino_RTC time(RTC_DS3231);

void setup() {
delay(300);
Serial.begin(9600);
time.begin();
//0 сек 38 мин 23 часа 23 декабря 2018 года воскрес
time.settime(0,38,23,23,12,18,0);
}

void loop(){
if (millis() % 1000 == 0)
{
  Serial.println(time.gettime("d-m-Y, H:i:s, D"));
  delay(1);  // чтоб не выводить время немколько раз за 1мс
}
}
