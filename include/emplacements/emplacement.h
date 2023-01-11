#pragma once

#include <iostream>
#include <string>

#include "helper/coordonnees.h"

// #include "emplacements/parking.h"
class Parking;

class Emplacement
{
protected:
    std::string nom;
    CoordoneesGPS coordonees;
    Parking *parkingVeloPlusProche;
    Parking *parkingVoiturePlusProche;

public:
    Emplacement();
    Emplacement(std::string nom, CoordoneesGPS coordonees);
    Emplacement(std::string nom, double latitude, double longitude);
    std::string getNom();
    CoordoneesGPS getCoordonees();
    Parking *getParkingVeloPlusProche();
    Parking *getParkingVoiturePlusProche();
    void setParkingVeloPlusProche(Parking *parking);
    void setParkingVoiturePlusProche(Parking *parking);

    std::string coordonnees_to_string();
    void afficher();

    double dureeDepuisEntree();

    // Operator overloading
    friend std::ostream &operator<<(std::ostream &os, const Emplacement &emplacement);
};
