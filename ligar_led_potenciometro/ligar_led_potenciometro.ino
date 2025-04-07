// C++ code
//
/*
  Simulando sensor de luminosidade
  Acende a luz vermelha quando for > 500.
  Acende a luz amarela quando for > 350.
  Acende a luz verde quando for <= 350.
  Obs.: Os valores precisarão ser ajustar quando estiver com o sensor.
*/

int Sensor = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  Serial.print("Luminosidade: ");
  Serial.println(analogRead(A0));
  if (analogRead(A0) > 500) {
    digitalWrite(9, HIGH);    
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
  } else if (analogRead(A0) > 400) {    
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);    
    digitalWrite(9, LOW);
  } else {
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, HIGH);
  }
  delay(50); // Delay a little bit to improve simulation performance
}