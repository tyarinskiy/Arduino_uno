/*
 * чткние RFID меток
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
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent())
  return;
  if ( ! mfrc522.PICC_ReadCardSerial())  // читаем карту
  return;
  // выводим результат считывания UID и тип метки
  Serial.print(F("Card UID:"));    // F - перемещение значения во flesh память не используется RAM
  dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
  Serial.println();
  Serial.print(F("PICC type: "));
  byte piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
  Serial.println(mfrc522.PICC_GetTypeName(piccType));
  delay(2000);
}

//Вывод результата в HEX 

void dump_byte_array(byte *buffer, byte bufferSize)
{
  for (byte i = 0; i < bufferSize; i++)
  {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}
  
