#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>



int main (int argc, char **argv) {
	int sock;
	char buf[256];
	struct sockaddr_in adresse_serveur;
	struct hostent *hote;
	unsigned short port;
	
	/* création de la socket locale */
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket");
		exit(1);
	}
	
	/* récupération de l'adresse IP du serveur (à partir de son nom) */
	if ((hote = gethostbyname(argv[2])) == NULL)
	{
		perror("gethostbyname");
		exit(2);
	}
	
	/* préparation de l'adresse du serveur */
	
	port = (unsigned short) atoi(argv[1]);

	adresse_serveur.sin_family = AF_INET;
	adresse_serveur.sin_port = htons(port);


	/* Important de faire une copy de l'adresse, car gethostbyname écrit dans la mémoire statique */
	/* Ici on récupère la première adresse IP de la machine. Potentiellement elle peut en avoir plusieurs */
	bcopy(hote->h_addr, &adresse_serveur.sin_addr, hote->h_length); /* l’adresse du serveur */
	printf("L'adresse du serveur en notation pointee %s\n", inet_ntoa(adresse_serveur.sin_addr));
	
	/* demande de connexion au serveur */
	if (connect(sock, (struct sockaddr *) &adresse_serveur, sizeof(adresse_serveur))==-1)
	{
		perror("connect");
		exit(3);
	}
	/* le serveur a accepté la connexion */
	printf("connexion acceptee\n");
	fflush(stdout);


	/* ecriture dans la socket */
	strcpy(buf, "salut");
	if (write(sock, buf, strlen(buf)+1) != strlen(buf)+1)
	{
		perror("write");
		exit(4);
	}
	printf("Chaine envoyée : %s\n", buf);
	fflush(stdout);

	printf("salut envoyé\n");
	fflush(stdout);
	
	/* lecture dans la socket d'une chaine */
	// On met à 0 le buffer de réception au cas où que le \0 ne soit pas envoyé
	memset(buf, '\0', sizeof(buf));

	if (read(sock, &buf, sizeof(int)) < 0)
	{
		perror("read");
		exit(5);
	}
	
	printf("j'ai reçu %s\n", buf);
	fflush(stdout);
	
	/* Fermeture du socket */
	close(sock);
}
		


