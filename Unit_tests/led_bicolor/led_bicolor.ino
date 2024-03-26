const int bouton = 2;
int etatboutonprecedent;
int etatbouton;
int couleur;


void setup(){
  // put your setup code here, to run once:
  const int pin3 = 3;
  pinMode(3, OUTPUT);
  const int pin4 = 4;
  pinMode(4, OUTPUT);
  const int pin5 = 5;
  pinMode(5, OUTPUT);
  const int pin6 = 6;
  pinMode(6, OUTPUT);

  couleur = 1; //couleur à attribuer
  etatbouton = LOW;
  etatboutonprecedent = HIGH;
}


void set_led_motor_state(int speed, int direction){
  if (speed > 0){
    if (direction == 0){ //tout droit 
        //led du moteur de gauche (3 rouge et 4 vert)
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        //led du moteur de droite (5 rouge et 6 vert)
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        }
    else if (direction == 1){ //tourne à gauche
        //led du moteur de gauche (3 rouge et 4 vert)
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        //led du moteur de droite (5 rouge et 6 vert)
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
    }
    else{ //tourne à droite
        //led du moteur de gauche (3 rouge et 4 vert)
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        //led du moteur de droite (5 rouge et 6 vert)
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        }
    }
  }



void loop() {

  etatbouton = digitalRead(bouton);
  if (etatbouton == HIGH && etatboutonprecedent == LOW){
      if (couleur = 1){
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        }
      else if (couleur = 2){
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        }
  }

  set_led_motor_state(10, 0);
  
  etatboutonprecedent = etatbouton;
}
