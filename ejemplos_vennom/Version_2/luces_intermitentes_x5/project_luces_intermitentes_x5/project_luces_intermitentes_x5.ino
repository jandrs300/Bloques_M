void setup() {
  pinMode(6, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  for (int i = 0; i < 5; ++i)
  {
    digitalWrite(6, 1);
    delay(1000);
    digitalWrite(6, 0);
    delay(1000);
  }
  analogWrite(6, 150);
  analogWrite(5, 0);
  analogWrite(3, 255);
  delay(1000);
  analogWrite(6, 0);
  analogWrite(5, 0);
  analogWrite(3, 0);
  for (int i = 0; i < 5; ++i)
  {
    digitalWrite(5, 1);
    delay(1000);
    digitalWrite(5, 0);
    delay(1000);
  }
  analogWrite(6, 150);
  analogWrite(5, 0);
  analogWrite(3, 255);
  delay(1000);
  analogWrite(6, 0);
  analogWrite(5, 0);
  analogWrite(3, 0);
  for (int i = 0; i < 5; ++i)
  {
    digitalWrite(3, 1);
    delay(1000);
    digitalWrite(3, 0);
    delay(1000);
  }
  analogWrite(6, 150);
  analogWrite(5, 0);
  analogWrite(3, 255);
  delay(1000);

}

void loop() {

}



