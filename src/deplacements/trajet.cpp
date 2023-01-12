// #pragma once

#include <iostream>
#include "deplacements/trajet.h"
#include "emplacements/emplacement.h"
#include "helper/fonctions.h"

Trajet::Trajet()
{
    this->nbEtapes = 0;
    this->maxEtapes = 16;
    this->etapes = new Emplacement *[maxEtapes];
    this->deplacements = new Deplacement[maxEtapes - 1];
    this->positionVoiture = nullptr;
    this->positionVelo = nullptr;
}

void Trajet::ajouterEtape(Emplacement emplacement)
{
    if (nbEtapes < maxEtapes)
    {
        this->etapes[nbEtapes] = &emplacement;
        this->nbEtapes++;
        if (positionVoiture == nullptr)
            this->positionVoiture = emplacement.getParkingVoiturePlusProche();
        if (positionVelo == nullptr)
            this->positionVelo = emplacement.getParkingVeloPlusProche();
    }
}

void Trajet::ajouterEtape(Emplacement emplacement, std::string methode)
{
    if (methode == "velo" && nbEtapes + 3 <= maxEtapes)
    {
        // Dans ce cas, on doit ajouter le fait que la personne doit se déplacer
        // du précédent emplacement vers le parking de à velo le plus proche
        // puis vers le parking à velo le plus proche de l'emplacement d'arivée
        // puis vers l'emplacement d'arrivée

        etapes[nbEtapes] = this->positionVelo;
        deplacements[nbEtapes - 1] = Deplacement(*etapes[nbEtapes - 1], *etapes[nbEtapes], "marche");
        nbEtapes++;
        // 2.
        etapes[nbEtapes] = emplacement.getParkingVeloPlusProche();
        deplacements[nbEtapes - 1] = Deplacement(*etapes[nbEtapes - 1], *etapes[nbEtapes], "velo");
        nbEtapes++;
        // 3.
        etapes[nbEtapes] = &emplacement;
        deplacements[nbEtapes - 1] = Deplacement(*etapes[nbEtapes - 1], *etapes[nbEtapes], "marche");
        nbEtapes++;
        // 4. On met a jour la position du velo
        this->positionVelo = emplacement.getParkingVeloPlusProche();
    }
    else if (methode == "voiture" && nbEtapes + 3 <= maxEtapes)
    {
        // Même principe que pour le vélo
        etapes[nbEtapes] = this->positionVoiture;
        deplacements[nbEtapes - 1] = Deplacement(*etapes[nbEtapes - 1], *etapes[nbEtapes], "marche");
        nbEtapes++;
        // 2.
        etapes[nbEtapes] = emplacement.getParkingVoiturePlusProche();
        deplacements[nbEtapes - 1] = Deplacement(*etapes[nbEtapes - 1], *etapes[nbEtapes], "voiture");
        nbEtapes++;
        // 3.
        etapes[nbEtapes] = &emplacement;
        deplacements[nbEtapes - 1] = Deplacement(*etapes[nbEtapes - 1], *etapes[nbEtapes], "marche");
        nbEtapes++;
        // 4. On met a jour la position du velo
        this->positionVoiture = emplacement.getParkingVoiturePlusProche();
    }
    else if (nbEtapes + 1 <= maxEtapes)
    {
        etapes[nbEtapes] = &emplacement;
        deplacements[nbEtapes - 1] = Deplacement(*etapes[nbEtapes - 1], *etapes[nbEtapes], methode);
        nbEtapes++;
    }
    else
    {
        std::cout << "Erreur: Le trajet est déjà complet" << std::endl;
        exit(2);
    }
}

void Trajet::afficher()
{
    for (int i = 0; i < nbEtapes - 1; i++)
    {
        std::cout << "[" << i << "] " << deplacements[i] << std::endl;
    }
}

int Trajet::getNbEtapes()
{
    return nbEtapes;
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
    return *etapes[index];
}

Trajet Trajet::operator+(Emplacement emplacement)
{
    if (nbEtapes == 0)
    {
        this->ajouterEtape(emplacement);
    }
    else
    {
        this->ajouterEtape(emplacement, "marche");
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, Trajet &trajet)
{
    if (trajet.nbEtapes == 0)
    {
        os << "Trajet vide" << std::endl;
        return os;
    }
    else if (trajet.nbEtapes == 1)
    {
        os << "Départ : " << *trajet.etapes[0] << std::endl;
        return os;
    }
    else
    {
        for (int i = 0; i < trajet.nbEtapes - 1; i++)
        {
            os << "[" << i + 1 << "] " << trajet.deplacements[i] << std::endl;
        }
    }

    os << "durée totale : " << seconds_to_time(trajet.dureeTrajet()) << std::endl;

    os << "distance totale : " << meters_to_string(trajet.distanceTrajet()) << std::endl;
    return os;
}
