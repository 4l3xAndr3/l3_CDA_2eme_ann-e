#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tab_dynamique.h"

int main() {
    // Test de tab_initialize
    size_t tailleMax = 10;
    tab_dynamic *tab = tab_initialize(tailleMax);
    assert(tab != NULL); // Vérifie que le tableau a été créé
    assert(tab->taille == 0); // Vérifie que la taille est initialement 0
    assert(tab->tailleMax == tailleMax); // Vérifie la taille maximale

    // Test de write_tab et read_tab
    char * word1 = "test1";
    char * word2 = "test2";
    char * word3 = "test3";
    write_tab(tab, word1, 0);
    assert(!strcmp(tab->data[0], word1));
    assert(!strcmp(read_tab(tab, 0), word1));

    // Test de add_element_tab
    add_element_tab(tab, word2);
    assert(!strcmp(read_tab(tab, 1), word2));

    // Test de add_element_decal_tab et search_tab
    add_element_decal_tab(tab, word3, 0);
    assert(!strcmp(read_tab(tab, 0), word3));
    assert(search_tab(tab, word1) == 1);
    assert(search_tab(tab, word3) == 0);
    // Libération de la mémoire
    assert(tab_destroy(tab) == 1);

    printf("Tous les tests ont réussi !\n");
    return 0;
}
