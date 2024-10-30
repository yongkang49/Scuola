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
#define MAX 50
#define DIM 10

int main(int argc, char **argv)
{
    struct sockaddr_in servizio;
    int socketfd;
    char msg[MAX];
    int numeri[DIM];
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
    printf("inserisci %d numeri interi\n", DIM);
    for (int i = 0; i < DIM; i++)
    {
        printf("%d-", i + 1);
        scanf("%d", &numeri[i]);
    }

    write(socketfd, numeri, sizeof(numeri));
    read(socketfd, msg, sizeof(msg));
    printf("%s\n", msg);
    close(socketfd);
    return 0;
}