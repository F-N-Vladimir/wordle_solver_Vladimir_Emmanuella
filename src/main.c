#include <stdio.h>
#include "wordle_solver.h"

int main() {
    WordList list;
    const char *filename = "ressources/bdd_wordle.txt";

    // Charger les mots depuis le fichier
    if (!load_words(filename, &list)) {
        printf("Erreur lors du chargement du fichier %s\n", filename);
        return 1;
    }

    printf("Solveur de Wordle démarré ! %d mots chargés.\n", list.count);

    // Lancer le menu interactif
    run_interactive_menu(&list);

    return 0;
}
