#include <emplacements/emplacement.h>
#include <helper/coordonnees.h>
#include <iostream>

Emplacement::Emplacement()
{
    this->nom = "";
    this->coordonees = CoordoneesGPS();
    this->parkingVeloPlusProche = nullptr;
    this->parkingVoiturePlusProche = nullptr;
}

Emplacement::Emplacement(std::string nom, CoordoneesGPS coordonees)
{
    this->nom = nom;
    this->coordonees = coordonees;
}

Emplacement::Emplacement(std::string nom, CoordoneesGPS coordonees, Parking *parkingVeloPlusProche, Parking *parkingVoiturePlusProche)
{
    this->nom = nom;
    this->coordonees = coordonees;
    this->parkingVeloPlusProche = parkingVeloPlusProche;
    this->parkingVoiturePlusProche = parkingVoiturePlusProche;
}

Emplacement::Emplacement(std::string nom, double latitude, double longitude)
{
    this->nom = nom;
    this->coordonees = CoordoneesGPS(latitude, longitude);
}

Emplacement::Emplacement(std::string nom, double latitude, double longitude, Parking *parkingVeloPlusProche, Parking *parkingVoiturePlusProche)
{
    this->nom = nom;
    this->coordonees = CoordoneesGPS(latitude, longitude);
    this->parkingVeloPlusProche = parkingVeloPlusProche;
    this->parkingVoiturePlusProche = parkingVoiturePlusProche;
}

std::string Emplacement::getNom()
{
    return this->nom;
}

CoordoneesGPS Emplacement::getCoordonees()
{
    return this->coordonees;
}

std::string Emplacement::coordonnees_to_string()
{
    return this->coordonees.to_string();
}

// double Emplacement::dureeDepuisEntree()
// {
//     return 0;
// }

Parking *Emplacement::getParkingVeloPlusProche()
{
    return parkingVeloPlusProche;
}

Parking *Emplacement::getParkingVoiturePlusProche()
{
    return parkingVoiturePlusProche;
}

void Emplacement::setParkingVeloPlusProche(Parking *parking)
{
    parkingVeloPlusProche = parking;
}

void Emplacement::setParkingVoiturePlusProche(Parking *parking)
{
    parkingVoiturePlusProche = parking;
}

void Emplacement::afficher()
{
    std::cout << "Emplacement " << std::endl
              << "[*] Nom : " << this->nom << std::endl
              << "[*] Coordonees : " << this->coordonees << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Emplacement &emplacement)
{
    os << emplacement.nom;
    return os;
}
