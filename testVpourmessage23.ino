#include <Wire.h>
#include "Xbee.h"
#include "rgb_lcd.h"
#include "Ultrasonic.h"
Ultrasonic ultrasonic(4);

#define taille 23

#define buzzpin 5

#define left_motor_pin_fwd 6 // vert
#define left_motor_pin_bck 7 // rouge
#define right_motor_pin_fwd 8 // violet
#define right_motor_pin_bck 9 // bleu
#define urgencyButt 3

#define offset_motor_left 0
#define DISTANCE_SEUIL 20 // seuil de 20cm


// #define PWM_SPEED(speed) (speed-10)*25 // Theorique
#define PWM_SPEED(speed) (speed*2)-256

#define TPS_VIRAGE1 500
#define TPS_TT_DROIT TPS_VIRAGE1+750
#define TPS_VIRAGE2 TPS_TT_DROIT+400

long RangeInCentimeters;

unsigned long begin_turn = millis()+10000;
bool turning=false;


int caser=0;
char truc[260];
rgb_lcd lcd;

unsigned long Time=0;
unsigned long Time2=0;
unsigned long numero=10;
char mode;
int vitesse=0;
int vitesseVerif=0;
char direction=' ';
char directionVerif=' ';
// int urgence;
int lancer=1;
int lancement=0;
char debut[7]={'{','%','B','R','A','T','*'};
char fin[3]={'*',':','}'};
char messReady[12]={'{','%','B','R','A','T','*','G','0','*',':','}'};
char messUrgency[12]={'{','%','B','R','A','T','*','S','T','*',':','}'};




void setup() {
  lcd.begin(16, 2);
  lcd.setRGB(0, 255, 0);
  Serial.begin(9600);

  //moteur
  pinMode(left_motor_pin_fwd, OUTPUT);
  pinMode(left_motor_pin_bck, OUTPUT);
  pinMode(right_motor_pin_fwd, OUTPUT);
  pinMode(right_motor_pin_bck, OUTPUT);

  pinMode(urgencyButt, INPUT);
  pinMode(buzzpin, OUTPUT);
}




void loop() {
  if(lancer==1){
    if(millis()>Time2+500){
      lcd.clear();
      RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
      lcd.setCursor(6,0);
      lcd.print(RangeInCentimeters);
      lcd.setCursor(0,0);
      Time2=millis();
    }
    digitalWrite(buzzpin,RangeInCentimeters<=25);
    // lcd.clear();
    lcd.setCursor(0,0);
    if(millis()-Time>100){
      
      lcd.print(vitesse);
      lcd.print(direction);
      Time=millis();
    }

    Read();
    trame();
    go(vitesse, direction);
  }
  else{
    RangeInCentimeters = ultrasonic.MeasureInCentimeters();
    RangeInCentimeters = abs(RangeInCentimeters);
    delay(100);
      autonome(255);

    }
    if(digitalRead(urgencyButt)==0){
      urgence();
      delay(9000);
      lancer=0;
    }
    
  }

