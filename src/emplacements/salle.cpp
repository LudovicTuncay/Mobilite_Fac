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

std::ostream &operator<<(std::ostream &os, const Salle &salle)
{
    os << "--> Salle      : " << salle.nom << std::endl
       << "--> Coordonees : " << salle.coordonees << std::endl
       << "--> Batiment   : " << salle.batiment->getNom() << std::endl
       << "--> Etage      : " << salle.etage << std::endl;
    return os;
}
