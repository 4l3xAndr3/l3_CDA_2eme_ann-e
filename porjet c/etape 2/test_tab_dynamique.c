#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tab_dynamique.h";

size_t taillemax = 5;
tab_dynamic *tab = tab_initialize(taillemax);
assert(tab != NULL);
assert(tab->size==0)
