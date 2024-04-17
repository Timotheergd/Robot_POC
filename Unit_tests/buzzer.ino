// définir les pin utilisés par le buzzer stop et son bouton (à changer stv)
int buzzer = 10; 
int stop_button_pin = 11;

// définir les pin utilisés par les moteurs
#define left_motor_pin_fwd 6
#define left_motor_pin_bck 7
#define right_motor_pin_fwd 8
#define right_motor_pin_bck 9

void setup(){
   Serial.begin(9600);
   pinMode(buzzer, OUTPUT);
   pinMode(stop_button_pin, INPUT_PULLUP);
   pinMode(left_motor_pin_fwd, OUTPUT);
   pinMode(left_motor_pin_bck, OUTPUT);
   pinMode(right_motor_pin_fwd, OUTPUT);
   pinMode(right_motor_pin_bck, OUTPUT);
}


void loop(){
   if (digitalRead(stop_button_pin) == LOW) {
      // allumer le buzzer avec une fréquence de 500Hz pendant 5s
      tone(buzzer, 500); 
      delay(5000); // c'est pas comme ça que ça marche Liam
   

      // arrêter les moteurs 
      analogWrite(left_motor_pin_fwd, 0);
      analogWrite(left_motor_pin_bck, 0);
      analogWrite(right_motor_pin_fwd, 0);
      analogWrite(right_motor_pin_bck, 0);
      
      // éteindre le buzzer
      noTone(buzzer);
      delay(500);
   }
}
