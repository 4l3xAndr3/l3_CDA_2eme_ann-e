#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define HOST_NAME_MAX 64
#define TRUE 1

char afficheNomMachine(void){
    char nomMachine[HOST_NAME_MAX]={'\0'};
    int ret = gethostname(nomMachine, HOST_NAME_MAX);
    if(ret == -1){
        printf("ERREUR : nom de la machine introuvable\n");
    }
    else{
        printf("machine %s \n", nomMachine);
    }
    return nomMachine;
}

in_addr_t afficheIpMachine(const char * name){
    struct hostent *he;
    in_addr_t * adrIP;
    int i=0;
    he = gethostbyname(name);

   if(he==NULL){
    return (in_addr_t) 0;
   } else{
    for(i=0; he->h_aliases[i]!=NULL; i++){
        printf("alias %s\n", he->h_aliases[i]);
    }
   }
   for(i=0; he->h_addr_list[i]!=NULL; i++){
    adrIP = (in_addr_t *) he->h_addr_list[i];
    printf("adresse IP %d\n", adrIP);
   }
   return (he->h_addr_list[i]);
}

main(int argc, char **argv){
   afficheNomMachine();
   afficheIpMachine("localhost");


}