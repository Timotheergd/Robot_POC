

void loop() {
    // Lire les données des capteurs d'obstacles
    int obstacleDistance = readObstacleSensor(); // Supposons que cette fonction renvoie la distance de l'obstacle en cm

    // Vérifier la distance de l'obstacle
    if (obstacleDistance < DISTANCE_SEUIL) {
        // Si un obstacle est proche, réagir en conséquence
        avoidObstacle();
    } else {
        // Sinon, continuer à se déplacer normalement
        goStraight(SPEED);
    }

    // Autres tâches à exécuter dans la boucle
}

