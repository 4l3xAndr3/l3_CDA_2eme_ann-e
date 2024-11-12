#include "sequence.h"
#include <stdio.h>
#include <string.h>


// Variables pour gérer l'état de l'itérateur sur le N-gramme
static int iterator_pos = 0;

// Initialise le N-gramme avec des mots vides
void sequence_initialize(struct strhash_table *ht) {
    // Réinitialise la table de hachage pour supprimer toute donnée de N-gramme précédente
    strhash_reset(ht);
}

// Initialise l'itérateur pour qu'il commence au premier mot du N-gramme
void sequence_itStart(void) {
    iterator_pos = 0;
}

// Récupère le prochain mot dans le N-gramme et avance l'itérateur
const char *sequence_itNext(void) {
    if (iterator_pos < Lg_N_gramme) {
        // Obtient le mot à la position actuelle de l'itérateur
        const char *word = (const char *)list_get_data(ht->values[iterator_pos].first);
        iterator_pos++;
        return word;
    }
    return NULL;  // L'itérateur a atteint la fin du N-gramme
}

// Vérifie s'il reste des mots dans le N-gramme pour l'itérateur
int sequence_itHasNext(void) {
    return iterator_pos < Lg_N_gramme;
}

// Ajoute un nouveau mot au N-gramme en l’insérant dans la table de hachage s'il n'existe pas déjà
void sequence_addWord(const char *word, struct strhash_table *ht) {
    // Ajoute le mot à la table de hachage
    strhash_wordAdd(ht, word);
}

// Récupère le prochain mot qui sera ajouté au N-gramme
const char *sequence_nextWord(void) {
    return (const char *)list_get_data(ht->values[Lg_N_gramme - 1].first);
}

// Avance le N-gramme pour inclure un nouveau mot et supprimer le plus ancien
void sequence_progress(void) {
    // Supprime le mot le plus ancien (en première position)
    strhash_wordDel(ht, list_get_data(ht->values[0].first));
    
    // Décale les mots restants vers la gauche
    for (int i = 0; i < Lg_N_gramme - 1; i++) {
        ht->values[i].first->data = ht->values[i + 1].first->data;
    }
    
    // Ajoute le nouveau mot à la dernière position
    strhash_wordAdd(ht, new_word);
}

// Affiche le N-gramme actuel avec les mots séparés par '/'
void sequence_print(void) {
    for (int i = 0; i < Lg_N_gramme; i++) {
        printf("%s", (const char *)list_get_data(ht->values[i].first));
        if (i < Lg_N_gramme - 1) {
            printf("/");
        }
    }
    printf("\n");
}

// Retourne une chaîne de caractères représentant le N-gramme
char *sequence_printInTab(void) {
    static char buffer[256] = "";  // Espace pour stocker le N-gramme
    buffer[0] = '\0';  // Réinitialise le tampon

    for (int i = 0; i < Lg_N_gramme; i++) {
        strcat(buffer, (const char *)list_get_data(ht->values[i].first));
        if (i < Lg_N_gramme - 1) {
            strcat(buffer, "/");
        }
    }
    return buffer;
}
