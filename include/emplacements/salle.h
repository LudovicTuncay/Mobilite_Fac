#pragma once

#include <iostream>
#include <emplacements/emplacement.h>
#include <emplacements/batiment.h>

class Batiment; // Déclaration anticipée de la classe Batiment pour éviter les erreurs de compilation liées aux dépendances circulaires

class Salle : public Emplacement
{
protected:
    Batiment *batiment;
    int etage;

public:
    Salle();
    Salle(std::string nom, Batiment *batiment, int etage);
    Batiment *getBatiment();
    int getEtage();

    // Operator overloading
    friend std::ostream &operator<<(std::ostream &os, const Salle &salle);
};
