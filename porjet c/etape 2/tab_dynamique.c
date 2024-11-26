#include "tab_dynamique.h"

tab_dynamic * tab_initialize(size_t taillemax) {
    if (taillemax <= 0) {
        return NULL;
    }
    tab_dynamic *tab = malloc(sizeof(tab_dynamic));
    if (!tab) {
        return NULL;
    }
    tab->data = malloc(taillemax * sizeof(void *));
    if (!tab->data) {
        free(tab);
        return NULL;
    }
    tab->taille = 0;
    tab->tailleMax = taillemax;
    return tab;
}

int tab_destroy(tab_dynamic * tab) {
    if (!tab) {
        return 0; 
    }
    free(tab->data);
    free(tab);
    return 1;
}

void * read_tab(tab_dynamic * tab, int position) {
    if (!tab || position < 0 || position >= tab->taille) {
        return NULL; 
    }
    return tab->data[position];
}

int write_tab(tab_dynamic * tab, void * mot, int position) {
    if (!tab || position < 0 || position >= tab->tailleMax || !mot) {
        return 0; 
    }
    if (position >= tab->taille) {
        tab->taille = position + 1; 
    }
    tab->data[position] = mot;
    return 1; 
}

int add_element_tab(tab_dynamic * tab, void * mot) {
    if (!tab || !mot) {
        return 0; 
    }
    if (tab->taille >= tab->tailleMax) {
        return 0; 
    }
    tab->data[tab->taille++] = mot; 
    return 1; 
}

int add_element_decal_tab(tab_dynamic * tab, void * mot, int position) {
    if (!tab || position < 0 || position > tab->taille || !mot) {
        return 0; 
    }
    if (tab->taille >= tab->tailleMax) {
        return 0;
    }
    for (int i = tab->taille; i > position; i--) {
        tab->data[i] = tab->data[i - 1];
    }
    tab->data[position] = mot; 
    tab->taille++;
    return 1; 
}

int search_tab(tab_dynamic * tab, void * mot) {
    if (!tab || !mot) {
        return -1; 
    }
    for (int i = 0; i < tab->taille; i++) {
        if (!strcmp((char *)tab->data[i], (char *)mot)) {
            return i;
        }
    }
    return -1; 
}
