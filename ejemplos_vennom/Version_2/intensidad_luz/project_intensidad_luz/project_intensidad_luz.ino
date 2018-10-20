void setup() {
  pinMode(5, OUTPUT);
}

void loop() {
  analogWrite(5, 0);
  delay(1000);
  analogWrite(5, 50);
  delay(1000);
  analogWrite(5, 100);
  delay(1000);
  analogWrite(5, 150);
  delay(1000);
  analogWrite(5, 255);
  delay(1000);

}



