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
#define DIM 10
#define MAX 50

void Conta(int numeri[], int *contPar, int *contDis)
{
    for (int i = 0; i < DIM; i++)
    {
        if (numeri[i] % 2 == 0)
        {
            (*contPar)++;
        }
        else
        {
            (*contDis)++;
        }
    }
}
int main()
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen = sizeof(servizio);
    char msg[MAX];
    int numeri[DIM];
    int contPar = 0, contDis = 0;
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
        read(soa, numeri, sizeof(numeri));
        printf("numeri ricevuti: ");
        for (int i = 0; i < DIM; i++)
        {
            printf("%d ", numeri[i]);
        }
        printf("\n");
        Conta(numeri, &contPar, &contDis);
        sprintf(msg, "numeri pari sono %d e numeri dispari sono %d" , contPar, contDis);
        printf("messaggio inviata: %s\n", msg);
        write(soa, msg, sizeof(msg));
        close(soa);
    }
    return 0;
}