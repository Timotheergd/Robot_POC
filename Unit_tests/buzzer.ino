int buzzer; 

void setup(){
   Serial.begin(9600);
   pinMode(buzzer, OUTPUT);
}

void loop(){
   // allume le buzzer
   tone(buzzer, 900); 
   delay(500);
   // éteins le buzzer
   noTone(buzzer); // eteins le buzzer 
   delay(500);
}

