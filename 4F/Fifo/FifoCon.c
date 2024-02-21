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
        if (errno != EEXIST)
        {
            printf("errore creazione Fifo\n");
            exit(-1);
        }
    }
    // apre la FIFO in scrittura
    fd = open("myFifo_1", O_RDONLY);
    int x[5], somma = 0;
    if (read(fd, &x, sizeof(x)) < 0)
    {
        printf("read non riuscita\n");
        exit(0);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", x[i]);
        somma += x[i];
    }

    printf("%d\n", somma);
    close(fd);
    return 0;
}