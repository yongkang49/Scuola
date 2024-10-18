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

#define DIM 100
#define SERVERPORT 1313

int main(int argc, char *argv[])
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen = sizeof(servizio);
    char str[DIM], msg[DIM];
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
    listen(socketfd, 10);
    printf("Server in ascolto: \n");
    for (;;)
    {
        fflush(stdout);
        soa = accept(socketfd, (struct sockaddr *)&addr_remoto, &fromlen);
        read(soa, str, sizeof(str));
        if (strcpy(msg, str) < 0)
        {
            printf("Errore nel processo\n");
        }
        else
        {
            for (int i = 0; i < strlen(str); i++)
            {
                msg[i] = toupper(msg[i]);
            }
        }
        printf("Stringa ricevuta: %s\n", str);
        printf("Stringa inviata : %s\n", msg);
        write(soa, msg, strlen(msg));
        close(soa);
    }
    return 0;
}