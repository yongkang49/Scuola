#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX 5

int main()
{
    int p, status;
    int fp[2];
    if (pipe(fp) == -1)
    {
        printf("pipe non riuscita\n");
        exit(-1);
    }
    p = fork();
    if (p < 0)
    {
        printf("fork non riuscita\n");
        exit(0);
    }
    if (p == 0) // figlio
    {
        int numeri[MAX];
        close(fp[0]);
        //printf("PID: %d\n", getpid());
        for (int i = 0; i < MAX; i++)
        {
            printf("inserisci il %d numero: ", i + 1);
            scanf("%d", &numeri[i]);
        }
        write(fp[1], numeri, sizeof(numeri));
        close(fp[0]);
    }
    else // padre
    {
        int n;
        int numeri[MAX];
        //printf("\nPID: %d\n", getpid());
        close(fp[1]);
        read(fp[0], numeri, sizeof(numeri));
        close(fp[0]);
        printf("inserisci un numero da moltiplicare\n");
        scanf("%d", &n);
        for (int i = 0; i < MAX; i++)
        {
            printf("%d\n", numeri[i] * n);
        }
        wait(&status);
    }
    return 0;
}
