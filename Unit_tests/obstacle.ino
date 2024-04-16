#include "Ultrasonic.h"
#define DISTANCE_SEUIL 5 // seuil de 5cm

Ultrasonic ultrasonic(2);

#define left_motor_pin_fwd 6
#define left_motor_pin_bck 7
#define right_motor_pin_fwd 8
#define right_motor_pin_bck 9

#define offset_motor_left -9

// #define PWM_SPEED(speed) (speed-10)*25 // Theorique
#define PWM_SPEED(speed) (speed*2)-256




void setup(){
    Serial.begin(9600);
    pinMode(left_motor_pin_fwd, OUTPUT);
    pinMode(left_motor_pin_bck, OUTPUT);
    pinMode(right_motor_pin_fwd, OUTPUT);
    pinMode(right_motor_pin_bck, OUTPUT);
}

void loop(){
  avoidObstacle(128, "f");
}



void avoidObstacle(int speedy, char dir){
    int speed = PWM_SPEED(speedy);
    int RangeInCentimeters = ultrasonic.MeasureInCentimeters();

    if (RangeInCentimeters <= DISTANCE_SEUIL){
        //stopper moteurs
        analogWrite(left_motor_pin_fwd, 0);
        analogWrite(left_motor_pin_bck, 0);
        analogWrite(right_motor_pin_fwd, 0);
        analogWrite(right_motor_pin_bck, 0);
    
        delay(500);
    
        //tourner dans une direction ayant une distance superieur au DISTANCE_SEUIL
        if(dir=="r" || dir=="f"){
              Serial.println("forward right");
              analogWrite(left_motor_pin_fwd, speed+offset_motor_left);
              analogWrite(left_motor_pin_bck, 0);
        }
        else if(dir=="l" || dir=="f"){
              Serial.println("forward left");
              analogWrite(right_motor_pin_fwd, speed);
              analogWrite(right_motor_pin_bck, 0);
        }
        else if(dir=="f" || RangeInCentimeters <= DISTANCE_SEUIL){
              Serial.println("forward left");
              analogWrite(right_motor_pin_fwd, speed);
              analogWrite(right_motor_pin_bck, 0);
        }
        else{
            analogWrite(left_motor_pin_fwd, 0);
            analogWrite(left_motor_pin_bck, -(speed+offset_motor_left));
            analogWrite(right_motor_pin_fwd, 0);
            analogWrite(right_motor_pin_bck, -speed);
        }}
    else{
            //continuer tout droit
            analogWrite(left_motor_pin_fwd, speed + offset_motor_left);
            analogWrite(left_motor_pin_bck, 0);
            analogWrite(right_motor_pin_fwd, speed);
            analogWrite(right_motor_pin_bck, 0);
    }
}
}







