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
const uint8_t valid_uid[] = {0x84, 0xFC, 0x44, 0x1E};

void setup() {
  Serial.begin(9600);
  SPI.begin(); // инициализация SPI
  mfrc522.PCD_Init();  // инициализация MFRC522
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent()) //ждем новую карту
  return;
  if ( ! mfrc522.PICC_ReadCardSerial())  // читаем карту
  return;
  if ((mfrc522.uid.size == sizeof(valid_uid)) &&   // если UID карты равен по разрядности с валидной
    (memcmp(&mfrc522.uid.uidByte, &valid_uid, sizeof(valid_uid)) == 0)) //побитово сравниваем символы UID новой карты с эталоном в количестве sieof  
  // если они равны функция memcmp возвращает 0
  {
    Serial.println("prohodi dorogoy");
  }
  else
  {
    Serial.println("hren tebe");
  }
  }
  
