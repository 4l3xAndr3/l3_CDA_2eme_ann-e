#include "tab_dynamique.h";
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

tab_dynamic * tab_initialize(size_t taillemax){
    tab_dynamic *tab = malloc(sizeof(tab_dynamic));
    tab->data = malloc(taillemax * sizeof(void *));
    tab->taille = 0;
    tab->tailleMax = taillemax;
    return tab;
}


int tab_destroy(tab_dynamic * tab){
    free(tab);
}


void * read_tab(tab_dynamic * tab,int position){
    if(position>tab->tailleMax || position<0){
        return "";
    }
    void * element = tab->data[position];
    return element;
}


int write_tab(tab_dynamic * tab,void * element,int position){
    if(position>tab->tailleMax || position<0 || element == ""){
        return 0;
    }
    tab->data[position]=element;
    if(position>tab->taille){
        tab->taille = position;
    }
    return 1;
}


int add_élément_tab(tab_dynamic * tab,void * element){
    if(tab == "" || element == ""){
        return 0;
    }
    tab->data[++tab->taille]=element;
    return 1;
}

/*
int add_élément_decal_tab(tab_dynamic * tab,void * element,int position){
    if(position>tab->tailleMax || position<0 || element == ""){
        return 0;
    }
    void *elem=tab->data[position];
    for(int i = position;i<tab->tailleMax;i++){
        write_tab[tab,elem,i];
    }
    return 1;
}
*/

int search_tab(tab_dynamic * tab,void * mot){
    for(int i = 0;i<tab->taille;i++){
        if (!cmp(mot,tab->data[i]))
        {
            return i;
        }else{
            return -1;
        }
    }  
}