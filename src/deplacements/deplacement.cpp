#include "deplacements/deplacement.h"
#include "helper/commande.h"
#include "helper/fonctions.h"

#include <iostream>

Deplacement::Deplacement()
{
    this->emplacementDepart = Emplacement();
    this->emplacementArrivee = Emplacement();
    this->methode = "";
    this->APIdata = "";
}

// double deplacement_marche(Emplacement emplacementDepart, Emplacement emplacementArrivee, int index)
// {
//     std::string commande_root = "curl --silent \"http://routing.openstreetmap.de/routed-foot/route/v1/driving/";
//     std::string coords = emplacementDepart.coordonnees_to_string() + ";" + emplacementArrivee.coordonnees_to_string();
//     std::string options = "?alternatives=false&overview=false\"";
//     std::string cmd_string = commande_root + coords + options;
//     Commande commande(cmd_string);                       // on cree la commande
//     commande.executer();                                 // on execute la commande
//     std::string APIdata[index] = commande.getResultat(); // on recupere le resultat de l'API
// }

Deplacement::Deplacement(Emplacement emplacementDepart, Emplacement emplacementArrivee, std::string methode)
{
    this->methode = methode;
    this->emplacementDepart = emplacementDepart;
    this->emplacementArrivee = emplacementArrivee;

    // On va maintenant créer une commande qui va appeler l'API et recueillir les données
    // la partie initialisation de la commande curl est la meme pour toutes les requetes

    std::string commande_root = "curl --silent \"http://routing.openstreetmap.de/routed-";
    // la partie responsable de la methode de deplacement
    std::string methode_deplacement;
    if (methode == "voiture")
        methode_deplacement = "car/route/v1/driving/";
    else if (methode == "marche")
        methode_deplacement = "foot/route/v1/driving/";
    else if (methode == "velo")
        methode_deplacement = "bike/route/v1/driving/";
    else
    {
        std::cerr << "Methode de deplacement inconnue" << std::endl;
        exit(1);
    }

    // la partie responsable des coordonnees
    std::string coords = emplacementDepart.coordonnees_to_string() + ";" + emplacementArrivee.coordonnees_to_string();
    // la partie responsable des options
    std::string options = "?alternatives=false&overview=false\"";

    // on assemble tout
    std::string cmd_string = commande_root + methode_deplacement + coords + options;

    Commande commande(cmd_string);          // on cree la commande
    commande.executer();                    // on execute la commande
    this->APIdata = commande.getResultat(); // on recupere le resultat de l'API
}

double Deplacement::dureeDeplacement()
{

    std::string cmd_string = "echo '" + this->APIdata + "' | jq '.routes[0].duration'";

    Commande commande(cmd_string); // on cree la commande
    commande.executer();           // on execute la commande
    Emplacement *emplacementDepart;
    emplacementDepart = = &(this->emplacementDepart);
    Emplacement *emplacementArrivee;
    emplacementArrivee = &(this->emplacementArrivee);
    double durees_depuis_entrees = emplacementDepart->dureeDepuisEntree() + emplacementArrivee->dureeDepuisEntree();
    return std::stod(commande.getResultat()) + durees_depuis_entrees; // on convertit le resultat en double
}

double Deplacement::distanceDeplacement()
{
    std::string cmd_string = "echo '" + this->APIdata + "' | jq '.routes[0].distance'";

    Commande commande(cmd_string);            // on cree la commande
    commande.executer();                      // on execute la commande
    return std::stod(commande.getResultat()); // on convertit le resultat en double
}

std::ostream &operator<<(std::ostream &os, Deplacement &deplacement)
{
    // Surcharge de l'opérateur << pour afficher les détails du déplacement
    os << deplacement.emplacementDepart << "--[" << deplacement.methode << "]->" << deplacement.emplacementArrivee << "\t(" << meters_to_string(deplacement.distanceDeplacement()) << ", " << seconds_to_time(deplacement.dureeDeplacement()) << ")";
    return os;
}
