#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

#define BUFFER_SIZE 1024
int main(int argc, char *argv[])
{
    int fd[2];
    int p, n;
    char buffer[BUFFER_SIZE];
    if (pipe(fd) < -1) // creazione pipe e controllo errore
    {
        printf("errore generazione pipe\n");
        exit(-1);
    }
    p = fork();
    if (p < 0) // controllo errore
    {
        printf("errore generazione fork\n");
        exit(0);
    }
    if (p > 0) // padre
    {
        printf("Pid = %d Figlio = %d\n", getpid(), p);
        close(fd[0]); // chiusura uscita (in lettura) pipe padre
        const char *messaggio = "Ciao\n";
        if (write(fd[1], messaggio, strlen(messaggio)) == -1)
        {
            printf("errore write pipe\n");
            exit(-1);
        }
        close(fd[1]);
    }
    else // figlio
    {
        printf("sono figlio: %d\n", getpid());
        close(fd[1]); // chiusura entrata (in scrittura) pipe figlio
        n = read(fd[0], buffer, BUFFER_SIZE);
        if (n == -1)
        {
            printf("errore read pipe\n");
            exit(-1);
        }
        else
        {
            buffer[n] = '\0';
            printf("%s", buffer);
        }
        close(fd[0]);
    }
    return 0;
}