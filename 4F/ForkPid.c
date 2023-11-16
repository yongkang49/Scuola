#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int p; // p != 0 è il processo originare
       // p == 0 è il processo clonato
int main(int argc, char *argv[])
{
    p = fork(); // generazione di un processo in palarello
    if (p != 0)
    {
        printf("sono il padre p = %d PID = %d, il mio padre ha PID=%d\n", p, getpid(), getppid());
    }
    else
    {
        printf("sono il figlio p = %d PID = %d pid padre = %d\n", p, getpid(), getppid());
    }
    return 0;
}