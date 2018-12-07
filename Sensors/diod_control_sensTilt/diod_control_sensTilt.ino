// светодиод выключается от датчика наклона

int ledPin = 9;
int tiltSensPin = 7;
int value;  // переменная для хранения датчика

void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(tiltSensPin, INPUT);
 }

void loop() {
  value = digitalRead(tiltSensPin);
  if (value == HIGH)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }

}
