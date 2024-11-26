#include "arbre_prediction.h"

Arbre * create_arbre(){
    Arbre *arbre = (Arbre *)malloc(sizeof(Arbre));
    arbre->word ="";
    arbre->occurrences = 0;
    arbre->children = NULL;
}

Arbre *search_arbre(Arbre *arbre, struct strhash_table *hash_table){
    Arbre *current = arbre;
    sequence_itStart;
    while (sequence_itHasNext()) {
        const char *mot = sequence_itNext();
        int trouve = 0 ;
        //boucle pour trouver le mot rechercher dans la branche de l'arbre
        for (int i = 0; i < current->children->taille; i++) 
        {
            Arbre * children =read_tab(current->children,i);
            if (!strcmp(children->word,mot))
            {
                current = children;
                trouve = 1;
                break;
            }
        }

        if (!trouve)
        {
            Arbre *new_arbre= create_arbre(mot);
            add_element_tab(current->children,new_arbre);
            current = new_arbre;
        }
    }
    return current;
}

void add_arbre(Arbre *parent, const char *word){
    for (int i = 0; i < parent->children->taille; i++) 
    {
        Arbre * children =read_tab(parent->children,i);
        if (!strcmp(parent->word,word))
        {
            children->occurrences++;
            return;
        }
    }
    Arbre *new_arbre= create_arbre(word);
    new_arbre->occurrences=1;
    add_element_tab(parent->children,new_arbre);
}

const char *max_arbre(Arbre *parent){
    const char *max_word = NULL;
    int max_occurrences = 0;

    for (int i = 0; i < parent->children->taille; i++)
    {
        Arbre * children =read_tab(parent->children,i);
        if (children->occurrences>max_occurrences)
        {
            max_occurrences=children->occurrences;
            max_word=children->word;
        }
    }
    return max_word;
}