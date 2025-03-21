/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _ETIQUETTABLE_H_RPCGEN
#define _ETIQUETTABLE_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct compte {
	char *photo;
	char *email;
	char *mdp;
	char *prenom;
	char *nom;
	char *date_naissance;
	char *genre;
	int condition_general;
	int newsletter;
	char *location;
	char *profil_allimentaire;
};
typedef struct compte compte;

struct mois {
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
typedef struct mois mois;

struct fruit_legume {
	char *nom;
	struct mois mois_saison;
	char *pays;
	char *choisir;
	char *conserver;
	int calories;
	int sucres;
};
typedef struct fruit_legume fruit_legume;

struct poisson {
	char *nom;
	char *provenance_recommander;
	char *provenance_eviter;
	char *choisir;
	char *sante_bienfait;
	int sante_calories;
	int sante_proteine;
	int sante_mat_grasses;
	int menace;
};
typedef struct poisson poisson;

struct recette {
	char *nom;
	int temp;
	int budget;
	int calories;
	int saison;
	int nb_pers;
	char *allergene;
	struct fruit_legume fruits_legumes[50];
	struct poisson poissons[50];
	char *recette;
	struct compte createur;
};
typedef struct recette recette;

struct connection {
	char *email;
	char *mdp;
};
typedef struct connection connection;

struct init {
	struct compte compte_ini;
	char *nom_fruit_legume;
	char *nom_poisson;
	char *nom_recette;
	char *email;
};
typedef struct init init;

#define ETIQUETABLEPROG 0x23456789
#define ETIQUETABLEVERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define inscription 1
extern  int * inscription_1(compte *, CLIENT *);
extern  int * inscription_1_svc(compte *, struct svc_req *);
#define connexion 2
extern  int * connexion_1(connection *, CLIENT *);
extern  int * connexion_1_svc(connection *, struct svc_req *);
#define fiche_fruit_legume 3
extern  fruit_legume * fiche_fruit_legume_1(char *, CLIENT *);
extern  fruit_legume * fiche_fruit_legume_1_svc(char *, struct svc_req *);
#define fiche_poisson 4
extern  poisson * fiche_poisson_1(char *, CLIENT *);
extern  poisson * fiche_poisson_1_svc(char *, struct svc_req *);
#define fiche_recette 5
extern  recette * fiche_recette_1(char *, CLIENT *);
extern  recette * fiche_recette_1_svc(char *, struct svc_req *);
#define fiche_user 6
extern  compte * fiche_user_1(char *, CLIENT *);
extern  compte * fiche_user_1_svc(char *, struct svc_req *);
#define deconnexion 7
extern  int * deconnexion_1(void *, CLIENT *);
extern  int * deconnexion_1_svc(void *, struct svc_req *);
#define ini 8
extern  int * ini_1(init *, CLIENT *);
extern  int * ini_1_svc(init *, struct svc_req *);
extern int etiquetableprog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define inscription 1
extern  int * inscription_1();
extern  int * inscription_1_svc();
#define connexion 2
extern  int * connexion_1();
extern  int * connexion_1_svc();
#define fiche_fruit_legume 3
extern  fruit_legume * fiche_fruit_legume_1();
extern  fruit_legume * fiche_fruit_legume_1_svc();
#define fiche_poisson 4
extern  poisson * fiche_poisson_1();
extern  poisson * fiche_poisson_1_svc();
#define fiche_recette 5
extern  recette * fiche_recette_1();
extern  recette * fiche_recette_1_svc();
#define fiche_user 6
extern  compte * fiche_user_1();
extern  compte * fiche_user_1_svc();
#define deconnexion 7
extern  int * deconnexion_1();
extern  int * deconnexion_1_svc();
#define ini 8
extern  int * ini_1();
extern  int * ini_1_svc();
extern int etiquetableprog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_compte (XDR *, compte*);
extern  bool_t xdr_mois (XDR *, mois*);
extern  bool_t xdr_fruit_legume (XDR *, fruit_legume*);
extern  bool_t xdr_poisson (XDR *, poisson*);
extern  bool_t xdr_recette (XDR *, recette*);
extern  bool_t xdr_connection (XDR *, connection*);
extern  bool_t xdr_init (XDR *, init*);

#else /* K&R C */
extern bool_t xdr_compte ();
extern bool_t xdr_mois ();
extern bool_t xdr_fruit_legume ();
extern bool_t xdr_poisson ();
extern bool_t xdr_recette ();
extern bool_t xdr_connection ();
extern bool_t xdr_init ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_ETIQUETTABLE_H_RPCGEN */
