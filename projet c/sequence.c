#include "sequence.h"

#include <stdio.h>
#include <string.h>


static int iterator_pos = 0;
static struct strhash_table * N_gramme;




void sequence_initialize(struct strhash_table * ht){
    N_gramme = ht;
}


void sequence_itStart( void ){
    iterator_pos = 0;
}

const char * sequence_itNext( void ){
    if (iterator_pos < Lg_N_gramme) {
        s_node *iterator =N_gramme->values->first;
        for (int i = 0; i < iterator_pos; i++)
        {
           iterator = list_next(iterator);
        }
        const char *word = list_get_data(iterator);
        iterator_pos++;
        return word;
    }
    return NULL;
}

int sequence_itHasNext( void ){
    return iterator_pos < Lg_N_gramme;
}

void sequence_addWord( const char * wordi, struct strhash_table *ht ){
    printf("%s\n",strhash_wordAdd(ht, wordi));
    printf("t%d\n",ht->values->nbElements);
}


const char * sequence_nextWord(void) {
    if (N_gramme == NULL || N_gramme->values == NULL || N_gramme->values->first == NULL) {
        return NULL;
    }
    printf("LA");
    s_node *iterator = N_gramme->values->first;
    while (iterator != NULL) {
        if (list_get_data(iterator) != NULL) {
            return list_get_data(iterator);
        }
        iterator = list_next(iterator);
    }
    return NULL;
}

void sequence_progress( void ){
    N_gramme->values->first=N_gramme->values->first->next;
}

void sequence_print(void) {
    s_node *iterator = N_gramme->values->first;
    if (iterator == NULL) {
        return; // Return if list is empty
    }

    // Buffer for concatenated result, assuming max length of 1024
    char buffer[1024] = "";
    while (iterator != NULL) {
        // Append the data from the current node to buffer
        strcat(buffer, (const char *)iterator->data);

        // Move to the next node
        iterator = list_next(iterator);

        // Add separator if not at the end
        if (iterator != NULL) {
            strcat(buffer, " / ");
        }
    }

    // Print the result
    printf("%s\n", buffer);
}

char * sequence_printInTab( void ){
    strhash_display(N_gramme);
    return "0";
}