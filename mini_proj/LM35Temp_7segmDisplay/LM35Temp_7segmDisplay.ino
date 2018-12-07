// вывод последней цифры с датчика температуры LM35 на дисплей

#define firstPin 2
#define count_segments 9  // #define не выделяет память под перемен как int, а сразу перед процу значение 


// объявляем массив со значениями цифр в битовом представлении, чтоб не задавать кажд цифру отдельно
// всего 10 цифр на 7ми сегментном дисплее, поэтому и массив из 10
byte numberSegments[10] = 
{
  0b01110111, 
  0b00010100, 
  0b10110011, 
  0b10110110, 
  0b11010100, 
  0b11100110, 
  0b11100111, 
  0b00110100, 
  0b11110111,
  0b11110110,
};

void setup() {
  
  for (int i = firstPin; i <= count_segments; i++)
  {
    pinMode(i, OUTPUT); 
  }
  
  Serial.begin(9600);  // для проверки отображ знач
  
}

void loop() {
  
  int val;
  int dat;
  val = analogRead(0);
  dat = (125*val)>>8;
//  = (125*analogRead(A0))>>8;  // формула расчета температуры (сдвиг влево на 8)
  Serial.println(dat);
 // delay(1000);
  int number = dat % 10;
  // делим с остатком после делен на 10, т.е. получаем последн цифру
  int mask = numberSegments[number]; // получаем код из массива, в кот содержится полученная цифра
  // для каждого из 7 сегментов индикатора
  for (int i = 0; i <= count_segments; i++)
  {
    //определяем должен ли быть включен
    boolean enableSegment = bitRead(mask, i);
    // включ или выключ сегменты на основе получ значений
    digitalWrite(i + firstPin, enableSegment);
    
  } 
  delay(1000);  
}
