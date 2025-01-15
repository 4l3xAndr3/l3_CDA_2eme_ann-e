#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define TRUE 1

int main (int argc, char **argv) {
	int socket_RV, socket_service;
	char buf[256];
	struct sockaddr_in adresseRV;
	unsigned int lgadresseRV;
	struct sockaddr_in adresseClient;
	unsigned int lg_adresseClient;
	unsigned short port;
	
	/* Création de la socket de RV */
	if ((socket_RV = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        exit(1);
    }
	/* Préparation de l'adresse locale */

	port = (unsigned short) atoi(argv[1]);

    adresseRV.sin_family = AF_INET;
    adresseRV.sin_port = htons(port);
    adresseRV.sin_addr.s_addr = htonl(INADDR_ANY); /* toutes les addresses de la machine locale */
    lgadresseRV = sizeof(adresseRV);
	
	/* attachement de la socket à l'adresse locale */
	if ((bind(socket_RV, (struct sockaddr *) &adresseRV, lgadresseRV)) == -1)
    {
        perror("bind");
        exit(3);
    }
	
	/* déclaration d'ouverture du service */
	if (listen(socket_RV, 10)==-1)
    {
        perror("listen");
        exit(4);
    }
	
	/* Si on devait afficher un numéro de port choisi aléatoirement, on devrait le récupérer. Ici c'est inutile car il est fixé */
	getsockname(socket_RV, (struct sockaddr *) &adresseRV, &lgadresseRV);
	port = ntohs(adresseRV.sin_port);
	
	printf("Le service est en attente de connexion sur le port : %d & %s\n", port); 
	
	/* boucle d'attente de connexion */
	while(TRUE){
		printf("Début de la boucle \n");
		fflush(stdout);
		
		/* attente d'un client */
		lg_adresseClient = sizeof(adresseClient);
        socket_service = accept(socket_RV, (struct sockaddr *) &adresseClient, &lg_adresseClient);
        if (socket_service == -1)
        {
        perror("accept");
        exit(5);
        }
		
		/* traitement des erreurs */
		if(socket_service==-1 && errno==EINTR){
			/* rception d'un signal */
			continue;
		}
		if(socket_service == -1) {
			perror("Acceptation impossible\n");
			close(socket_RV);
			exit(4);
		}
		
		/* un client est arrivé */
		printf("connexion acceptée\n");
		fflush(stdout);
		
		/* lecture dans la socket d'une chaine de caractères */
		if (read(socket_service, buf, 256) < 0)
        {
            perror("read");
            exit(6);
        }

		printf("j'ai reçu %s\n", buf);
		fflush(stdout);
		
		/* écriture dans la socket */
		// strcpy ne supprime pas le contenu présent dans le buffer
		memset(buf, '\0', sizeof(buf));
		const char *fin = "tchao";
		int lg_msg=strlen(fin)+1;
		printf("fin=%s sizeof(fin)= %lu\n", fin, lg_msg);
		strcpy(buf, fin);
		if (write(socket_service, &buf, sizeof(int)) != sizeof(int))
        {
            perror("write");
            exit(7);
        }
		
		printf("réponse envoyée ...adios\n");
		close(socket_service);
	}
	close(socket_RV);
}