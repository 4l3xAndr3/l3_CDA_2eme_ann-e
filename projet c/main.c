#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "sequence.h"
#include "hash.h"

int verifier(int condition, const char *message) {
    if (!condition) {
        printf("Échec du test : %s\n", message);
        return 0;
    }
    return 1;
}

int main() {
    struct strhash_table *ht;  // Création de la table de hachage pour les tests
    ht = strhash_create(3);
    sequence_initialize(ht);

    
    sequence_addWord("mot1", ht);
    printf("%d\n",ht->size);
    //sequence_itStart();            
    //verifier(strcmp(sequence_nextWord(), "mot1") == 0, "sequence_nextWord devrait retourner le dernier mot ajouté");



    return 0;
}
