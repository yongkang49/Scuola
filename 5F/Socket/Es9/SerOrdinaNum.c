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

void Ordina(int* numeri, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (numeri[j] > numeri[j + 1]) {
                int temp = numeri[j];
                numeri[j] = numeri[j + 1];
                numeri[j + 1] = temp;
            }
        }
    }
}

int main()
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen=sizeof(servizio);
    int numeri[MAX];
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
        read(soa, numeri, MAX * sizeof(int));
        Ordina(numeri, MAX);
        write(soa, numeri, sizeof(numeri));
        close(soa);
    }  
   return 0;
    
}