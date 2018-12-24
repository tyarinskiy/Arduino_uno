// выводим время на LCD
/*
 * RS: pin 12
 * E: pin 11
 * D4: pin 9
 * D5: pin 8
 * D6: pin 7
 * D7: pin 6
 * 
 * A4 SDA
 * A5 SCL
 */
 
#include <iarduino_RTC.h>
iarduino_RTC time(RTC_DS3231);

#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,9,8,7,6);

void setup() {
delay(300);
//Serial.begin(9600);
time.begin();
lcd.begin(16,2);
}

void loop(){
if (millis() % 1000 == 0)
{
  lcd.setCursor(0,1);
  lcd.print(time.gettime("H:i:s, D"));
//  lcd.print(time.gettime("d-m-Y, H:i:s, D"));
  delay(1);  // чтоб не выводить время немколько раз за 1мс
}
}
