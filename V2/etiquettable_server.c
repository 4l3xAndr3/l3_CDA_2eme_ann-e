#include "etiquettable.h"
struct compte list_compte[50];
int nb_compte = 0;

struct fruit_legume list_fruit_legume[50];
int nb_fruit_legume = 0;

struct poisson list_poisson[50];
int nb_poisson = 0;

struct recette list_recette[50];
int nb_recette = 0;

struct compte compte_connect;

int *inscription_1_svc(compte *argp, struct svc_req *rqstp)
{
    list_compte[nb_compte++] = *argp;
    return 1;
}

int *connexion_1_svc(connection *argp, struct svc_req *rqstp)
{
    for (size_t i = 0; i < nb_compte; i++)
    {
        if (strcmp(argp->email, list_compte[i].email) == 0 && strcmp(argp->mdp, list_compte[i].mdp) == 0)
        {
            compte_connect = list_compte[i];
            return 0;
        }
    }
    return 1;
}

fruit_legume *fiche_fruit_legume_1_svc(char *argp, struct svc_req *rqstp)
{
    for (size_t i = 0; i < nb_fruit_legume; i++)
    {
        if (strcmp(argp, list_fruit_legume[i].nom) == 0)
        {
            return &list_fruit_legume[i];
        }
    }
    return NULL;
}

poisson *fiche_poisson_1_svc(char *argp, struct svc_req *rqstp)
{
    for (size_t i = 0; i < nb_poisson; i++)
    {
        if (strcmp(argp, list_poisson[i].nom) == 0)
        {
            return &list_poisson[i];
        }
    }
    return NULL;
}

recette *fiche_recette_1_svc(char *argp, struct svc_req *rqstp)
{
    for (size_t i = 0; i < nb_recette; i++)  // Changed condition to nb_recette instead of nb_fruit_legume
    {
        if (strcmp(argp, list_recette[i].nom) == 0)  // Corrected the name comparison to the recipe list
        {
            return &list_recette[i];
        }
    }
    return NULL;
}

compte *fiche_user_1_svc(char *argp, struct svc_req *rqstp)
{
    for (size_t i = 0; i < nb_compte; i++)
    {
        if (strcmp(argp, list_compte[i].email) == 0)  // Corrected the comparison for email
        {
            return &list_compte[i];
        }
    }
    return NULL;  // Changed return value to NULL (instead of 1, which is incorrect)
}

int *deconnexion_1_svc(void *argp, struct svc_req *rqstp)
{
    struct compte compte_NULL = {0};  // Initialize structure to zero
    compte_connect = compte_NULL;
    return 1;
}

int *ini_1_svc(init *argp, struct svc_req *rqstp)
{
printf("test 2");
	struct compte compte2_ini;
    compte2_ini.photo = NULL;
    compte2_ini.email = argp->email;
    compte2_ini.mdp = "1234";
    compte2_ini.prenom = "toto";
    compte2_ini.nom = "tutu";
    compte2_ini.date_naissance = "15/04/2024";
    compte2_ini.genre = "M";
    compte2_ini.condition_general = 1;
    compte2_ini.newsletter = 0;
    compte2_ini.location = NULL;
    compte2_ini.profil_allimentaire = NULL;
    
    struct mois mois_annee;

    // Initialisation des mois avec des valeurs de 0 et 1
    mois_annee.janvier = 1;    // 1 pour janvier (événement présent)
    mois_annee.fevrier = 0;    // 0 pour février (événement absent)
    mois_annee.mars = 1;       // 1 pour mars (événement présent)
    mois_annee.avril = 0;      // 0 pour avril (événement absent)
    mois_annee.juin = 0;       // 0 pour juin (événement absent)
    mois_annee.juillet = 1;    // 1 pour juillet (événement présent)
    mois_annee.aout = 0;       // 0 pour août (événement absent)
    mois_annee.septembre = 1;  // 1 pour septembre (événement présent)
    mois_annee.novembre = 1;   // 1 pour novembre (événement présent)
    mois_annee.decembre = 0;   // 0 pour décembre (événement absent)
    
    struct fruit_legume fruit_legume_ini;
    fruit_legume_ini.nom = argp->nom_fruit_legume;
    fruit_legume_ini.mois_saison = mois_annee;  
    fruit_legume_ini.pays = "France";
    fruit_legume_ini.choisir = "jsp";
    fruit_legume_ini.conserver = "jsp";
    fruit_legume_ini.calories = 50000;
    fruit_legume_ini.sucres = 1;

    struct poisson poisson_ini;
    poisson_ini.nom = argp->nom_poisson;
    poisson_ini.provenance_recommander = "jsp";
    poisson_ini.provenance_eviter = "jsp";
    poisson_ini.choisir = "jsp";
    poisson_ini.sante_bienfait = "jsp";
    poisson_ini.sante_calories = 50000;
    poisson_ini.sante_proteine = 50000;
    poisson_ini.sante_mat_grasses = 50000;
    poisson_ini.menace = 0;

    struct recette recette_ini;  
    recette_ini.nom = argp->nom_recette;
    recette_ini.temp = 0;
    recette_ini.budget = 0;
    recette_ini.calories = 0;
    recette_ini.saison = 0;
    recette_ini.nb_pers = "jsp";
    recette_ini.allergene = NULL;
    recette_ini.fruits_legumes[0] = fruit_legume_ini;
    recette_ini.poissons[0] = poisson_ini;
    recette_ini.recette = "jsp";
    recette_ini.createur = compte2_ini;

    

    list_compte[nb_compte++] = compte2_ini;
    list_fruit_legume[nb_fruit_legume++] = fruit_legume_ini;
    list_poisson[nb_poisson++] = poisson_ini;
    list_recette[nb_recette++] = recette_ini;

    return 1;  // Added missing semicolon
}



