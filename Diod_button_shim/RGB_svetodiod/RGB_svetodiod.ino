//RGB светодиод

int  redPin = 11;
int bluePin = 10;
int greenPin = 9;
int val;

void setup() {

  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  for(val=255; val>0; val--)
  {
    analogWrite(redPin, val);
    analogWrite(bluePin, 255-val);
    analogWrite(greenPin, 128-val);
    delay(10);
  }
  for(val=0; val<255; val++);
  {
    analogWrite(redPin, val);
    analogWrite(bluePin, 255-val);
    analogWrite(greenPin, 128-val);
    delay(10);
   }
   Serial.println(val, DEC); // выводит в десятичном формате
   

}
