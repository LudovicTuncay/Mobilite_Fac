#pragma once

#include <iostream>
#include <deplacements/trajet.h>
#include <emplacements/emplacement.h>

class Utilisateur
{
    Trajet trajet;

public:
    Utilisateur();

    void ajouterEtape(CoordoneesGPS coords, std::string methode);

    void afficherTrajet();

    double getDistanceTotale();
    double getDureeTotale();

    // Création d'un trajet à partir de l'entrée standard (clavier)
    // L'utilisateur va entrer les étapes du trajet (salle)
    void CreerTrajet();

    // Operator overloading
    friend std::ostream &operator<<(std::ostream &os, const Utilisateur &utilisateur);
};
