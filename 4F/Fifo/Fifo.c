#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int fd;
    if (mkfifo("myFifo_1", 0777) < 0)
    {
        printf("errore creazione Fifo\n");
        exit(-1);
    }
    // apre la FIFO in scrittura
    fd = open("myFifo_1", O_WRONLY);
    printf("fifo creato\n");
    int x = 90;
    if (write(fd, &x, sizeof(x)) < 0)
    {
        printf("write non riuscita\n");
        exit(0);
    }
    printf("scrittura FIFO con successo");
    close(fd);
    return 0;
}