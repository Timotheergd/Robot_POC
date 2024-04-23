#include "Ultrasonic.h"
#include "moteur2.ino"
#define DISTANCE_SEUIL 20 // seuil de 20cm

Ultrasonic ultrasonic(2);

// définir les pin utilisés par le buzzer 
int buzzer = 10; 

// définir les pin utilisés par les moteurs
#define left_motor_pin_fwd 6
#define left_motor_pin_bck 7
#define right_motor_pin_fwd 8
#define right_motor_pin_bck 9

#define offset_motor_left -9

// #define PWM_SPEED(speed) (speed-10)*25 // Theorique
#define PWM_SPEED(speed) (speed*2)-256

#define TPS_VIRAGE1 2000
#define TPS_TT_DROIT 6000
#define TPS_VIRAGE2 8000


unsigned long begin_turn = millis();


void setup(){
    Serial.begin(9600);
    pinMode(buzzer, OUTPUT);
    pinMode(left_motor_pin_fwd, OUTPUT);
    pinMode(left_motor_pin_bck, OUTPUT);
    pinMode(right_motor_pin_fwd, OUTPUT);
    pinMode(right_motor_pin_bck, OUTPUT);
}

void loop(){
  avoidObstacle(128, "F", &begin_turn, &turning);
}



void avoidObstacle(int speedy, char dir, unsigned long begin_turn, bool *turning){

    static unsigned long last_buzz_time = 0; 
    static int buzz_count = 0; 
    
    int speed = PWM_SPEED(speedy);
    int RangeInCentimeters = ultrasonic.MeasureInCentimeters();
    unsigned long current_time = millis(); // Temps actuel

    //faire 5 bips toutes les secondes
    vincentlagaf();
        
   /* analogWrite(right_motor_pin_fwd, speed+offset_motor_left);
    analogWrite(right_motor_pin_bck, 0);
    // att qu'on tourne à droite de 90° ou 45°
    */
    
    if (RangeInCentimeters <= DISTANCE_SEUIL){
   
        if (millis()-*begin_turn<TPS_VIRAGE1){
            if (!turning) begin_turn = millis(){
                *turning=true;
                go(speed, "R");
            }

        else if(millis()-*begin_turn<TPS_TT_DROIT){
            go(speed, "F");
        }
            
        else if(millis()-*begin_turn<TPS_VIRAGE2){
            go(speed, "R");
        }
        else{
            *turning=false;
        }
    }
    
}


