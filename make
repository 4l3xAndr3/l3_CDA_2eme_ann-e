#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "sequence.h"
#include "hash.h"

void test_sequence() {
    struct strhash_table *ht = strhash_create(10);

    // Initialisation
    sequence_initialize(ht);
    sequence_itStart();
    assert(sequence_itHasNext() == 0); // Rien à itérer dans un N-gramme vide

    // Ajouter des mots
    sequence_addWord("mot1", ht);
    sequence_progress();
    assert(strcmp(sequence_nextWord(), "mot1") == 0);

    sequence_addWord("mot2", ht);
    sequence_progress();
    assert(strcmp(sequence_nextWord(), "mot2") == 0);

    sequence_addWord("mot3", ht);
    sequence_progress();
    assert(strcmp(sequence_nextWord(), "mot3") == 0);

    // Vérifier le contenu du N-gramme
    sequence_itStart();
    assert(strcmp(sequence_itNext(), "mot1") == 0);
    assert(strcmp(sequence_itNext(), "mot2") == 0);
    assert(strcmp(sequence_itNext(), "mot3") == 0);
    assert(sequence_itHasNext() == 0); // Plus d'éléments à itérer

    // Avancer le N-gramme
    sequence_addWord("mot4", ht);
    sequence_progress();

    sequence_itStart();
    assert(strcmp(sequence_itNext(), "mot2") == 0); // "mot1" est éjecté
    assert(strcmp(sequence_itNext(), "mot3") == 0);
    assert(strcmp(sequence_itNext(), "mot4") == 0);

    // Vérification d'affichage
    printf("N-gramme actuel : ");
    sequence_print(); // Doit afficher "mot2 / mot3 / mot4"

    // Test de la fonction sequence_printInTab
    assert(strcmp(sequence_printInTab(), "mot2 / mot3 / mot4") == 0);

    // Ajout d'un mot déjà existant
    sequence_addWord("mot3", ht);
    sequence_progress();
    assert(strcmp(sequence_nextWord(), "mot3") == 0);

    // Libérer les ressources
    strhash_free(ht);

    printf("Tous les tests ont réussi !\n");
}

int main() {
    test_sequence();
    return 0;
}
