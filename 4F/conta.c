#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int p;
int main(int argc, char *argv[])
{
    p = fork();
    if (p < 0)
    {
        printf("errore");
        exit(1);
    }
    else if (p > 0)
    {
        printf("mio PID: %d e mio figlio ha PID: %d\n", getpid(), p);
        for (int i = 0; i < 19; i++)
        {
            printf("%d ", i);
        }
    }
    else
    {
        printf("\nmio PID: %d e mio padre ha PID: %d\n", getpid(), getppid());
        for (int i = 0; i < 9; i++)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}