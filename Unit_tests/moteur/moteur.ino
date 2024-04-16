/*

TODO : revoir les pin apres les tests

Pont en H

Branchement :

IN1 -> Pin 6 left_fwd
IN2 -> Pin 7 left_fwd
IN3 -> Pin 8 left_fwd
IN4 -> Pin 9 left_fwd

*/


#define left_motor_pin_fwd 6
#define left_motor_pin_bck 7
#define right_motor_pin_fwd 8
#define right_motor_pin_bck 9

#define PWM_SPEED(speed) (speed-10)*25


void setup() {
    pinMode(left_motor_pin_fwd, OUTPUT);
    pinMode(left_motor_pin_bck, OUTPUT);
    pinMode(right_motor_pin_fwd, OUTPUT);
    pinMode(right_motor_pin_bck, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}


void go_strait(int speed){
    if(speed==10){ // STOP
        analogWrite(left_motor_pin_fwd, 0);
        analogWrite(left_motor_pin_bck, 0);
        analogWrite(right_motor_pin_fwd, 0);
        analogWrite(right_motor_pin_bck, 0);
    }
    else if(speed<10){ // Go backward 
        analogWrite(left_motor_pin_fwd, 0);
        analogWrite(left_motor_pin_bck, PWM_SPEED(speed));
        analogWrite(right_motor_pin_fwd, 0);
        analogWrite(right_motor_pin_bck, PWM_SPEED(speed));
    }
    else { // Go forward
        analogWrite(left_motor_pin_fwd, PWM_SPEED(speed));
        analogWrite(left_motor_pin_bck, 0);
        analogWrite(right_motor_pin_fwd, PWM_SPEED(speed));
        analogWrite(right_motor_pin_bck, 0);
    }
  
}

void turn(int speed, int direction){
    /*
    Changer les temps après les tests
    */
    
    // stopper les moteurs avant de tourner
    analogWrite(left_motor_pin_fwd, 0);
    analogWrite(left_motor_pin_bck, 0);
    analogWrite(right_motor_pin_fwd, 0);
    analogWrite(right_motor_pin_bck, 0);
    delay(100);

    switch(direction){
        case 'l': // Tourner à gauche
            analogWrite(left_motor_pin_fwd, 0);
            analogWrite(left_motor_pin_bck, PWM_SPEED(speed));
            analogWrite(right_motor_pin_fwd, PWM_SPEED(speed));
            analogWrite(right_motor_pin_bck, 0);
            break;
        case 'r': // Tourner à droite
            analogWrite(left_motor_pin_fwd, PWM_SPEED(speed));
            analogWrite(left_motor_pin_bck, 0);
            analogWrite(right_motor_pin_fwd, 0);
            analogWrite(right_motor_pin_bck, PWM_SPEED(speed));
            break;
        case 'g': // Tourner vers l'arrière à gauche
            analogWrite(left_motor_pin_fwd, 0);
            analogWrite(left_motor_pin_bck, PWM_SPEED(speed));
            analogWrite(right_motor_pin_fwd, PWM_SPEED(speed));
            analogWrite(right_motor_pin_bck, 0);
            break;
        case 'd': // Tourner vers l'arrière à droite
            analogWrite(left_motor_pin_fwd, PWM_SPEED(speed));
            analogWrite(left_motor_pin_bck, 0);
            analogWrite(right_motor_pin_fwd, 0);
            analogWrite(right_motor_pin_bck, PWM_SPEED(speed));
            break;
        default: // Aucune action si la direction est invalide
            break;
    }
}




