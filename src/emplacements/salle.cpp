// Auteurs : Ludovic TUNCAY et Auguste VERDIER

#include <emplacements/salle.h>
#include <emplacements/batiment.h>

#include <iostream>

Salle::Salle() : Emplacement()
{
    this->batiment = nullptr;
    this->etage = -1;
}

Salle::Salle(std::string nom, Batiment *batiment, int etage) : Emplacement(nom, batiment->getCoordonees())
{
    this->batiment = batiment;
    this->etage = etage;
    this->batiment->ajouterSalle(*this); // Ajout de la salle au batiment
}

Batiment *Salle::getBatiment()
{
    return this->batiment;
}

int Salle::getEtage()
{
    return this->etage;
}

// Retourne la durée depuis l'entrée du batiment pour arriver à l'entree de
// la salle (en secondes) -> formule : dureeDepuisEntree = (etage+1)*60
double Salle::dureeDepuisEntree()
{
    return (this->etage + 1) * 60;
}
