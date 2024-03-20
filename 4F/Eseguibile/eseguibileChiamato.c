#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    printf("Sono l'eseguibile chiamato: il mio PID=%d\n", getpid());
    printf("%s, %s", argv[0], argv[1]);
    return 0;
}