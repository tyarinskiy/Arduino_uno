// пример скетча с дальномером акустическим HC-SR05. работает как эхолот на отраженном сигнале

int trigPin = 10;
int echoPin = 11;

void setup() {

  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  
  int dutation, distance;
  digitalWrite(trigPin, LOW);  // для большей точности
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);  // устанвл для начала замера
  delayMicroseconds(10)  // столько нужно держать HIGH чтоб начать замер
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // узнаем длительность высокого сигнала на пине Echo
  distance = duration / 58; // считаем расстояние (используется значение скорости звука)
  Serial.print(distance);
  Serial.print("cm");
  delay(100);

}
