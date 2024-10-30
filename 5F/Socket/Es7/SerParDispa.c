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

void Calcoli(int* numeri, int* sommaPar, float* mediaPar, int* sommaDis, float* mediaDis) {
    int contPar = 0, contDis = 0;
    *sommaPar = 0;
    *sommaDis = 0;
    for (int i = 0; i < MAX; i++) 
    {
        if (numeri[i] % 2 == 0) 
        { 
            *sommaPar += numeri[i];
            contPar++;
        } 
        else 
        { 
            *sommaDis += numeri[i];
            contDis++;
        }
    }
    *mediaPar = (float)(*sommaPar) / contPar;
    *mediaDis = (float)(*sommaDis) / contDis;
}
int main()
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen=sizeof(servizio);
    int numeri[MAX];
    int sommaPar, sommaDis;
    float mediaPar, mediaDis;
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
        Calcoli(numeri, &sommaPar, &mediaPar, &sommaDis, &mediaDis);
        write(soa, &sommaPar, sizeof(sommaPar));
        write(soa, &mediaPar, sizeof(mediaPar));
        write(soa, &sommaDis, sizeof(sommaDis));
        write(soa, &mediaDis, sizeof(mediaDis));
        close(soa);
     }
      
   return 0;
    
}