void setup(){
    
    pinMode(6,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(3,OUTPUT);
}

void loop(){
    
    digitalWrite(6,1);
    digitalWrite(5,0);
    digitalWrite(3,0);
    delay(1000);
    digitalWrite(6,0);
    digitalWrite(5,1);
    digitalWrite(3,0);
    delay(1000);
    digitalWrite(6,0);
    digitalWrite(5,0);
    digitalWrite(3,1);
    delay(1000);
    
}

