
#include "SevSeg.h"
SevSeg sevseg; //инициируем контроллер

void setup() {
  byte numDigits = 4; // кол разрядов
  byte digitPins[] = {A1, A2, A3, A4};   //задаем пины анодов
  byte segmentPins[] = {5, 6, 7, 8, 9, 10, 11, 12};  // пины сегментов
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);
}

void loop() {
  sevseg.setNumber(6667,3);
  sevseg.refreshDisplay(); 

}
