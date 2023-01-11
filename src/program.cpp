#include <helper/commande.h>
#include <helper/coordonnees.h>

#include <emplacements/emplacement.h>
#include <emplacements/batiment.h>
#include <emplacements/salle.h>
#include <emplacements/parking.h>

#include <deplacements/trajet.h>

#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>

// Batiment creerBatiment(std::string nom, double latitude, double longitude, Parking &parkingVelo, Parking &parkingVoiture)
// {
//    Batiment b(nom, latitude, longitude, parkingVelo, parkingVoiture);

//    // Batiment b(nom, latitude, longitude, parkingVelo, parkingVoiture);
//    // // Ajout de salles :
//    // for (int i = 0; i < 3; i++)
//    // {
//    //    Salle s(std::to_string(i) + "01", &b, i);
//    //    b.ajouterSalle(s);
//    // }
//    return b;
// }

Batiment creerBatiment(std::string nom, double latitude, double longitude, Parking *parkingVelo, Parking *parkingVoiture)
{
   Batiment b(nom, latitude, longitude, parkingVelo, parkingVoiture);
   // Ajout de salles :
   for (int i = 0; i < 3; i++)
   {
      Salle s(std::to_string(i) + "01", &b, i);
      // Lorsqu'on créé la salle, le batiment se voit automatiquement attribué
      // la salle
   }
   return b;
}

int main()
{
   // TODO : remplacer les coordonnées par les vraies coordonnées !
   Parking p1velo("Parking 1 velo", 0, 0);
   Parking p2velo("Parking 2 velo", 0, 0);
   Parking p1voiture("Parking 1 voiture", 0, 0);
   Parking p2voiture("Parking 2 voiture", 0, 0);

   Batiment b_U1 = creerBatiment("Batiment U1", 0, 0, &p1velo, &p2voiture);
   Batiment b_U2 = creerBatiment("Batiment U2", 0, 0, &p2velo, &p2voiture);
   Batiment b_U3 = creerBatiment("Batiment U3", 0, 0, &p1velo, &p1voiture);

   // Affichage des informations des batiments
   b_U1.afficher();
   b_U2.afficher();
   b_U3.afficher();

   return 1;
}
