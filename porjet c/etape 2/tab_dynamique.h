#ifndef TAB_DYNAMIQUE_H
#define TAB_DYNAMIQUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition de la structure tab_dynamic
typedef struct {
   void **data;    // Tableau d'éléments
   int taille;     // Nombre d'éléments dans le tableau
   int tailleMax;  // Taille maximale du tableau
} tab_dynamic;

// Déclarations des fonctions
tab_dynamic * tab_initialize(size_t taillemax);
int tab_destroy(tab_dynamic * tab);
void * read_tab(tab_dynamic * tab,int position);
int write_tab(tab_dynamic * tab,void * mot,int position);
int add_element_tab(tab_dynamic * tab,void * mot);
int add_element_decal_tab(tab_dynamic * tab,void * mot,int position);
int search_tab(tab_dynamic * tab,void * mot);

#endif // TAB_DYNAMIQUE_H
