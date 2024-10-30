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
#define MAX 10

void MaxMin(int* numeri, int* max, int* min) 
{
    *max = numeri[0];
    *min = numeri[0];
    for (int i = 1; i < MAX; i++) 
    {
        if (numeri[i] > *max) 
        {
            *max = numeri[i];
        }
        if (numeri[i] < *min) 
        {
            *min = numeri[i];
        }
    }
}

int main()
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen=sizeof(servizio);
    int numeri[MAX];
    int max, min;
    servizio.sin_family=AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVERPORT);
    socketfd=socket(AF_INET,SOCK_STREAM,0);
    bind(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));
    listen(socketfd,10);
    printf("Server in ascolto...\n");
    for (; ;)
    {
        fflush(stdout);
        soa=accept(socketfd,(struct sockaddr*)&addr_remoto,&fromlen);
        read(soa, numeri, sizeof(numeri));
        MaxMin(numeri, &max, &min);
        write(soa, &max, sizeof(max));
        write(soa, &min, sizeof(min));
        close(soa);
     }
   return 0;
}
    