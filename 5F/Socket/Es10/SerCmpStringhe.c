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
#define DIM 50

int main()
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen = sizeof(servizio);
    char str1[DIM], str2[DIM], msg[DIM];
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
    listen(socketfd, 10);
    printf("Server in ascolto...\n");
    for (;;)
    {
        fflush(stdout);
        soa = accept(socketfd, (struct sockaddr *)&addr_remoto, &fromlen);
        read(soa, str1, sizeof(str1));
        printf("prima stringa ricevuta: %s\n", str1);
        read(soa, str2, sizeof(str2));
        printf("seconda stringa ricevuta: %s\n", str2);
        if (strlen(str1) > strlen(str2))
        {
            sprintf(msg, "la prima stringa è piu lunga");
        }
        else if (strlen(str1) < strlen(str2))
        {
            sprintf(msg, "la seconda stringa è piu lunga");
        }
        else
        {
            sprintf(msg, "le due stringhe hanno la stessa lunghezza");
        }
        printf("messaggio inviata: %s\n", msg);
        write(soa, msg, sizeof(msg));
        close(soa);
    }
    return 0;
}