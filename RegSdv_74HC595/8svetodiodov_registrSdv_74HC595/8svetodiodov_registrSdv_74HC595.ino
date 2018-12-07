/*
  Shift Register Example
 for 74HC595 shift register
 
 Created 22 May 2009
 Created 23 Mar 2010
 by Tom Igoe

  arduino.ru/Tutorial/registr_74HC595
 
 */
 
//Пин подключен к ST_CP входу 74HC595
int latchPin = 8;
//Пин подключен к SH_CP входу 74HC595
int clockPin = 12;
//Пин подключен к DS входу 74HC595
int dataPin = 11;
 
void setup() {
  //устанавливаем режим OUTPUT
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT); 
  pinMode(clockPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("reset");
}
 
void loop() {
  if (Serial.available() > 0) {
    // Символы от '0' до '9'
    // представлены в ASCII таблице значения от 48 до 57.
    int bitToSet = Serial.read() - 48;
 
    // Записываем HIGH в позицию соответствующую bitToSet
    registerWrite(bitToSet, HIGH);
  }
}
 
// Этот метот записывает байт в регистр
void registerWrite(int whichPin, int whichState) {
// инициализируем и обнуляем байт
  byte bitsToSend = 0;
 
  //Отключаем вывод на регистре
  digitalWrite(latchPin, LOW);
 
  // устанавливаем HIGH в соответствующем бите
  bitWrite(bitsToSend, whichPin, whichState);
 
  // проталкиваем байт в регистр
  shiftOut(dataPin, clockPin, MSBFIRST, bitsToSend);
 
    // "защелкиваем" регистр, чтобы байт появился на его выходах
  digitalWrite(latchPin, HIGH);
}
