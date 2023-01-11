#pragma once

#include <iostream>
#include <deplacements/trajet.h>
#include <emplacements/emplacement.h>

class Utilisateur
{
    Trajet trajet;

public:
    Utilisateur();

    double getDistanceTotale();
    double getDureeTotale();

    // Création d'un trajet à partir de l'entrée standard (clavier)
    // L'utilisateur va entrer les étapes du trajet (salle)
    void creerTrajet(Emplacement *emplacements, int nb_emplacements, std::string *methodes, int nb_methodes);

    // Operator overloading
    friend std::ostream &operator<<(std::ostream &os, Utilisateur &utilisateur);
};
