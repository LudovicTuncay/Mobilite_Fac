#pragma once

#include <iostream>
#include "helper/coordonnees.h"
#include "deplacements/deplacement.h"
#include "emplacements/emplacement.h"
#include "emplacements/parking.h"

class Trajet
{
    int nbEtapes;
    int maxEtapes;
    Emplacement **etapes;
    Deplacement *deplacements;
    Parking *positionVoiture;
    Parking *positionVelo;

public:
    Trajet();

    // Ajouter une étape (sans méthode de déplacement, pour la première étape)
    void ajouterEtape(Emplacement emplacement);

    // Ajouter un déplacemenEmplacement emplacementéplacement)
    void ajouterEtape(Emplacement emplacement, std::string methode);

    // Afficher le trajet
    void afficher();

    int getNbEtapes();

    // Calculer la durée du trajet
    double dureeTrajet();

    // Calculer la distance totale du trajet
    double distanceTrajet();

    // Surcharge de l'opérateur [] pour accéder aux étapes du trajet
    Emplacement &operator[](int index);

    // Surcharge de l'opérateur + pour ajouter un déplacement au trajet
    Trajet &operator+(Emplacement emplacement);

    // surcharge de l'opérateur << pour afficher le trajet
    friend std::ostream &operator<<(std::ostream &os, Trajet &trajet);
};
