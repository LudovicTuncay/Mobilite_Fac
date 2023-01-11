#pragma once

#include <iostream>
#include <emplacements/parking.h>
#include <emplacements/emplacement.h>
#include <emplacements/salle.h>

// Déclaration anticipée de certaine classes pour éviter les erreurs de compilation liées aux dépendances circulaires
class Emplacement;
class Salle;
class Parking;

// Classe qui hérite de Emplacement
class Batiment : public Emplacement
{
protected:
    int maxSalles;
    int nbSalles;
    Salle *salles;
    Parking *parkingVeloPlusProche;
    Parking *parkingVoiturePlusProche;

public:
    Batiment();
    Batiment(std::string nom, CoordoneesGPS coordonees, Parking *parkingVelo, Parking *parkingVoiture);
    Batiment(std::string nom, double latitude, double longitude, Parking *parkingVelo, Parking *parkingVoiture);
    void ajouterSalle(Salle &s);
    void afficherSalles();
    int getNbSalles();
    Salle *getSalles();

    // affichage des informations du batiment
    void afficher();
};
