#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "wordle_solver.h"

int load_words(const char *filename, WordList *list) {
    FILE *file = fopen(filename, "r");
    if (!file) return 0;

    list->count = 0;
    while (list->count < MAX_WORDS && fscanf(file, "%s", list->words[list->count].word) == 1) {
        list->count++;
    }
    fclose(file);
    return 1;
}

void filter_contains_letter(WordList *list, char letter) {
    letter = tolower(letter);
    int new_count = 0;
    for (int i = 0; i < list->count; i++) {
        for (int j = 0; list->words[i].word[j]; j++) {
            if (tolower(list->words[i].word[j]) == letter) {
                list->words[new_count] = list->words[i];
                new_count++;
                break;
            }
        }
    }
    list->count = new_count;
}

void filter_excludes_letter(WordList *list, char letter) {
    letter = tolower(letter);
    int new_count = 0;
    for (int i = 0; i < list->count; i++) {
        int has_letter = 0;
        for (int j = 0; list->words[i].word[j]; j++) {
            if (tolower(list->words[i].word[j]) == letter) {
                has_letter = 1;
                break;
            }
        }
        if (!has_letter) {
            list->words[new_count] = list->words[i];
            new_count++;
        }
    }
    list->count = new_count;
}

void filter_contains_substring(WordList *list, const char *substring) {
    int new_count = 0;
    for (int i = 0; i < list->count; i++) {
        if (strstr(list->words[i].word, substring)) {
            list->words[new_count] = list->words[i];
            new_count++;
        }
    }
    list->count = new_count;
}

void display_words(const WordList *list) {
    printf("Mots restants (%d) :\n", list->count);
    for (int i = 0; i < list->count; i++) {
        printf("%s\n", list->words[i].word);
    }
}

void run_interactive_menu(WordList *list) {
    int choice;
    char input[100];
    char letter;

    while (1) {
        printf("\nMenu des filtres :\n");
        printf("1. Filtrer les mots contenant une lettre\n");
        printf("2. Filtrer les mots excluant une lettre\n");
        printf("3. Filtrer les mots contenant une sous-chaîne\n");
        printf("4. Afficher la liste des mots\n");
        printf("5. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choice);
        getchar(); // Nettoyer le buffer

        switch (choice) {
            case 1:
                printf("Entrez une lettre : ");
                scanf("%c", &letter);
                filter_contains_letter(list, letter);
                break;
            case 2:
                printf("Entrez une lettre à exclure : ");
                scanf("%c", &letter);
                filter_excludes_letter(list, letter);
                break;
            case 3:
                printf("Entrez une sous-chaîne : ");
                scanf("%s", input);
                filter_contains_substring(list, input);
                break;
            case 4:
                display_words(list);
                break;
            case 5:
                printf("Au revoir !\n");
                return;
            default:
                printf("Choix invalide.\n");
        }
    }
}
