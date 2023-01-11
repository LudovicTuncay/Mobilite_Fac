#include "emplacements/parking.h"
#include <iostream>
#include <string>

Parking::Parking() : Emplacement()
{
    this->ParkingVelo = false;
}

Parking::Parking(std::string nom, CoordoneesGPS coordonees, bool ParkingVelo) : Emplacement(nom, coordonees, this, nullptr)
{
    this->ParkingVelo = ParkingVelo;
}

Parking::Parking(std::string nom, double latitude, double longitude, bool ParkingVelo) : Emplacement(nom, latitude, longitude, nullptr, this)
{
    this->ParkingVelo = ParkingVelo;
}

bool Parking::isParkingVelo()
{
    return ParkingVelo;
}

bool Parking::isParkingVoiture()
{
    return !ParkingVelo;
}

std::string Parking::getType()
{
    return ParkingVelo ? "vélo" : "voiture";
}

// Donne la durée moyenne depuis l'entrée du parking pour acceder (vice versa)
// a sa voiture ou a son velo, en secondes
// Le temps est de 10 secondes pour un parking à vélo et de 60 secondes pour un
// parking à voiture
double Parking::dureeDepuisEntree()
{
    return ParkingVelo ? 10. : 60.;
}

void Parking::afficher()
{
    std::cout << "Parking " << std::endl
              << "[*] Nom : " << this->nom << std::endl
              << "[*] Coordonees : " << this->coordonees << std::endl
              << "[*] Parking pour " << this->getType() << std::endl;
}

std::ostream &
operator<<(std::ostream &os, const Parking &parking)
{
    os << "Parking " << std::endl
       << "[*] Nom : " << parking.nom << std::endl
       << "[*] Coordonees : " << parking.coordonees << std::endl
       << "[*] ParkingVelo : " << parking.ParkingVelo << std::endl;
    return os;
}
