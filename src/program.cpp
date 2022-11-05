#include <helper/commande.h>
#include <emplacements/emplacement.h>
#include <helper/coordonnees.h>

#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>

int main()
{

   Commande c1("echo \"Hello World ! this is a test...\"");
   c1.executer();
   std::cout << c1;

   Commande c2("sjqdqkjsdbqslkjd"); // Commande qui n'existe pas (pour tester le code d'erreur)
   c2.executer();
   std::cout << c2;

   std::cout << std::endl;

   CoordoneesGPS coords(1.0, 2.0);
   std::cout << "Coordonnées : " << coords << std::endl
             << std::endl;

   Emplacement e1("Paris", coords);
   std::cout << e1 << std::endl
             << std::endl;

   Emplacement e2("test", 1.1, 2.1);
   std::cout << e2;

   return 0;
}
