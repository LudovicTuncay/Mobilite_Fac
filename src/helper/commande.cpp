#include <helper/commande.h>
#include <iostream>

Commande::Commande(std::string commande)
{
    this->commande = commande;
}

std::string Commande::getCommande()
{
    return this->commande;
}

std::string Commande::getResultat()
{
    return this->resultat;
}

int Commande::getExitCode()
{
    return this->exitCode;
}

void Commande::executer()
{
    char buffer[128];
    std::string result = "";
    FILE *pipe = popen((this->commande + " 2>&1").c_str(), "r"); // 2>&1 permet de rediriger la sortie d'erreur vers stdio
    if (!pipe)
        throw std::runtime_error("popen() failed!");
    try
    {
        while (fgets(buffer, sizeof buffer, pipe) != NULL)
        {
            result += buffer;
        }
    }
    catch (...)
    {
        pclose(pipe);
        throw;
    }
    this->exitCode = pclose(pipe);
    this->resultat = result;
}

std::ostream &operator<<(std::ostream &os, const Commande &commande)
{
    os << " [*] commande : " << commande.commande << std::endl;
    os << " [*] resultat : " << commande.resultat; // Pas de << std::endl; car le resultat contient deja un retour a la ligne
    os << " [*] exitCode : " << commande.exitCode;
    if (commande.exitCode == 0)
    {
        os << " (OK)";
    }
    else
    {
        os << " (KO)";
    }
    os << std::endl;
    return os;
}
