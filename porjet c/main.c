#include <stdio.h>
#include <string.h>
#include "sequence.h"
#include "hash.h"

// Fonction d'aide pour afficher un message et vérifier une condition
void verifier(int condition, const char *message) {
    if (!condition) {
        printf("Échec du test : %s\n", message);
    } else {
        printf("Test réussi : %s\n", message);
    }
}

int main() {
    struct strhash_table *ht = strhash_create(10);  // Création de la table de hachage pour les tests
    if (ht == NULL) {
        printf("Échec de la création de la table de hachage\n");
        return 1;
    }

    // Test de sequence_initialize
    sequence_initialize(ht);
    struct strhash_stat hstat;
    strhash_analyse(ht, &hstat);
    verifier(hstat.nbWord == 0, "sequence_initialize devrait réinitialiser la table de hachage");

    // Test de sequence_addWord et sequence_nextWord
    sequence_addWord("mot1", ht);
    verifier(strcmp(sequence_nextWord(ht), "mot1") == 0, "sequence_nextWord devrait retourner le dernier mot ajouté");

    // Ajout de mots supplémentaires pour remplir le N-gramme
    sequence_addWord("mot2", ht);
    sequence_addWord("mot3", ht);
    verifier(strcmp(sequence_nextWord(ht), "mot3") == 0, "sequence_nextWord devrait retourner le dernier mot ajouté (mot3)");

    // Test de sequence_itStart et sequence_itNext
    sequence_itStart();
    verifier(strcmp(sequence_itNext(ht), "mot1") == 0, "sequence_itNext devrait retourner mot1");
    verifier(strcmp(sequence_itNext(ht), "mot2") == 0, "sequence_itNext devrait retourner mot2");
    verifier(strcmp(sequence_itNext(ht), "mot3") == 0, "sequence_itNext devrait retourner mot3");
    verifier(sequence_itNext(ht) == NULL, "sequence_itNext devrait retourner NULL après avoir atteint la fin");

    // Test de sequence_progress
    sequence_progress(ht, "nouveau_mot");
    verifier(strcmp(sequence_nextWord(ht), "nouveau_mot") == 0, "sequence_progress devrait ajouter 'nouveau_mot' à la fin du N-gramme");
    verifier(strcmp(sequence_itNext(ht), "mot2") == 0, "sequence_progress devrait décaler le N-gramme, donc le premier mot est maintenant 'mot2'");

    // Test de sequence_print
    printf("Sortie attendue du N-gramme : mot2/mot3/nouveau_mot\nActuel : ");
    sequence_print(ht);

    // Test de sequence_printInTab
    const char *ngram_str = sequence_printInTab(ht);
    verifier(strcmp(ngram_str, "mot2/mot3/nouveau_mot") == 0, "sequence_printInTab devrait retourner 'mot2/mot3/nouveau_mot'");

    // Libération de la mémoire
    strhash_free(ht);
    printf("Tous les tests sont terminés.\n");
    return 0;
}
