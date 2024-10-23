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

int ContLet(char str[], char car[])
{
    int cont = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == car[0])
        {
            cont++;
        }
    }
    return cont;
}

int main(int argc, char *argv[])
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen = sizeof(servizio);
    char str[DIM], msg[DIM];
    char car[1];
    int cont;
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
        printf("Stringa ricevuta: %s\n", str);
        read(soa, car, 1);
        printf("Carattere ricevuto: %c\n", car[0]);
        cont = ContLet(str, car);
        sprintf(msg, "la parola contiene %d volte il carattere %c\n", cont , car[0]);
        printf("Stringa inviata : %s\n", msg);
        write(soa, msg, strlen(msg));
        close(soa);
    }
    return 0;
}