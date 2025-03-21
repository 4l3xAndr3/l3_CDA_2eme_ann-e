struct compte{
	char * photo;
	char * email;
	char * mdp;
	char * prenom;
	char * nom;
	char * date_naissance;
	char * genre;
	int condition_general;
	int newsletter;
	char * location;
	char * profil_allimentaire;
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
	char * nom;
	struct mois mois_saison;
	char * pays;
	char * choisir;
	char * conserver;
	int calories;
	int sucres;
};

struct poisson{
	char * nom;
	char * provenance_recommander;
	char * provenance_eviter;
	char * choisir;
	char * sante_bienfait;
	int sante_calories;
	int sante_proteine;
	int sante_mat_grasses;
	int menace;
};
struct recette{
	char * nom;
	int temp;
	int budget;
	int calories;
	int saison;
	int nb_pers;
	char * allergene;
	struct fruit_legume fruits_legumes[50];
	struct poisson poissons[50];
	char * recette;
	struct compte createur;
};

struct connect{
	char * email;
	char * mdp;
};

struct ini{
	struct compte compte_ini;
	char * nom_fruit_legume;
	char * nom_poisson;
	char * nom_recette;
	char * email;
};
	
	
program ETIQUETABLEPROG{
	version ETIQUETABLEVERS{
		int inscription(compte)=1;
		int connexion(connect)=2;
		fruit_legume fiche_fruit_legume(char * nom)=3;
		poisson fiche_poisson(char * nom)=4;
		recette fiche_recette(char * nom)=5;
		compte fiche_user(char * email)=6;
		int deconnexion()=7;
		int ini(ini)=8;
	}=1;
}=0x23456789;





		
		
	
	
