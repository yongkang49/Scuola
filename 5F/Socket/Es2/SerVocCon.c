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

void controllaConVoc(char str[], int *contVoc, int *contCon)
{
    char vocali[] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = tolower(str[i]);
    }
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            (*contVoc)++;
        }
        else
        {
            (*contCon)++;
        }
    }
}
int main(int argc, char *argv[])
{

    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen = sizeof(servizio);
    char str[DIM], msg[DIM];
    int contVoc = 0, contCon = 0;
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
        controllaConVoc(str, &contVoc, &contCon);
        sprintf(msg, "la parola contiene %d Vocali e %d consonanti", contVoc, contCon);
        printf("Stringa ricevuta: %s\n", str);
        printf("Stringa inviata : %s\n", msg);
        write(soa, msg, strlen(msg));
        close(soa);
    }
    return 0;
}