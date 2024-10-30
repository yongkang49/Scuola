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
#define DIM 50

int main(int argc,char** argv)
{
    struct sockaddr_in servizio;
    int socketfd;
    char str1[DIM], str2[DIM], msg[DIM];
    servizio.sin_family=AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVERPORT);
    socketfd=socket(AF_INET,SOCK_STREAM,0);
    connect(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));
    printf("inserisci la prima stringa\n");
    scanf("%s", str1);
    printf("inserisci la seconda stringa\n");
    scanf("%s", str2);
    write(socketfd, str1, sizeof(str1));
    write(socketfd, str2, sizeof(str2));
    read(socketfd, msg, sizeof(msg));
    printf("%s\n", msg);
    close(socketfd);
    return 0;
}