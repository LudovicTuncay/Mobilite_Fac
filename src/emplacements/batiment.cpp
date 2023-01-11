#include <emplacements/batiment.h>

#include <iostream>

#define MAX_SALLES 128

Batiment::Batiment() : Emplacement()
{
    salles = new Salle[MAX_SALLES];
    nbSalles = 0;
    parkingVeloPlusProche = nullptr;
    parkingVoiturePlusProche = nullptr;
    this->parkingVeloPlusProche = nullptr;
    this->parkingVoiturePlusProche = nullptr;
}

Batiment::Batiment(std::string nom, CoordoneesGPS coordonees, Parking *parkingVelo, Parking *parkingVoiture) : Emplacement(nom, coordonees)
{
    this->maxSalles = MAX_SALLES;
    this->nbSalles = 0;
    this->salles = new Salle[this->maxSalles];
    this->parkingVeloPlusProche = parkingVelo;
    this->parkingVoiturePlusProche = parkingVoiture;
}

Batiment::Batiment(std::string nom, double latitude, double longitude, Parking *parkingVelo, Parking *parkingVoiture) : Emplacement(nom, latitude, longitude)
{
    this->maxSalles = MAX_SALLES;
    this->nbSalles = 0;
    this->salles = new Salle[this->maxSalles];
    this->parkingVeloPlusProche = parkingVelo;
    this->parkingVoiturePlusProche = parkingVoiture;
}

void Batiment::ajouterSalle(Salle &salle)
{
    if (this->nbSalles >= this->maxSalles)
    {
        std::cout << "Impossible d'ajouter une salle, le batiment est plein" << std::endl;
    }
    this->salles[this->nbSalles] = salle;
    this->nbSalles++;
}

void Batiment::afficherSalles()
{
    std::cout << "Salles du batiment " << this->nom << std::endl;
    for (int i = 0; i < this->nbSalles; i++)
    {
        std::cout << this->salles[i] << std::endl;
    }
}

int Batiment::getNbSalles()
{
    return this->nbSalles;
}

Salle *Batiment::getSalles()
{
    return this->salles;
}

void Batiment::afficher()
{
    std::cout << "Batiment " << std::endl
              << "[*] Batiment   : " << this->nom << std::endl
              << "[*] Coordonees : " << this->coordonees << std::endl
              << "[*] # Salles   : " << this->nbSalles << std::endl;
    //   << "[*] Parking Velo + proche    : " << this->parkingVeloPlusProche->getNom() << std::endl
    //   << "[*] Parking Voiture + proche : " << this->parkingVoiturePlusProche->getNom() << std::endl;
}
