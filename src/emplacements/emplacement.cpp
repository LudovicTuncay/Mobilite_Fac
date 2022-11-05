#include <emplacements/emplacement.h>
#include <helper/coordonnees.h>
#include <iostream>

Emplacement::Emplacement(std::string nom, CoordoneesGPS coordonees)
{
    this->nom = nom;
    this->coordonees = coordonees;
}

Emplacement::Emplacement(std::string nom, double latitude, double longitude)
{
    this->nom = nom;
    this->coordonees = CoordoneesGPS(latitude, longitude);
}

std::string Emplacement::getNom()
{
    return this->nom;
}

CoordoneesGPS Emplacement::getCoordonees()
{
    return this->coordonees;
}

std::ostream &operator<<(std::ostream &os, const Emplacement &emplacement)
{
    os << "Emplacement " << std::endl
       << "\t-> Nom : " << emplacement.nom << std::endl
       << "\t-> Coordonees : " << emplacement.coordonees << std::endl;
    return os;
}