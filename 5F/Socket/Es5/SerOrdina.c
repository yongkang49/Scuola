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

void Ordina(char str[])
{
    char temp;
    for (int i = 0; i < strlen(str) - 1; i++)
    {
        for (int k = 0; k < strlen(str) - 1 - i; k++)
        {
            if (str[k] >= str[k + 1])
            {
                temp = str[k];
                str[k] = str[k + 1];
                str[k + 1] = temp;
            }
        }
    }
}
void ToLower(char str[])
{
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = tolower(str[i]);
    }
}
void EliminaNumeri(char str[])
{
    int cont = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
        {
        }
        else
        {
            cont++;
            for (int j = i; j < strlen(str) - 1; j++)
            {
                str[j] = str[j + 1];
            }
        }
    }
    str[strlen(str) - cont] = '\0';
}

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
        printf("Stringa ricevuta: %s\n", str);
        EliminaNumeri(str);
        ToLower(str);
        Ordina(str);
        strcpy(msg, str);
        printf("Stringa inviata : %s\n", msg);
        write(soa, msg, strlen(msg));
        close(soa);
    }
    return 0;
}