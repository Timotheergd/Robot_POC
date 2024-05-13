#include <stdio.h>
#include <stdlib.h>
#include <string.h> // pour memcpy
#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#define taille 23


unsigned long Time;
unsigned long numero=0;
char mode;
int vitesseDonner=254;
int urgence;
char directionDonner='F';
int lancer=1;
unsigned char message[23];
char debut[7]={'{','%','B','R','A','T','*'};
char fin[3]={'*',':','}'};
char messReady[12]={'{','%','B','R','A','T','*','G','0','*',':','}'};
char messUrgency[12]={'{','%','B','R','A','T','*','S','T','*',':','}'};

int caser=0;
char truc[260];

void setup()
{
  Serial.begin(9600);   
  pinMode(A0, INPUT);   
  pinMode(9, INPUT);
  pinMode(8, INPUT);
}
 

void loop()
{
  vitesseDonner=analogRead(A0)/4;
  if(digitalRead(9)==0){
    directionDonner='R';
  }else if(digitalRead(8)==0){
    directionDonner='L';
  }else{
    directionDonner='F';
  }

  if(lancer==0 && (millis()- Time)>100){
    emetteur();
  }
  
  if(lancer==1){
    emetteur();
    lancer=0;
  }
  Read();

  char donneeRead[23];
  if(findMessage(donneeRead)){
    verificationMessage(donneeRead, 23);

    memmove(truc, truc+taille, (caser-taille)*sizeof(char));
    caser=caser-taille;
  }else{
    if(caser>0){
      if(caser>23){ //à supprimer
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