#include <emplacements/batiment.h>
#include <emplacements/salle.h>

#include <iostream>

#define MAX_SALLES 128

Batiment::Batiment(std::string nom, CoordoneesGPS coordonees) : Emplacement(nom, coordonees)
{
    this->maxSalles = MAX_SALLES;
    this->nbSalles = 0;
    this->salles = new Salle[this->maxSalles];
}

Batiment::Batiment(std::string nom, double latitude, double longitude) : Emplacement(nom, latitude, longitude)
{
    this->maxSalles = MAX_SALLES;
    this->nbSalles = 0;
    this->salles = new Salle[this->maxSalles];
}

void Batiment::ajouterSalle(Salle &salle)
{
    if (this->nbSalles < this->maxSalles)
    {
        this->salles[this->nbSalles] = salle;
        this->nbSalles++;
    }
}

void Batiment::afficherSalles()
{
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

std::ostream &operator<<(std::ostream &os, const Batiment &batiment)
{
    os << "Batiment " << std::endl
       << "--> Nom        : " << batiment.nom << std::endl
       << "--> Coordonees : " << batiment.coordonees << std::endl
       << "--> # Salles   : " << batiment.nbSalles << std::endl
       << "--> Salles     : " << std::endl;

    for (int i = 0; i < batiment.nbSalles; i++)
    {
        os << batiment.salles[i] << std::endl;
    }
    os << "——————————————————————————————" << std::endl;

    return os;
}
