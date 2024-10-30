#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define SERVERPORT 1313
#define MAX 10

void SommaMedia(int *numeri, int *somma, float *media) 
{
    *somma = 0;
    int n = 0;
    for (int i = 0; i < MAX; i++) 
    {
        *somma += numeri[i];
        n++;
    }
    *media = (float)(*somma) / n;
}

int main()
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen=sizeof(servizio);
    int numeri[MAX], somma;
    float media;
    servizio.sin_family=AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVERPORT);
    socketfd=socket(AF_INET,SOCK_STREAM,0);
    bind(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));
    listen(socketfd,10);
    printf("Server in ascolto...\n");
    for (; ;)
    {
        fflush(stdout);
        soa=accept(socketfd,(struct sockaddr*)&addr_remoto,&fromlen);
        read(soa, numeri, MAX * sizeof(int));
        SommaMedia(numeri, &somma, &media);  
        write(soa, &somma, sizeof(somma));
        write(soa, &media, sizeof(media));
        close(soa);
     }
   return 0;
}