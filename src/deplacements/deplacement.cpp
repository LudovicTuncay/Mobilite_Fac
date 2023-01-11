#include "deplacements/deplacement.h"
#include "helper/commande.h"

#include <iostream>

Deplacement::Deplacement()
{
    this->emplacementDepart = Emplacement();
    this->emplacementArrivee = Emplacement();
    this->methode = "";
    this->APIdata = "";
}

Deplacement::Deplacement(Emplacement emplacementDepart, Emplacement emplacementArrivee, std::string methode)
{
    this->emplacementDepart = emplacementDepart;
    this->emplacementArrivee = emplacementArrivee;
    this->methode = methode;

    // On va maintenant créer une commande qui va appeler l'API et recueillir les données
    // la partie initialisation de la commande curl est la meme pour toutes les requetes

    std::string commande_root = "curl --silent \"http://routing.openstreetmap.de/routed-";
    // la partie responsable de la methode de deplacement
    std::string methode_deplacement;
    if (methode == "voiture")
        methode_deplacement = "car/";
    else if (methode == "pieton")
        methode_deplacement = "foot/";
    else if (methode == "velo")
        methode_deplacement = "bike/";
    else
    {
        std::cerr << "Methode de deplacement inconnue" << std::endl;
        exit(1);
    }
    // la partie responsable des coordonnees
    std::string coords = emplacementDepart.coordonnees_to_string() + ";" + emplacementArrivee.coordonnees_to_string();
    // la partie responsable des options
    std::string options = "?alternatives=false&overview=false";

    // on assemble tout
    std::string cmd_string = commande_root + methode_deplacement + coords + options;

    Commande commande(cmd_string);          // on cree la commande
    commande.executer();                    // on execute la commande
    this->APIdata = commande.getResultat(); // on convertit le resultat en double
}

double Deplacement::dureeDeplacement()
{
    std::string cmd_string = "echo '" + this->APIdata + "' | jq '.routes[0].duration'";

    Commande commande(cmd_string);            // on cree la commande
    commande.executer();                      // on execute la commande
    return std::stod(commande.getResultat()); // on convertit le resultat en double
}

double Deplacement::distanceDeplacement()
{
    std::string cmd_string = "echo '" + this->APIdata + "' | jq '.routes[0].distance'";

    Commande commande(cmd_string);            // on cree la commande
    commande.executer();                      // on execute la commande
    return std::stod(commande.getResultat()); // on convertit le resultat en double
}

std::ostream &operator<<(std::ostream &os, const Deplacement &deplacement)
{
    // Surcharge de l'opérateur << pour afficher les détails du déplacement
    os << deplacement.emplacementDepart << "--[" << deplacement.methode << "]--" << deplacement.emplacementArrivee << std::endl;
    return os;
}
