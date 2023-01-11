#pragma once

#include <emplacements/emplacement.h>

class Emplacement;

class Deplacement
{
protected:
    Emplacement emplacementDepart;
    Emplacement emplacementArrivee;
    std::string methode;
    std::string APIdata;

public:
    Deplacement();
    Deplacement(Emplacement emplacementDepart, Emplacement emplacementArrivee, std::string methode);

    Emplacement getEmplacementDepart();
    Emplacement getEmplacementArrivee();

    double distanceDeplacement();
    double dureeDeplacement();

    // Operator overloading
    friend std::ostream &operator<<(std::ostream &os, Deplacement &deplacement);
};
