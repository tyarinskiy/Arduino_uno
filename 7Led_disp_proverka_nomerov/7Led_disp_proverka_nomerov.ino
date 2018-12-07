// проверка подключения индикатора

#define firstPin 2
#define count_segments 9  // #define не выделяет память под перемен как int, а сразу перед процу значение 

void setup() {
  
  for (int i = firstPin; i <= count_segments; i++)
  {
    pinMode(i, OUTPUT); 
  }
  
  Serial.begin(9600);
  
}

void loop() {
  
  for (int ledPin = 2; ledPin <= 9; ledPin++)
  {
    digitalWrite(ledPin, HIGH);
    Serial.print("PIN: ");
    Serial.println(ledPin);
    delay(10000);
        
  }
  for (int ledPin = 9; ledPin >= 2; ledPin--)
  {
    digitalWrite(ledPin, LOW);
    Serial.print("PIN: ");
    Serial.println(ledPin);
    delay(10000);
  }  

}
