#ifndef WORDLE_SOLVER_H
#define WORDLE_SOLVER_H

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
} Word;

typedef struct {
    Word words[MAX_WORDS];
    int count;
} WordList;

// Fonctions pour charger les mots
int load_words(const char *filename, WordList *list);

// Fonctions pour les filtres
void filter_contains_letter(WordList *list, char letter);
void filter_excludes_letter(WordList *list, char letter);
void filter_contains_substring(WordList *list, const char *substring);
void display_words(const WordList *list);

// Fonction pour exécuter le menu interactif
void run_interactive_menu(WordList *list);

#endif
