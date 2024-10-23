#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define PORT 1313
#define DIM 100

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("errore argomenti\n");
        exit(0);
    }
    struct sockaddr_in servizio;
    int socketfd;
    char str[DIM];
    char car[1];
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(PORT);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
    strcpy(str, argv[1]);
    write(socketfd, str, sizeof(str));
    strcpy(car, argv[2]);
    write(socketfd, car, sizeof(car));
    read(socketfd, str, sizeof(str));
    printf("\nStringhe ricevute: %s\n", str);
    close(socketfd);
    return 0;
}