// Auteurs : Ludovic TUNCAY et Auguste VERDIER

#pragma once

#include <iostream>
#include <emplacements/emplacement.h>
#include <emplacements/batiment.h>

// Déclaration anticipée des classes pour éviter les erreurs de compilation liées aux dépendances circulaires
class Batiment;
// class Emplacement;

class Salle : public Emplacement
{
protected:
    Batiment *batiment;
    int etage;

public:
    Salle();
    Salle(std::string nom, Batiment *batiment, int etage);
    Batiment *getBatiment();
    int getEtage();

    // Retourne la durée depuis l'entrée du batiment pour arriver à l'entree de
    // la salle (en secondes) -> formule : dureeDepuisEntree = (etage+1)*60
    double dureeDepuisEntree();
};
