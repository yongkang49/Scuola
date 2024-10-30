#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define SERVERPORT 1313
#define MAX 10

void Leggi(int numeri[])
{
    printf("Inserisci %d numeri interi:\n", MAX);
    for (int i = 0; i < MAX; i++) 
    {
        scanf("%d", &numeri[i]);
    }
}
void Scrivi(int numeri[])
{
    printf("Vettore ordinato:\n");
    for (int i = 0; i < MAX; i++) 
    {
        printf("%d\n", numeri[i]);
    }
}

int main(int argc,char** argv)
{
       
    struct sockaddr_in servizio;
    int socketfd;
    int numeri[MAX];
    servizio.sin_family=AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVERPORT);
    socketfd=socket(AF_INET,SOCK_STREAM,0);
    connect(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));
    Leggi(numeri);
    write(socketfd, numeri, sizeof(numeri));
    read(socketfd, numeri, sizeof(numeri));
    Scrivi(numeri);
    close(socketfd);
    return 0;
}