// Auteurs : Ludovic TUNCAY et Auguste VERDIER

#include <helper/commande.h>
#include <helper/coordonnees.h>

#include <emplacements/emplacement.h>
#include <emplacements/batiment.h>
#include <emplacements/salle.h>
#include <emplacements/parking.h>

#include <deplacements/trajet.h>

#include <Utilisateur/utilisateur.h>

#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>

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

#define PARKING_VELO 1
#define PARKING_VOITURE 0

void exemplePolymorphisme()
{
   Parking p_velo("Parking RU1 velo", 0, 0, PARKING_VELO);
   Parking p_voit("Parking RU1 voiture", 0, 0, PARKING_VOITURE);
   Batiment b("RU1", 0, 0, &p_velo, &p_voit);

   std::cout << "Si les 3 valeurs sont identiques, alors la fonction virtuelle correcte n'est pas appelée" << std::endl;

   Emplacement *e;
   e = &p_velo;
   std::cout << "Durée depuis l'entrée d'un parking à vélo      : " << e->dureeDepuisEntree() << std::endl;
   e = &p_voit;
   std::cout << "Durée depuis l'entrée d'un parking de voitures : " << e->dureeDepuisEntree() << std::endl;
   e = &b;
   std::cout << "Durée depuis l'entrée d'un batiment            : " << e->dureeDepuisEntree() << std::endl;
   // La bonne fonction virtuelle est appellée si les 3 valeurs sont différentes.
}

void gestionParcours()
{
   Parking p_velo_U1_U2("Parking velo entre U1 et U2", 43.56066294848289, 1.4704106358671574, PARKING_VELO);
   Parking p_voit_grand_RU2("Grand parking RU2 (Canal)", 43.56043216996784, 1.4726218021795812, PARKING_VOITURE);
   Batiment b_U1 = creerBatiment("Batiment U1", 43.5603056863409, 1.470114678781177, &p_velo_U1_U2, &p_voit_grand_RU2);

   Parking p_velo_U2("Parking velo entrée U2", 43.56167016293028, 1.4706031271464737, PARKING_VELO);
   Parking p_voit_petit_RU2("Petit parking RU2 (Canal)", 43.56141490914014, 1.4714878632231323, PARKING_VOITURE);
   Batiment b_U2 = creerBatiment("Batiment U2", 43.56146543485002, 1.4706671663951156, &p_velo_U2, &p_voit_petit_RU2);

   Parking p_velo_U3("Parking velo entrée U3", 43.562139630972965, 1.4701505934249586, PARKING_VELO);
   Parking p_voit_STAPS("Parking piste de course STAPS", 43.56254237146542, 1.47137217938225, PARKING_VOITURE);
   Batiment b_U3 = creerBatiment("Batiment U3", 43.56209310134519, 1.469841885779374, &p_velo_U3, &p_voit_STAPS);

   Parking p_velo_U3_U4_U6("Parking velo entre U3, U4 et U6", 43.562447329993915, 1.4691455751359808, PARKING_VELO);
   Parking p_voit_gymnases("Parking gymnases", 43.56376799479894, 1.469542286518094, PARKING_VOITURE);
   Batiment b_U4 = creerBatiment("Batiment U4", 43.56279937123464, 1.4691599487302571, &p_velo_U3_U4_U6, &p_voit_gymnases);

   Batiment b_U6 = creerBatiment("Batiment U6", 43.56275649191613, 1.4682717514403143, &p_velo_U3_U4_U6, &p_voit_gymnases);

   Parking p_velo_RU1("Parking RU1 velo", 43.56195725349943, 1.463567659315997, PARKING_VELO);
   Parking p_voit_RU1("Parking RU1 voiture", 43.56255426718022, 1.4638404832520777, PARKING_VOITURE);
   Batiment RU1("RU1", 43.56220872417138, 1.4632832684834005, &p_velo_RU1, &p_voit_RU1);

   Batiment RU2("RU2", 43.560936635472665, 1.471979265643556, &p_velo_U2, &p_voit_petit_RU2);

   std::string methodes[3] = {"voiture", "velo", "marche"};

   Emplacement emplacements[7] = {b_U1, b_U2, b_U3, b_U4, b_U6, RU1, RU2};

   Utilisateur u;

   u.creerTrajet(emplacements, 7, methodes, 3);
}

void selectExemple()
{
   std::string user_input;
   do
   {
      std::cout << "Choisissez un exemple : " << std::endl;
      std::cout << "1 - Exemple de polymorphisme" << std::endl;
      std::cout << "2 - Exemple de gestion de parcours" << std::endl;

      std::cin >> user_input;
   } while (user_input != "1" && user_input != "2");

   if (user_input == "1")
      exemplePolymorphisme();
   else if (user_input == "2")
      gestionParcours();
}

int main()
{
   selectExemple();
   return 1;
}
