# Mobilite_Fac

---

Contexte : Projet C++ du cours d'informatique en M2 IMA.
Auteurs : [Ludovic Tuncay](https://github.com/LudovicTuncay) et [Auguste Verdier](https://github.com/LilBabines)

---

# Description du projet C++

## Thème : Mobilité à la fac

Projet universitaire visant à manipuler le langage de programmation C++ ainsi que différents aspects de la programmation objet.

Objectif : Créer un programme permettant de gérer la mobilité des étudiants à la fac.

L'utilisateur peut choisir parmi une liste de différents bâtiments de l'université et créer itérativement un trajet au sein du campus. Le programme calcule une estimation du temps de trajet et de la distance à parcourir à chaque étape ainsi que sur l'ensemble du trajet. L'un de nos objectifs était d'obtenir de bonnes estimations, nous avons donc calculé ces distances et ces temps de trajet à l'aide d'une API mise à disposition par [OpenStreetMap](https://routing.openstreetmap.de/).

# Quick start

## Téléchargement

```bash
git clone https://github.com/LudovicTuncay/Mobilite_Fac.git
```

## Compilation et execution

1. Compilation

```bash
cd Mobilite_Fac
make all
```

2. Execution

```bash
./build/apps/program
```

L'utilisateur sera invité à choisir entre deux exemples. Le premier permet d'illustrer le polymorphisme compris dans notre programme, tandis que le second permet de créer un trajet personnalisé.

## Dependences :

Pour exectuer correctement l'exemple sur les trajets, le programme nécéssite le programme externe `jq` qui permet de parser les données JSON renvoyées par l'API. Pour l'installer, référez vous au instruction suivantes : [page installation de jq](https://stedolan.github.io/jq/download/).
