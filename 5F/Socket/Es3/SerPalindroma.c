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

#define PORT 3131
#define DIM 100

int ControlloPalindroma(char str[])
{
    int len = strlen(str) / 2;
    int continua = 1;
    for (int i = 0; i < len && continua; i++)
    {
        if (str[i] != str[strlen(str) -1 - i])
        {
            continua = 0;
        }
    }
    if (continua)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main(int argc, char *argv[])
{
    struct sockaddr_in server, addrRemoto;
    int socketfd, soa, lenght = sizeof(server);
    char str[DIM], msg[DIM];
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(PORT);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketfd, (struct sockaddr *)&server, sizeof(server));
    listen(socketfd, 10);
    printf("Server in ascolto: \n");
    while (1)
    {
        fflush(stdout);
        soa = accept(socketfd, (struct sockaddr *)&addrRemoto, &lenght);
        read(soa, str, sizeof(str));
        printf("stringa ricevuta: %s\n", str);
        if (ControlloPalindroma(str))
        {
            sprintf(msg, "è una stringa palindroma\n");
        }
        else
        {
            sprintf(msg, "non è una stringa palindroma\n");
        }
        write(soa, msg, strlen(msg));
        printf("stringa inviata: %s\n", msg);
        close(soa);
    }
    return 0;
}