# wordle_solver_Vladimir_Emmanuella

Solveur de Wordle
Ce projet est un solveur pour le jeu Wordle, développé dans le cadre du TP de SE-L1. Il permet de filtrer une liste de mots à partir de critères spécifiques pour aider à trouver la solution d'un Wordle.
Structure du projet

bin/ : Contient les fichiers binaires compilés.
src/ : Contient les fichiers source C (main.c, wordle.c).
include/ : Contient les fichiers d'en-tête (wordle_solver.h).
ressources/ : Contient la base de données des mots (bdd_wordle.txt).

Prérequis

Un compilateur C (gcc recommandé).
Un système avec support des fichiers texte (Linux, macOS, ou Windows avec WSL).
Le fichier bdd_wordle.txt doit être présent dans le dossier ressources.

Installation

Clonez le dépôt :
git clone https://github.com/nom1/wordle_Vladimir_Emmanuellla.git
cd wordle_vladimir_Emanuella


Assurez-vous que le fichier bdd_wordle.txt est dans le dossier ressources.


Compilation
Pour compiler le programme, exécutez :
gcc -o bin/wordle_solver src/main.c src/wordle.c -I include

Exécution
Pour lancer le programme :
./bin/wordle_solver

Utilisation
Le programme propose un menu interactif avec les options suivantes :

Filtrer les mots contenant une lettre : Entrez une lettre pour ne garder que les mots contenant cette lettre.
Filtrer les mots excluant une lettre : Entrez une lettre pour exclure les mots contenant cette lettre.
Filtrer les mots contenant une sous-chaîne : Entrez une sous-chaîne pour ne garder que les mots contenant cette sous-chaîne.
Afficher la liste des mots : Affiche les mots restants après application des filtres.
Quitter : Termine le programme.

Exemple :

Si vous entrez le mot "adieu" dans Wordle et obtenez oxovx, vous pouvez :
Utiliser le filtre "contient la lettre 'a'" pour garder les mots avec 'a'.
Utiliser le filtre "exclut la lettre 'd'" pour éliminer les mots avec 'd'.



Auteurs

Vladimir (propriétaire)
Emanuella (collaborateur)

