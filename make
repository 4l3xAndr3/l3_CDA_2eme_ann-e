#include "sequence.h"
#include <stdio.h>
#include <string.h>




// Variables pour gérer l'état de l'itérateur sur le N-gramme
static int iterator_pos = 0;
// tabelau en circulaire n_gramme
static const char *n_gramme[Lg_N_gramme + 1];
static int pos_n_gramme;




// Initialise le N-gramme avec des mots vides
void sequence_initialize(struct strhash_table *ht) {
    for(int i=0 ; i< Lg_N_gramme;i++){
        n_gramme[i]="";
        pos_n_gramme=0;
    }
    if (ht == NULL) { // Create a new table only if ht is NULL
        ht = strhash_create(Lg_N_gramme);
    }
}




void sequence_itStart(void) {
    iterator_pos = pos_n_gramme-1;
}


const char *sequence_itNext(void) {
    if (iterator_pos < pos_n_gramme) {
        return n_gramme[iterator_pos++];
    }
    return "";
}


// Vérifie s'il reste des mots dans le N-gramme pour l'itérateur
int sequence_itHasNext(void) {
    return iterator_pos < pos_n_gramme;
}


// Ajoute un nouveau mot au N-gramme en l’insérant dans la table de hachage s'il n'existe pas déjà
void sequence_addWord(const char *word, struct strhash_table *ht) {
    // Ajoute le mot à la table de hachage + test si word n'existe pas
    if(!strcmp(strhash_wordAdd(ht, word),word)){
        //ajout word a n_gramme
        n_gramme[pos_n_gramme+1]=word;
    }
}


// Récupère le prochain mot qui sera ajouté au N-gramme
const char *sequence_nextWord(void) {
    return n_gramme[pos_n_gramme+1];
}


// Avance le N-gramme pour inclure un nouveau mot et supprimer le plus ancien
void sequence_progress(void) {
    n_gramme[pos_n_gramme-1]="";
    pos_n_gramme++;
}


// Affiche le N-gramme actuel avec les mots séparés par '/'
void sequence_print(void) {
    for (int i = 0; i < pos_n_gramme; i++) {
        printf("%s",n_gramme[i]);
        if (i < pos_n_gramme - 1) {
            printf("/");
        }
    }
    printf("\n");
}


char *sequence_printInTab(void) {
    static char buffer[256];
    buffer[0] = '\0';  


    for (int i = 0; i < Lg_N_gramme; i++) {
        if (strlen(n_gramme[i]) > 0) {
            strcat(buffer, n_gramme[i]);
            if (i < Lg_N_gramme - 1 && strlen(n_gramme[i + 1]) > 0) {
                strcat(buffer, " ");
            }
        }
    }


    return buffer;
}
