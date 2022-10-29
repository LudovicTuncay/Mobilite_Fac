# Mobilite_Fac

---
Contexte : Projet C++ du cours d'informatique en M2 IMA. 
Auteurs : [Ludovic Tuncay](https://github.com/LudovicTuncay) et [Auguste Verdier](https://github.com/LilBabines)
---

# Description du projet C++

## Thème : Mobilité à la fac

Nous aimerions travailler sur la mobilité sur le campus. Le but serait de calculer les temps de déplacements nécéssaires au sein du campus (un calcul d'itinéraire entre le domicile et la salle souhaitée est envisageable). 
Nous pourrions utiliser l'emplois du temps d'un étudiant, si possible directement importé depuis celcat pour planifier un trajet sur une journée entière. Nous souhaitons aussi utiliser l'API de Google Maps ou OpenStreetMap (par le biais de [OSRM](https://github.com/Project-OSRM/osrm-backend)) pour manipuler de vraies estimations de temps de trajet.

Plusieurs classes seraient nécéssaires, dont celles représentant les personnes (avec des classes qui vont en hériter suivant si on est étudiant, du personnel, enseignant... ), celles représentant les batiments, celles représentants les différents moyens de transports (avec une sous-classe pour chaque moyen de transport avec ses contraintes et ses avantages inclus dans les fonctions) et enfin des classes qui vont représenter les différents types de parkings.
