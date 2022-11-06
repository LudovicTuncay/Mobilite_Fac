#pragma once

#include <iostream>
#include <string>

#include "helper/coordonnees.h"

class Emplacement
{

protected:
    std::string nom;
    CoordoneesGPS coordonees;

public:
    Emplacement();
    Emplacement(std::string nom, CoordoneesGPS coordonees);
    Emplacement(std::string nom, double latitude, double longitude);
    std::string getNom();
    CoordoneesGPS getCoordonees();

    // Operator overloading
    friend std::ostream &operator<<(std::ostream &os, const Emplacement &emplacement);
};
