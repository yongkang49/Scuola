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

int main(int argc,char** argv)
{
       
    struct sockaddr_in servizio;
    int socketfd;
    int numeri[MAX];
    int sommaPar, sommaDis;
    float mediaPar, mediaDis;
    servizio.sin_family=AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVERPORT);
    socketfd=socket(AF_INET,SOCK_STREAM,0);
    connect(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));
    printf("Inserisci gli elementi: ");
    for (int i = 0; i < MAX; i++) {
        scanf("%d", &numeri[i]);
    }
    write(socketfd, numeri, MAX * sizeof(int));
    read(socketfd, &sommaPar, sizeof(sommaPar));
    read(socketfd, &mediaPar, sizeof(mediaPar));
    read(socketfd, &sommaDis, sizeof(sommaDis));
    read(socketfd, &mediaDis, sizeof(mediaDis));
    printf("Somma dei numeri pari: %d\n Media dei numeri pari: %.2f\n", sommaPar, mediaPar);
    printf("Somma dei numeri dispari: %d\n Media dei numeri dispari: %.2f\n", sommaDis, mediaDis);
    close(socketfd);
    return 0;
}
