#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "list.h"
#include "sequence.h"
#include "tab_dynamique.h"


// Structure d'un nœud d'arbre de prédiction
typedef struct Arbre {
    char *word; // Mot
    int occurrences; // Nombre d'occurrences
    tab_dynamic *children; // Tableau dynamique des fils
} Arbre;

Arbre * create_arbre();
Arbre *search_arbre(Arbre *arbre, struct strhash_table *hash_table);
void add_arbre(Arbre *parent, const char *word);
const char *max_arbre(Arbre *arbre);