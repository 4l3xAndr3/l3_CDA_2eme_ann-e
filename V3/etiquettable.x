struct compte{
	char photo[50];
	char email[50];
	char  mdp[50];
	char  prenom[50];
	char  nom[50];
	char  date_naissance[50];
	char  genre[50];
	int condition_general;
	int newsletter;
	char  location[50];
	char  profil_allimentaire[50];
};
struct mois{
 	int janvier;
 	int fevrier;
 	int mars;
 	int avril;
 	int juin;
 	int juillet;
 	int aout;
 	int septembre;
 	int novembre;
 	int decembre;
};
 
struct fruit_legume{
	char  nom[50];
	mois mois_saison;
	char  pays[50];
	char  choisir[50];
	char  conserver[50];
	int calories;
	int sucres;
};

struct poisson{
	char  nom[50];
	char  provenance_recommander[50];
	char  provenance_eviter[50];
	char  choisir[50];
	char  sante_bienfait[50];
	int sante_calories;
	int sante_proteine;
	int sante_mat_grasses;
	int menace;
};
struct recette{
	char  nom[50];
	int temp;
	int budget;
	int calories;
	int saison;
	int nb_pers;
	char  allergene[50];
	fruit_legume fruits_legumes[50];
	poisson poissons[50];
	char  recette[50];
	struct compte createur;
};

struct connection{
	char email[50];
	char mdp[50];
};

struct init{
	compte compte_ini;
	char nom_fruit_legume[50];
	char nom_poisson[50];
	char nom_recette[50];
	char email[50];
};
	
	
program ETIQUETABLEPROG{
	version ETIQUETABLEVERS{
		int ini(init)=1;
		int inscription(compte)=2;
		int connexion(connection)=3;
		fruit_legume fiche_fruit_legume(char *nom)=4;
		poisson fiche_poisson(char *nom)=5;
		recette fiche_recette(char * nom)=6;
		compte fiche_user(char * email)=7;
		int deconnexion()=8;
	}=1;
}=0x23456789;





		
		
	
	
