typedef struct 
{
   void ** data;//tableaux d'element
   int taille;//nb d'element dans le tableaux 
   int tailleMax;//taille max du tableau
}tab_dynamic;


//Création initiale d’un tableau dynamique.
tab_dynamic * tab_initialize(size_t taillemax);

//Destruction du tableau pour libérer la mémoire allouée (mais pas les données référencées).
int tab_destroy(tab_dynamic * tab);

//Lecture à une position donnée dans le tableau.
void * read_tab(tab_dynamic * tab,int position);

//écriture à une position donnée dans le tableau.
int write_tab(tab_dynamic * tab,void * mot,int position);

//Ajout d’un nouvel élément à la fin du tableau.
int add_élément_tab(tab_dynamic * tab,void * mot);

//Insertion d’un élément à une position donnée avec décalage des éléments.
int add_élément_decal_tab(tab_dynamic * tab,void * mot,int position);

//Recherche de la position d’un élément via une fonction de comparaison dédiée.
int search_tab(tab_dynamic * tab,void * mot);