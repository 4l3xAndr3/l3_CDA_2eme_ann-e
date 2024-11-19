#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "sequence.h"
#include "hash.h"

int main() {
    struct strhash_table *ht=strhash_create(Lg_N_gramme);

    // Test de l'initialisation du N-gramme et des test
    sequence_initialize(ht);
    sequence_itStart();
    const char *word1 = "test";
    const char *word2 = "test2";


    // Test sequence_addWord + sequence_nextWord
    sequence_addWord(word1, ht);
    assert(!strcmp(sequence_nextWord(),word1));

    // test sequence_progress
    sequence_progress();
    assert(strcmp(sequence_nextWord(),word1));

    // Test avec deuxieme mot sequence_addWord + sequence_nextWord
    sequence_addWord(word2, ht);
    assert(!strcmp(sequence_nextWord(),word2));
    sequence_progress();
    sequence_addWord("test3", ht);
    assert(!strcmp(sequence_nextWord(),"test3"));
    sequence_progress();
    sequence_addWord("test4", ht);
    assert(!strcmp(sequence_nextWord(),"test4"));
    // Vérification de l'itérateur
    sequence_itStart();
    assert(sequence_itHasNext());
    printf(sequence_itNext());
    //assert(strcmp(sequence_itNext(), "test2") == 0);

    // Affichage du N-gramme
    printf("Affichage du N-gramme actuel:\n");
    sequence_print();
    
    // Libération des ressources
    strhash_free(ht);
    printf("Tous les tests ont été exécutés avec succès.\n");

    return 0;
}
