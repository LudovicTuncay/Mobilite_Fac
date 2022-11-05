#pragma once

#include <string>

class Commande
{
    std::string commande;
    std::string resultat;
    int exitCode;

public:
    Commande(std::string commande);
    std::string getCommande();
    std::string getResultat();
    int getExitCode();
    void executer();

    // Operator overloading
    friend std::ostream &operator<<(std::ostream &os, const Commande &commande);
};
