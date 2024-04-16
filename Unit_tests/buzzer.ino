int buzzer; 

#define left_motor_pin_fwd 6
#define left_motor_pin_bck 7
#define right_motor_pin_fwd 8
#define right_motor_pin_bck 9


void setup(){
   Serial.begin(9600);
   pinMode(buzzer, OUTPUT);
   pinMode(left_motor_pin_fwd, OUTPUT);
   pinMode(left_motor_pin_bck, OUTPUT);
   pinMode(right_motor_pin_fwd, OUTPUT);
   pinMode(right_motor_pin_bck, OUTPUT);
}


void loop(){
   // allume le buzzer avec frequence de 500Hz
   tone(buzzer, 500); 
   delay(5000);
   // stopper le moteur 
   analogWrite(left_motor_pin_fwd, 0);
   analogWrite(left_motor_pin_bck, 0);
   analogWrite(right_motor_pin_fwd, 0);
   analogWrite(right_motor_pin_bck, 0);
   
   // éteins le buzzer
   noTone(buzzer);
   delay(500);
}
