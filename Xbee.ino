#include <stdio.h>
#include <stdlib.h>
#include "Xbee.h"


int identification(char tableau[], char ordre[], int grandeur){
  for(int i=0; i<grandeur; i++){
    if(tableau[i]!=ordre[i]){
      return 0;
    }
  }
  return 1;
}

void Read(){ //mets toutes les données reçues dans un tableau
  while (Serial.available() > 0) {
    truc[caser]=Serial.read();
    caser++;
  }
}

void verificationMessageAvecErreur(char tableau[]){

}

int verifvitesse(unsigned char caractere){
  int varVitesse = (int) caractere;
        if(varVitesse<=255 && varVitesse>=0){
          return 1;
        }else{
          return 0;
        }
}

int verifnumero(char tableau[4]){
  byte donner[4];
   for (int i = 0; i < 4; i++) {
      donner[i]=tableau[i];
    }
  unsigned long machin = (donner[0] << 24) | (donner[1] << 16) | (donner[2] << 8) | donner[3];
  if(machin==numero){
    return 1;
  }else{
    return 0;
  }
}

int verifsomme(char tableau[23]){
  byte donner[4];
   for (int i = 0; i < 4; i++) {
      donner[i]=tableau[i+7];
    }
  unsigned long num = (donner[0] << 24) | (donner[1] << 16) | (donner[2] << 8) | donner[3];
   for (int i = 0; i < 4; i++) {
      donner[i]=tableau[i+16];
    }
  unsigned long sommeDonner = (donner[0] << 24) | (donner[1] << 16) | (donner[2] << 8) | donner[3];
  int direc = (int)tableau[12];
  unsigned char variable = tableau[14];
  int speed = (int)variable;
  unsigned long somme = num+direc+speed;

  if(somme==sommeDonner){
    return 1;
  }else{
    return 0;
  }
}

void renvoi(char tableau[23]){
  byte donner[4];
   for (int i = 0; i < 4; i++) {
      donner[i]=tableau[i];
    }
  unsigned long machin = (donner[0] << 24) | (donner[1] << 16) | (donner[2] << 8) | donner[3];
  delay(10);
  for(int i=0; i<taille; i++){
    Serial.write(tableau[i]);
  }
}

// void emetteur(){
//   //numero++;
//   byte octet1 = numero >> 24;
//   byte octet2 = (numero >> 16) & 0xFF;
//   byte octet3 =  (numero >> 8) & 0xFF;
//   byte octet4 = numero & 0xFF;
//   char tabNUM[]={(char)octet1, (char)octet2, (char)octet3, (char)octet4};

//   unsigned long somme=vitesseDonner+numero+(int)direction;
//   octet1 = somme >> 24;
//   octet2 = (somme >> 16) & 0xFF;
//   octet3 =  (somme >> 8) & 0xFF;
//   octet4 = somme & 0xFF;
//   char tabSOM[]={(char)octet1, (char)octet2, (char)octet3, (char)octet4};
//   char message[23];
//   // for(int i=0; i<23; i++){
//   //   message[i]='O';
//   // }
//   memcpy(message, debut, 7*sizeof(char));
//   memcpy(message+7, tabNUM, 4*sizeof(char));
//   message[11]='+';
//   message[12]=direction;
//   message[13]='+';
//   message[14]=vitesseDonner;
//   message[15]='+';
//   memcpy(message+16, tabSOM, 3*sizeof(char));
//   memcpy(message+20, fin, 3*sizeof(char));
//   for(int i=0; i<14; i++){
//     Serial.write(message[i]);
//   }
// }

void verificationMessage(char tableau[], int grandeur){
  if(grandeur==12){
    if(identification(tableau, messReady, grandeur)){
      lancer=1;
      // urgence=0;
    }else if(identification(tableau, messUrgency, grandeur)){
      // urgence=1;
      lancer=0;
    }
    else{

    }
  }else if(grandeur==23){
    char partie1[7];
    char partie2[3];
    memcpy(partie1, tableau, 7*sizeof(char));
    memcpy(partie2, tableau+20, 3*sizeof(char));
    if(identification(partie1, debut, 7) && identification(partie2, fin, 3) && (tableau[11]=='+' && tableau[13]=='+') && (tableau[12]=='F' || tableau[12]=='R' || tableau[12]=='L')){
          unsigned char varVitesse=tableau[14];
          char num[4];
          memcpy(num, tableau+7, 4*sizeof(char));
          if(verifvitesse(varVitesse) && verifsomme(tableau)){
              if (!verifnumero(num)){ //1ER reçu
                renvoi(tableau);
                byte donner[4];
                for (int i = 0; i < 4; i++) {
                  donner[i]=tableau[i];
                }
                unsigned long numactu = (donner[0] << 24) | (donner[1] << 16) | (donner[2] << 8) | donner[3];
                numero=numactu;

                vitesse=vitesseVerif;
                // Serial.println(vitesse);
                direction=directionVerif;
                directionVerif=tableau[12];
                vitesseVerif=varVitesse;
              }else{ // NACK
                renvoi(tableau);
                directionVerif=tableau[12];
                vitesseVerif=varVitesse;
              }
            }
            // Serial.println(vitesse);
    }else{
      // Serial.println("nononnonon");
    }
  }else{
    verificationMessageAvecErreur(tableau);
  }
  // Serial.print("fin ");
  // if(caser>200){
  //   Serial.println(caser);
  // }
}

int findMessage( unsigned char donneeRead[23]){ // trouve les bordures des messages
  if(caser>0 && truc[0]=='{'){
    if(caser>=taille && truc[taille-1]=='}'){
      for(int y=0; y<taille; y++){
        // Serial. print(truc[y]);
        // Serial.print("    ");
        donneeRead[y]=truc[y];
      }
      // Serial.println();
      return 1;
    }
  }
  return 0;
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

void trame(){
  unsigned char donneeRead[23];
  if(findMessage(donneeRead)){
    
    verificationMessage(donneeRead, 23);
    
    memmove(truc, truc+taille, (caser-taille)*sizeof(char));
    caser=caser-taille;
  }else{
    if(caser>0){
      if(caser>23){ // à enlever
      memmove(truc, truc+1, (caser-1)*sizeof(char));
      caser=caser-1;
      }
    }
  } 
  if(caser>150){
    memmove(truc, truc+1, 0);
    caser=0;
  }
}

void urgence(){
  for(int i=0; i<12; i++){
    lancer=0;
    Serial.write(messUrgency[i]);
  }
  analogWrite(left_motor_pin_fwd, 0);
  analogWrite(left_motor_pin_bck, 0);
  analogWrite(right_motor_pin_fwd, 0);
  analogWrite(right_motor_pin_bck, 0);
}

void fuser(){
  for(int i=0; i<12; i++){
    Serial.write(messReady[i]);
  }
}

void VincentLagaf(){
  for(int i=0;i<5;i++){
    digitalWrite(buzzpin,1);
    delay(1000);
    digitalWrite(buzzpin,0);
    delay(200);
  }
}


void autonome(int speedy){

    static unsigned long last_buzz_time = 0; 
    static int buzz_count = 0; 
    
    int speed = PWM_SPEED(speedy);
    unsigned long current_time = millis(); // Temps actuel

    //faire 5 bips toutes les secondes
    // Vincentlagaf();

    if (!turning) begin_turn = millis();
        
    lcd.clear();
          lcd.print(RangeInCentimeters);
    if (RangeInCentimeters <= DISTANCE_SEUIL || turning){
   
        if ((millis()-begin_turn)<TPS_VIRAGE1){
            // 
            turning=true;
            go(speed, 'R');
            
        }

        else if((millis()-begin_turn)<TPS_TT_DROIT){
            go(speed, 'F');
            lcd.clear();
          lcd.print(RangeInCentimeters);
        }
            
        else if(millis()-begin_turn<TPS_VIRAGE2){
            go(speed, 'L');
        }
        else{
            turning=false;
            go(speed, 'F');
        }
    }
  }




