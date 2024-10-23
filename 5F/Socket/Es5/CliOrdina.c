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
    struct sockaddr_in servizio;
    int socketfd;
    char str[DIM], new[DIM];
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(PORT);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
    printf("inserisci una stringa\n");
    scanf("%s", str);
    write(socketfd, str, sizeof(str));
    read(socketfd, new, sizeof(new));
    printf("Stringhe ricevute: %s\n", new);
    close(socketfd);
    return 0;
}