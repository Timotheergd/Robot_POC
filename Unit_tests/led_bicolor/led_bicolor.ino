/*
Led bi couleur à cathode commune 

longue pin = rouge
pin milieu = cathode commune (ground)
petite pin = vert

s1 = d4 -> rouge gauche
s2 = d3 -> vert gauche
d5 -> rouge droit
d6 -> vert droit

*/

const int bouton = 2;
int etatboutonprecedent;
int etatbouton;
int couleur;

const int pin_left_red = 3;
const int pin_left_green = 4;
const int pin_right_red = 6;
const int pin_right_green = 5;


void setup(){
  // put your setup code here, to run once:
  
  pinMode(pin_left_red, OUTPUT);
  pinMode(pin_left_green, OUTPUT);
  pinMode(pin_right_red, OUTPUT);
  pinMode(pin_right_green, OUTPUT);

  couleur = 1; //couleur à attribuer
  etatbouton = LOW;
  etatboutonprecedent = HIGH;
}


void set_led_motor_state(int speed, int direction){
  if (speed > 10){
    if (direction == 0){ //tout droit 
        //led du moteur de gauche
        digitalWrite(pin_left_red, LOW);
        digitalWrite(pin_left_green, HIGH);
        //led du moteur de droite 
        digitalWrite(pin_right_red, LOW);
        digitalWrite(pin_right_green, HIGH);
        }
    else if (direction == 1){ //tourne à gauche
        //led du moteur de gauche 
        digitalWrite(pin_left_red, LOW);
        digitalWrite(pin_left_green, HIGH);
        //led du moteur de droite 
        digitalWrite(pin_right_red, LOW);
        digitalWrite(pin_right_green, LOW);
    }
    else{ //tourne à droite
        direction == 2;  
        //led du moteur de gauche 
        digitalWrite(pin_left_red, LOW);
        digitalWrite(pin_left_green, LOW);
        //led du moteur de droite
        digitalWrite(pin_right_red, LOW);
        digitalWrite(pin_right_green, HIGH);
        }
    }
  if (speed < 10 && speed > 0){
    if (direction == 3){ //marche arrière
        //led du moteur de gauche 
        digitalWrite(pin_left_red, HIGH);
        digitalWrite(pin_left_green, LOW);
        //led du moteur de droite 
        digitalWrite(pin_right_red, HIGH);
        digitalWrite(pin_right_green, LOW);
        }
  }
  if (speed == 10){ //immobile
        //led du moteur de gauche 
        digitalWrite(pin_left_red, LOW);
        digitalWrite(pin_left_green, LOW);
        //led du moteur de droite 
        digitalWrite(pin_right_red, LOW);
        digitalWrite(pin_right_green, LOW);
        }
  }



void loop() {

  etatbouton = digitalRead(bouton);
  if (etatbouton == HIGH && etatboutonprecedent == LOW){
      if (couleur = 1){
        digitalWrite(pin_left_red, HIGH);
        digitalWrite(pin_left_green, LOW);
        }
      else if (couleur = 2){
        digitalWrite(pin_right_red, LOW);
        digitalWrite(pin_right_green, HIGH);
        }
  }

  set_led_motor_state(10, 2);
  
  etatboutonprecedent = etatbouton;
}
