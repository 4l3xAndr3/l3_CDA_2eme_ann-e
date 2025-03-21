/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "etiquettable.h"


void
etiquetableprog_1(char *host)
{
	CLIENT *clnt;
	int  *result_1;
	compte  inscription_1_arg;
	int  *result_2;
	connection  connexion_1_arg;
	fruit_legume  *result_3;
	char  fiche_fruit_legume_1_arg;
	poisson  *result_4;
	char  fiche_poisson_1_arg;
	recette  *result_5;
	char  fiche_recette_1_arg;
	compte  *result_6;
	char  fiche_user_1_arg;
	int  *result_7;
	char *deconnexion_1_arg;
	int  *result_8;
	init  ini_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, ETIQUETABLEPROG, ETIQUETABLEVERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
printf("test 0");
	//inscription
	inscription_1_arg.photo = NULL;
    inscription_1_arg.email = strdup("alex@email.com");
    inscription_1_arg.mdp = strdup("1234");
    inscription_1_arg.prenom = strdup("alex");
    inscription_1_arg.nom = strdup("moi");
    inscription_1_arg.date_naissance = strdup("15/04/2024");
    inscription_1_arg.genre = strdup("M");
    inscription_1_arg.condition_general = 1;
    inscription_1_arg.newsletter = 0;
    inscription_1_arg.location = NULL;  
    inscription_1_arg.profil_allimentaire = NULL;
    
	connexion_1_arg.email="alex@email.com";
	connexion_1_arg.mdp="1234";
	
	fiche_fruit_legume_1_arg="pomme";
	fiche_poisson_1_arg ="truite";
	fiche_recette_1_arg ="chesse burger";
	fiche_user_1_arg = "toto@test.com";

	
	//ini les variable
	ini_1_arg.compte_ini= inscription_1_arg;
	ini_1_arg.nom_fruit_legume=fiche_fruit_legume_1_arg;
	ini_1_arg.nom_poisson=fiche_poisson_1_arg;
	ini_1_arg.nom_recette=fiche_recette_1_arg;
	ini_1_arg.email=fiche_user_1_arg;
	printf("test 1");
/*	result_8 = ini_1(&ini_1_arg, clnt);
	if (result_8 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
*/
	
	result_1 = inscription_1(&inscription_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}/*
	printf("test inscription result : %ls \n",result_1);
	result_2 = connexion_1(&connexion_1_arg, clnt);
	if (result_2 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	printf("test connexion result : %ls \n",result_2);

	result_3 = fiche_fruit_legume_1(&fiche_fruit_legume_1_arg, clnt);
	if (result_3 == (fruit_legume *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	printf("test fiche_fruit_legume result : nom: %s / pays producteur: %s \n",result_3->nom,result_3->pays);

	result_4 = fiche_poisson_1(&fiche_poisson_1_arg, clnt);
	if (result_4 == (poisson *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	printf("test fiche_poisson result : nom: %s \n",result_4->nom);

	result_5 = fiche_recette_1(&fiche_recette_1_arg, clnt);
	if (result_5 == (recette *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	printf("test fiche_recette result : nom: %s \n",result_5->nom);

	result_6 = fiche_user_1(&fiche_user_1_arg, clnt);
	if (result_6 == (compte *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	printf("test connexion result : mail:%s nom:%s prenom: %s \n",result_6->email,result_6->nom,result_6->prenom);
	
	result_6 = fiche_user_1("", clnt);
	if (result_6 == (compte *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	printf("test connexion result : mail:%s nom:%s prenom:%s \n",result_6->email,result_6->nom,result_6->prenom);
	
	result_7 = deconnexion_1((void*)&deconnexion_1_arg, clnt);
	if (result_7 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	printf("test connexion result : %ls \n",result_7);
	*/
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	etiquetableprog_1 (host);
exit (0);
}
