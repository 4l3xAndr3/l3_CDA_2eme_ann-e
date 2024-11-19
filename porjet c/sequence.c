#include "sequence.h"
#include <stdio.h>
#include <string.h>




// Variables pour gérer l'état de l'itérateur sur le N-gramme
static int iterator_pos = 0;

// tabelau en circulaire n_gramme
static const char *n_gramme[Lg_N_gramme + 1];
static int pos_n_gramme;


void sequence_initialize(struct strhash_table *ht) {
    for(int i=0 ; i< Lg_N_gramme;i++){
        n_gramme[i]="";
        pos_n_gramme=0;
    }
    if (ht == NULL) { 
        ht = strhash_create(Lg_N_gramme);
    }
}

void sequence_itStart(void) {
    iterator_pos = (pos_n_gramme+1)%(Lg_N_gramme+1);
}

const char *sequence_itNext(void) {
    
    if (iterator_pos < Lg_N_gramme) {
        return n_gramme[iterator_pos++];
    }
    return "";
}

int sequence_itHasNext(void) {
    return iterator_pos < Lg_N_gramme;
}

void sequence_addWord(const char *word, struct strhash_table *ht) {
    // Ajoute le mot à la table de hachage + test si word n'existe pas
    if(!strcmp(strhash_wordAdd(ht, word),word)){
        //ajout word a n_gramme
        n_gramme[(pos_n_gramme+1)%(Lg_N_gramme+1)]=word;
    }
}

const char *sequence_nextWord(void) {
    return n_gramme[(pos_n_gramme+1)%(Lg_N_gramme+1)];
}


void sequence_progress(void) {
    //n_gramme[pos_n_gramme]="";
    pos_n_gramme=(pos_n_gramme+1)%(Lg_N_gramme+1);

    
}

void sequence_print(void) {
    
    for (int i = 0; i < Lg_N_gramme; i++) {
        printf("%s",n_gramme[i]);
        if (i < Lg_N_gramme && n_gramme[i+1]!=""&& n_gramme[i]!="") {
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