// #pragma once

#include <iostream>
#include "deplacements/trajet.h"
#include "emplacements/emplacement.h"

Trajet::Trajet()
{
    this->nbEtapes = 0;
    this->maxEtapes = 10;
    this->etapes = new Emplacement[maxEtapes];
    this->deplacements = new Deplacement[maxEtapes - 1];
}

void Trajet::ajouterEtape(Emplacement emplacement)
{
    if (nbEtapes < maxEtapes)
    {
        this->etapes[nbEtapes] = emplacement;
        this->nbEtapes++;
    }
}

void Trajet::ajouterEtape(Emplacement emplacement, std::string methode)
{
    if (nbEtapes < maxEtapes)
    {
        etapes[nbEtapes] = emplacement;
        deplacements[nbEtapes - 1] = Deplacement(etapes[nbEtapes - 1], etapes[nbEtapes], methode);
        nbEtapes++;
    }
}

void Trajet::afficher()
{
    for (int i = 0; i < nbEtapes - 1; i++)
    {
        std::cout << "[" << i << "] " << deplacements[i] << std::endl;
    }
}

double Trajet::dureeTrajet()
{
    double duree = 0;
    for (int i = 0; i < nbEtapes - 1; i++)
    {
        duree += deplacements[i].dureeDeplacement();
    }
    return duree;
}

double Trajet::distanceTrajet()
{
    double distance = 0;
    for (int i = 0; i < nbEtapes - 1; i++)
    {
        distance += deplacements[i].distanceDeplacement();
    }
    return distance;
}

Emplacement &Trajet::operator[](int index)
{
    return etapes[index];
}

Trajet &Trajet::operator+(Emplacement emplacement)
{
    if (nbEtapes == 0)
    {
        this->ajouterEtape(emplacement);
    }
    else
    {
        this->ajouterEtape(emplacement, "walking");
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Trajet &trajet)
{
    for (int i = 0; i < trajet.nbEtapes - 1; i++)
    {
        os << "[" << i << "] " << trajet.deplacements[i] << std::endl;
    }
    return os;
}
