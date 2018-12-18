/*
 * считываем все данные с карты
 * 
 * используем RC522
 * 
 * Подключение:
 * 
 * RST - pin 9
 * MISO - pin 12
 * MOSI - pin11
 * SCK - pin 13
 * NSS (SS, SDA) - pin 10
 */

#include <SPI.h>
#include <MFRC522.h>

#define rstPin 9
#define nssPin 10

//инициализируем MFRC522
MFRC522 mfrc522(nssPin, rstPin);   // создаем сущьность mrfc

void setup() {
  Serial.begin(9600);
  SPI.begin(); // инициализация SPI
  mfrc522.PCD_Init();  // инициализация MFRC522
  Serial.println("Ready");
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent())
  return;
  if ( ! mfrc522.PICC_ReadCardSerial())  // читаем карту
  return;
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}
  
