#pragma once

#include <iostream>
#include <emplacements/salle.h>
#include <emplacements/emplacement.h>

class Salle; // Déclaration anticipée de la classe Salle pour éviter les erreurs de compilation liées aux dépendances circulaires

// Classe qui hérite de Emplacement
class Batiment : public Emplacement
{
protected:
    int maxSalles;
    Salle *salles;
    int nbSalles;

public:
    Batiment();
    Batiment(std::string nom, CoordoneesGPS coordonees);
    Batiment(std::string nom, double latitude, double longitude);
    void ajouterSalle(Salle &s);
    void afficherSalles();
    int getNbSalles();
    Salle *getSalles();

    // Operator overloading
    friend std::ostream &operator<<(std::ostream &os, const Batiment &batiment);
};
