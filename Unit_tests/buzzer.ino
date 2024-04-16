int buzzer; 

void setup(){
   Serial.begin(9600);
   pinMode(buzzer, OUTPUT);
}

void loop(){
   // allume le buzzer avec frequence de 500Hz
   tone(buzzer, 500); 
   delay(5000);
   // éteins le buzzer
   noTone(buzzer); // eteins le buzzer 
   delay(500);
}

