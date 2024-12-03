#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sequence.h"
#include "hash.h"

// Variables globales statiques
static char *circularBuffer[Lg_N_gramme];
static int currentIndex = 0;
static struct strhash_table *hashTable;
static int iteratorIndex = 0;

// Initialiser le N-gramme avec des mots vides
void sequence_initialize(struct strhash_table *ht) {
    hashTable = ht;
    for (int i = 0; i < Lg_N_gramme; i++) {
        circularBuffer[i] = NULL;
    }
    currentIndex = 0;
}

// Initialiser l'itérateur sur le premier mot du N-gramme courant
void sequence_itStart(void) {
    iteratorIndex = 0;
}

// Retourner le mot correspondant à la position de l'itérateur et avancer
const char *sequence_itNext(void) {
    if (iteratorIndex >= Lg_N_gramme) {
        return NULL;
    }
    const char *word = circularBuffer[(currentIndex + iteratorIndex) % Lg_N_gramme];
    iteratorIndex++;
    return word;
}

// Tester si l'itérateur est à la fin du N-gramme
int sequence_itHasNext(void) {
    return iteratorIndex < Lg_N_gramme;
}

// Ajouter un nouveau mot de fin du prochain N-gramme
void sequence_addWord(const char *word, struct strhash_table *ht) {
    char *addedWord = strhash_wordAdd(ht, word);
    circularBuffer[(currentIndex + Lg_N_gramme) % Lg_N_gramme] = addedWord;
}

// Retourner le prochain mot qui entrera dans le N-gramme
const char *sequence_nextWord(void) {
    return circularBuffer[(currentIndex + Lg_N_gramme) % Lg_N_gramme];
}

// Avancer le N-gramme pour intégrer le nouveau mot
void sequence_progress(void) {
    currentIndex = (currentIndex + 1) % Lg_N_gramme;
}

// Afficher le N-gramme courant
void sequence_print(void) {
    for (int i = 0; i < Lg_N_gramme; i++) {
        if (circularBuffer[(currentIndex + i) % Lg_N_gramme] != NULL) {
            printf("%s", circularBuffer[(currentIndex + i) % Lg_N_gramme]);
        } else {
            printf("<vide>");
        }
        if (i < Lg_N_gramme - 1) {
            printf(" / ");
        }
    }
    printf("\n");
}

// Séquence sous forme de chaîne pour le test
char *sequence_printInTab(void) {
    static char buffer[256];
    buffer[0] = '\0';
    for (int i = 0; i < Lg_N_gramme; i++) {
        if (circularBuffer[(currentIndex + i) % Lg_N_gramme] != NULL) {
            strcat(buffer, circularBuffer[(currentIndex + i) % Lg_N_gramme]);
        } else {
            strcat(buffer, "<vide>");
        }
        if (i < Lg_N_gramme - 1) {
            strcat(buffer, " / ");
        }
    }
    return buffer;
}
