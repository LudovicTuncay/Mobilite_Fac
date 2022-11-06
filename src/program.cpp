#include <helper/commande.h>
#include <helper/coordonnees.h>
#include <emplacements/emplacement.h>
#include <emplacements/batiment.h>
#include <emplacements/salle.h>

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

   Batiment b1("U4", 1.2, 2.2);

   Salle s1("212", &b1, 2);
   std::cout << s1 << std::endl
             << std::endl;

   Salle s2("213", &b1, 2);
   std::cout << s1 << std::endl
             << std::endl;

   std::cout << "————————————————————————————————————————————————" << std::endl
             << std::endl
             << std::endl
             << std::endl;

   b1.afficherSalles();

   std::cout << "————————————————————————————————————————————————" << std::endl
             << std::endl
             << std::endl
             << std::endl;

   std::cout << b1 << std::endl
             << std::endl;
   return 0;
}
