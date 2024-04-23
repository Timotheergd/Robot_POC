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
// #define PWM_SPEED(speed) (speed)


void setup() {
    Serial.begin(9600);
    pinMode(left_motor_pin_fwd, OUTPUT);
    pinMode(left_motor_pin_bck, OUTPUT);
    pinMode(right_motor_pin_fwd, OUTPUT);
    pinMode(right_motor_pin_bck, OUTPUT);
}

unsigned char truc[3];
int vitesse=0;
char direction=' ';

unsigned long Time;

void loop() {

  if (Serial.available() && truc[0]!='N'){
      truc[0]=truc[1];
      truc[1]=truc[2];
      truc[2]=Serial.read();

    }
  
  if(truc[0]=='N'){
    vitesse=(int)truc[1];
    if(vitesse<10){
      vitesse=0;
    }
    direction=truc[2];
    Serial.print(vitesse);
    Serial.print("  ");
    Serial.println(direction);
    for(int i=0; i<3; i++){
      truc[i]=' ';
    }
  }
  
  
  if(millis()-Time<100){
    go(vitesse, direction);
    Time=millis();
  }
}


void go(int speedy, char dir){
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
        analogWrite(left_motor_pin_bck, -speed-2);
        analogWrite(right_motor_pin_fwd, 0);
        analogWrite(right_motor_pin_bck, -speed-2);
    }
    else { // // Go forward

        analogWrite(left_motor_pin_bck, 0);
        analogWrite(right_motor_pin_bck, 0);
        
        if(dir=='R'){
          analogWrite(left_motor_pin_fwd, speed+offset_motor_left);
          analogWrite(right_motor_pin_fwd, 0);
        }

        if(dir=='L'){
          analogWrite(right_motor_pin_fwd, speed);
          analogWrite(left_motor_pin_fwd, 0);
        }

        if(dir=='F'){
          analogWrite(left_motor_pin_fwd, speed+offset_motor_left);
          analogWrite(right_motor_pin_fwd, speed);
        }
    }
}
