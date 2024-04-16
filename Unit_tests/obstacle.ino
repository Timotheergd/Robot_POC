#include "Ultrasonic.h"
#define DISTANCE_SEUIL 5 // seuil de 5cm

Ultrasonic ultrasonic(2);

void setup() {
    Serial.begin(9600);
}


void loop() {
    if (distance <= DISTANCE_SEUIL){
        Serial.println("Obstacle detected!");
        eviteObstacle();
    }else{
        continueTaVie();
    }
}

void avoidObstacle() {
    // Arrêter le mouvement avant de tourner
    stopMotors();

    // Effectuer un virage pour éviter l'obstacle (par exemple, tourner à gauche)
    turnLeft();

    // Attendre un court instant pour que le robot tourne
    delay(500);

    // Reprendre le mouvement en avant
    goStraight();
}

void goStraight() {
    // Mettre en marche les moteurs pour avancer
    // (implémentation spécifique à votre configuration matérielle)
}

void turnLeft() {
    // Mettre en marche les moteurs pour tourner à gauche
    // (implémentation spécifique à votre configuration matérielle)
}

void stopMotors() {
    // Arrêter les moteurs
    // (implémentation spécifique à votre configuration matérielle)
}


