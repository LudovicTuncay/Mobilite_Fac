#include <Utilisateur/utilisateur.h>

Utilisateur::Utilisateur()
{
    trajet = Trajet();
}

double Utilisateur::getDistanceTotale()
{
    return trajet.distanceTrajet();
}

double Utilisateur::getDureeTotale()
{
    return trajet.dureeTrajet();
}

Emplacement select_emplacement(Emplacement *emplacements, int nb_emplacements)
{
    int choix;
    std::cout << "Choisissez un emplacement : " << std::endl;
    for (int i = 0; i < nb_emplacements; i++)
    {
        std::cout << "[" << i << "] " << emplacements[i] << std::endl;
    }
    std::cout << "-> ";
    std::cin >> choix;
    std::cout << std::endl;
    if (choix < 0 || choix >= nb_emplacements)
    {
        std::cout << "Choix invalide" << std::endl
                  << std::endl;
        return select_emplacement(emplacements, nb_emplacements);
    }
    return emplacements[choix];
}

std::string select_methode(std::string *methodes, int nb_methodes)
{
    int choix;
    std::cout << "Choisissez une méthode de déplacement : " << std::endl;
    for (int i = 0; i < nb_methodes; i++)
    {
        std::cout << "[" << i << "] " << methodes[i] << std::endl;
    }
    std::cout << "-> ";
    std::cin >> choix;
    std::cout << std::endl;
    if (choix < 0 || choix >= nb_methodes)
    {
        std::cout << "Choix invalide" << std::endl
                  << std::endl;
        return select_methode(methodes, nb_methodes);
    }
    return methodes[choix];
}

// Création d'un trajet à partir de l'entrée standard (clavier)
// L'utilisateur va entrer les étapes du trajet (salle)
void Utilisateur::creerTrajet(Emplacement *emplacements, int nb_emplacements, std::string *methodes, int nb_methodes)
{
    int choix;
    std::cout << trajet << std::endl;
    std::cout << "1. Ajouter une étape" << std::endl;
    std::cout << "2. Afficher le trajet" << std::endl;
    std::cout << "3. Quitter" << std::endl;
    std::cout << "-> ";
    std::cin >> choix;
    std::cout << std::endl;
    switch (choix)
    {
    case 1:
        if (this->trajet.getNbEtapes() == 0)
            this->trajet.ajouterEtape(select_emplacement(emplacements, nb_emplacements));
        else
            this->trajet.ajouterEtape(select_emplacement(emplacements, nb_emplacements), select_methode(methodes, nb_methodes));
        creerTrajet(emplacements, nb_emplacements, methodes, nb_methodes);
        break;
    case 2:
        // std::cout << this->trajet << std::endl; // Deja affiché par creerTrajet
        creerTrajet(emplacements, nb_emplacements, methodes, nb_methodes);
        break;
    case 3:
        break;
    default:
        std::cout << "Choix invalide" << std::endl
                  << std::endl;
        creerTrajet(emplacements, nb_emplacements, methodes, nb_methodes);
        break;
    }
}

std::ostream &operator<<(std::ostream &os, Utilisateur &utilisateur)
{
    os << "trajet: " << std::endl
       << utilisateur.trajet;
    return os;
}
