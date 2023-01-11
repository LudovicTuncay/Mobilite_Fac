#pragma once

#include <emplacements/emplacement.h>
#include <iostream>
#include <string>

class Parking : public Emplacement
{
protected:
    bool ParkingVelo; // true si parking à vélo, false si parking à voiture

public:
    Parking();
    Parking(std::string nom, CoordoneesGPS coordonees, bool ParkingVelo);
    Parking(std::string nom, double latitude, double longitude, bool ParkingVelo);

    bool isParkingVelo();
    bool isParkingVoiture();

    std::string getType();

    // Redéfinir la méthode dureeDepuisEntree() de la classe Emplacement
    // Donne la durée moyenne depuis l'entrée du parking pour acceder (vice versa)
    // a sa voiture ou a son velo, en secondes
    double dureeDepuisEntree();

    // Affichage des informations du parking
    void afficher();

    // Operator overloading
    friend std::ostream &operator<<(std::ostream &os, const Parking &parking);
};
