void setup() {

  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {

  analogWrite(6, 0);
  analogWrite(5, 100);
  analogWrite(3, 255);
  tone(11, 330, 250); // write to buzzer
  delay(250);
  tone(11, 330, 250); // write to buzzer
  delay(250);
  tone(11, 330, 500); // write to buzzer
  delay(500);
  tone(11, 330, 250); // write to buzzer
  delay(250);
  tone(11, 330, 250); // write to buzzer
  delay(250);
  tone(11, 330, 500); // write to buzzer
  delay(500);
  tone(11, 330, 250); // write to buzzer
  delay(250);
  tone(11, 392, 250); // write to buzzer
  delay(250);
  tone(11, 262, 250); // write to buzzer
  delay(250);
  tone(11, 294, 250); // write to buzzer
  delay(250);
  tone(11, 330, 1000); // write to buzzer
  delay(1000);
  tone(11, 349, 250); // write to buzzer
  delay(250);
  tone(11, 349, 250); // write to buzzer
  delay(250);
  tone(11, 349, 250); // write to buzzer
  delay(250);
  tone(11, 349, 250); // write to buzzer
  delay(250);
  tone(11, 349, 250); // write to buzzer
  delay(250);
  tone(11, 330, 250); // write to buzzer
  delay(250);
  tone(11, 330, 250); // write to buzzer
  delay(250);
  tone(11, 330, 500); // write to buzzer
  delay(500);
  tone(11, 294, 250); // write to buzzer
  delay(250);
  tone(11, 294, 250); // write to buzzer
  delay(250);
  tone(11, 330, 250); // write to buzzer
  delay(250);
  tone(11, 294, 500); // write to buzzer
  delay(500);
  tone(11, 392, 500); // write to buzzer
  delay(500);
  analogWrite(6, 0);
  analogWrite(5, 0);
  analogWrite(3, 0);
  delay(1000);

}

