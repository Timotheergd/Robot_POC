#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"



int identification(char tableau[], char ordre[], int grandeur) {
  for (int i = 0; i < grandeur; i++) {
    if (tableau[i] != ordre[i]) {
      return 0;
    }
  }
  return 1;
}

void Read() {  //mets toutes les données reçues dans un tableau
  while (Serial.available() > 0) {
    truc[caser] = Serial.read();
    caser++;
  }
}

void verificationMessageAvecErreur(char tableau[]) {
}

int verifvitesse(unsigned char caractere) {
  int vitesse = (int)caractere;
  if (vitesse <= 255 && vitesse >= 0) {
    return 1;
  } else {
    return 0;
  }
}

int verifnumero(char tableau[4]) {
  byte donner[4];
  for (int i = 0; i < 4; i++) {
    donner[i] = tableau[i];
  }
  unsigned long machin = (donner[0] << 24) | (donner[1] << 16) | (donner[2] << 8) | donner[3];
  if (machin = numero) {
    return 1;
  } else {
    return 0;
  }
}

int verifsomme(char tableau[23]) {
  byte donner[4];
  for (int i = 0; i < 4; i++) {
    donner[i] = tableau[i + 7];
  }
  unsigned long num = (donner[0] << 24) | (donner[1] << 16) | (donner[2] << 8) | donner[3];
  for (int i = 0; i < 4; i++) {
    donner[i] = tableau[i + 16];
  }
  unsigned long sommeRecu = (donner[0] << 24) | (donner[1] << 16) | (donner[2] << 8) | donner[3];
  int direc = (int)tableau[12];
  unsigned char variable = tableau[14];
  int speed = (int)variable;
  unsigned long somme = num + direc + speed;

  if (somme == sommeRecu) {
    return 1;
  } else {
    return 0;
  }
}

void renvoi(char tableau[23]) {
  // direction=tableau[12];
  // vitesse=tableau[14];
  // Serial.println(" oui ");
  for (int i = 0; i < taille; i++) {
    Serial.write(tableau[i]);
  }
}

void emetteur() {
  byte octet1 = numero >> 24;
  byte octet2 = (numero >> 16) & 0xFF;
  byte octet3 = (numero >> 8) & 0xFF;
  byte octet4 = numero & 0xFF;
  char tabNUM[] = { (char)octet1, (char)octet2, (char)octet3, (char)octet4 };

  unsigned long somme = vitesseDonner + numero + (int)directionDonner;
  octet1 = somme >> 24;
  octet2 = (somme >> 16) & 0xFF;
  octet3 = (somme >> 8) & 0xFF;
  octet4 = somme & 0xFF;
  char tabSOM[] = { (char)octet1, (char)octet2, (char)octet3, (char)octet4 };

  memcpy(message, debut, 7 * sizeof(char));
  memcpy(message + 7, tabNUM, 4 * sizeof(char));
  message[11] = '+';
  message[12] = directionDonner;
  message[13] = '+';
  message[14] = (unsigned char)vitesseDonner;
  message[15] = '+';
  memcpy(message + 16, tabSOM, 4 * sizeof(char));
  memcpy(message + 20, fin, 3 * sizeof(char));
  for (int i = 0; i < 23; i++) {
    Serial.write(message[i]);
    delay(1);
  }
}

void verificationMessage(char tableau[], int grandeur) {
  if (grandeur == 12) {
    if (identification(tableau, messReady, grandeur)) {
      lancer = 1;
      urgence = 0;
    } else if (identification(tableau, messUrgency, grandeur)) {
      urgence = 1;
      lancer = 0;
    } else {
    }
  } else if (grandeur == 23) {
    char partie1[7];
    char partie2[3];
    memcpy(partie1, tableau, 7 * sizeof(char));
    memcpy(partie2, tableau + 20, 3 * sizeof(char));
    if (identification(partie1, debut, 7) && identification(partie2, fin, 3) && (tableau[11] == '+' && tableau[13] == '+') && (tableau[12] == 'F' || tableau[12] == 'R' || tableau[12] == 'L')) {
      unsigned char vitesse = tableau[14];
      char num[4];
      memcpy(num, tableau + 7, 4 * sizeof(char));
      if (verifvitesse(vitesse) && verifsomme(tableau)) {
        int error=0;
        for(int i=0; i<23; i++){
          if (tableau[i]!=message[i]) {
            error++;
          }
          if(error==0){
            numero++;
            lancer = 1;
          }
      }
      }
    } else {
      Serial.println("nononnonon");
    }
  } else {
    verificationMessageAvecErreur(tableau);
  }
  // Serial.print("fin ");
  // if(caser>200){
  //   Serial.println(caser);
  // }
}

int findMessage(char donneeRead[23]) {  // trouve les bordures des messages
  if (caser > 0 && truc[0] == '{') {
    if (caser >= taille && truc[taille - 1] == '}') {
      for (int y = 0; y < taille; y++) {
        // Serial. print(truc[y]);
        // Serial.print("    ");
        donneeRead[y] = truc[y];
      }
      Serial.println();
      return 1;
    }
  }
  return 0;
}
