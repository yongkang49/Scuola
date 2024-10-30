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

int main(int argc, char **argv)
{

    struct sockaddr_in servizio;
    int socketfd;
    int numeri[MAX], somma;
    float media;
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
    printf("Inserisci gli elementi: ");
    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", &numeri[i]);
    }
    write(socketfd, numeri, MAX * sizeof(int));
    read(socketfd, &somma, sizeof(somma));
    read(socketfd, &media, sizeof(media));
    printf("Somma: %d\n Media: %.2f\n", somma, media);
    close(socketfd);
    return 0;
}