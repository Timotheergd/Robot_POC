/*

TODO : revoir les pin apres les tests

Pont en H

Branchement :

IN3 -> Pin 6 left_fwd
IN4 -> Pin 7 left_bwd
IN2 -> Pin 8 right_fwd
IN1 -> Pin 9 right_bwd

*/


#define left_motor_pin_fwd 6
#define left_motor_pin_bck 7
#define right_motor_pin_fwd 8
#define right_motor_pin_bck 9

#define offset_motor_left -9

// #define PWM_SPEED(speed) (speed-10)*25 // Theorique
#define PWM_SPEED(speed) (speed*2)-256


void setup() {
  Serial.begin(9600);
    pinMode(left_motor_pin_fwd, OUTPUT);
    pinMode(left_motor_pin_bck, OUTPUT);
    pinMode(right_motor_pin_fwd, OUTPUT);
    pinMode(right_motor_pin_bck, OUTPUT);
}

void loop() {
  go(128, "f");
}


void go(int speedy, int dir){
  int speed = PWM_SPEED(speedy);
    // speed btw -255 and 255
    if(speed==0){ // STOP
        analogWrite(left_motor_pin_fwd, 0);
        analogWrite(left_motor_pin_bck, 0);
        analogWrite(right_motor_pin_fwd, 0);
        analogWrite(right_motor_pin_bck, 0);
    }
    else if(speed<0){ // Go backward 
        analogWrite(left_motor_pin_fwd, 0);
        analogWrite(left_motor_pin_bck, -(speed+offset_motor_left));
        analogWrite(right_motor_pin_fwd, 0);
        analogWrite(right_motor_pin_bck, -speed);
    }
    else { // // Go forward
        
        if(dir=="r" || dir=="f"){
          Serial.println("forward left");
          analogWrite(left_motor_pin_fwd, speed+offset_motor_left);
          analogWrite(left_motor_pin_bck, 0);
        }
        if(dir=="l" || dir=="f"){
          Serial.println("forward right");
          analogWrite(right_motor_pin_fwd, speed);
          analogWrite(right_motor_pin_bck, 0);
        }
    }
}
