// температурный датчик LM35

int tempPin = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  int val;
  int dat;
  val = analogRead(0);
  dat = (125*val)>>8; // формула расчета температуры (сдвиг влево на 8)
  Serial.print("Temp:");
  Serial.print(dat);
  Serial.println("C");
  delay(500);
  
}
