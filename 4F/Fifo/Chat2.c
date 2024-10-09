#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

#define BUFFER_DIM 1024

int main()
{
    int fd, n;
    char buffer[BUFFER_DIM];
    if (mkfifo("fifo1", 0777) == -1)
    {
        if (errno != EEXIST)
        {
            printf("Errore\n");
            return 1;
        }
    }
    if (mkfifo("fifo2", 0777) == -1)
    {
        if (errno != EEXIST)
        {
            printf("Errore\n");
            return 1;
        }
    }
    printf("inizia a chat\n");
    int p = fork();
    do
    {
        if (p == 0)
        {
            fd = open("fifo2", O_WRONLY);
            scanf("%s", buffer);
            write(fd, buffer, sizeof(buffer));
            close(fd);
        }
        else
        {
            fd = open("fifo1", O_RDONLY);
            read(fd, buffer, sizeof(buffer));
            printf("\x1b[32m %s <-----\n", buffer);
            printf("\x1b[0m");
            close(fd);
        }
    } while (strcmp(buffer, "HALT"));
    close(fd);
    return 0;
}
