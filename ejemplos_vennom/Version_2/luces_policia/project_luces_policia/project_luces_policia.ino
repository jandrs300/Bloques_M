void setup(){
    
    pinMode(3,OUTPUT);
    pinMode(6,OUTPUT);
}

void loop(){
    
    digitalWrite(3,1);
    digitalWrite(6,0);
    delay(200);
    digitalWrite(3,0);
    digitalWrite(6,1);
    delay(200);
}


