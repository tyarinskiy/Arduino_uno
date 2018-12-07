
#define firstPin 5
#define lastPin 12
#define count_segments 8
#define d4 A1   // пины анодов
#define d3 A2
#define d2 A3
#define d1 A4

int n = 500;

#include "DHT.h"
#define dhtPin 3
DHT dht(dhtPin, DHT11);

byte numberSegments[12] = 
{
  0b00111111,  //0 
  0b00000110,  //1
  0b01011011,  //2
  0b01001111,  //3
  0b01100110,  //4
  0b01101101,  //5 
  0b01111101,  //6 
  0b00000111,  //7 
  0b01111111,  //8
  0b01101111,  //9
  0b00111001, // знак C
  0b01111000, // знак t  
};

void setup() {
  for (int i = firstPin; i <= lastPin; i++)
  {
    pinMode(i, OUTPUT); 
  }
  pinMode(d1, OUTPUT); 
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);

  Serial.begin(9600);

  dht.begin();
}

void loop() {
//  delay(10);
  int temp = dht.readTemperature();
  Serial.println(temp);
  if (temp > 9)
  {
    int number1 = temp / 10;
//    int mask = numberSegments[number1];
    numberSeg(3);
    switchSeg(numberSegments[number1]);
    delay(1);
    Clear();
    int number2 = temp % 10;
    numberSeg(2);
    switchSeg(numberSegments[number2]);
    delay(1);
    Clear();
  }
  else {
    int number1 = temp % 10;
    numberSeg(3);
    switchSeg(numberSegments[number1]);
    delay(1);
    Clear();
  }
 // delay(1000);
/*  int number1 = temp % 10;
  int mask = numberSegments[number];
  
  digitalWrite(d1, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, LOW);
  
  for (int i = 0; i <= count_segments; i++)
  { 
    boolean enableSegment = bitRead(mask, i); //bitRead считывает побитно справа на лево
    digitalWrite(i + firstPin, enableSegment);
  }
  */
}

void numberSeg(unsigned int n)
{
  switch(n) {
    case 1:
      digitalWrite(d1, LOW);
      digitalWrite(d2, HIGH);
      digitalWrite(d3, HIGH);
      digitalWrite(d4, HIGH);
    break;
    case 2:
      digitalWrite(d1, HIGH);
      digitalWrite(d2, LOW);
      digitalWrite(d3, HIGH);
      digitalWrite(d4, HIGH);
    break;
    case 3:
      digitalWrite(d1, HIGH);
      digitalWrite(d2, HIGH);
      digitalWrite(d3, LOW);
      digitalWrite(d4, HIGH);
    break;
    case 4:
      digitalWrite(d1, HIGH);
      digitalWrite(d2, HIGH);
      digitalWrite(d3, HIGH);
      digitalWrite(d4, LOW);
    break;
    default:
      digitalWrite(d1, HIGH);
      digitalWrite(d2, HIGH);
      digitalWrite(d3, HIGH);
      digitalWrite(d4, HIGH);
    break;
  }
}

void switchSeg(unsigned int fig)
{
  for (int i = 0; i <= count_segments; i++)
  { 
    boolean enableSegment = bitRead(fig, i); //bitRead считывает побитно справа на лево
    digitalWrite(i + firstPin, enableSegment);
    delay(1);
//    digitalWrite(i + firstPin, !enableSegment);
  }  
}
void Clear()
{
  for (int i = firstPin; i <= lastPin; i++)
  {
    digitalWrite(i, LOW);
  }
}
