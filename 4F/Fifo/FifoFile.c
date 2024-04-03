#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BLOCK_DIM 1024
#define PROGRAM "es1"

int spawn(char program[], char *argument[])
{
    int pid;
    pid = fork();
    if (pid < 0)
    {
        return -1;
    }
    if (pid > 0)
    {
        return 0;
    }
    execv(program, argument);
    abort();
}

int main(int argc, char *argv[])
{
    FILE *file;
    int fifo;
    unsigned char buffer[BLOCK_DIM];
    int n;
    char *arg[3];
    if (argc != 3)
    {
        printf("errore argomenti\n");
        return 0;
    }

    // creazione riga di comando
    arg[0] = (char *)malloc(strlen(PROGRAM) + 1);
    strcpy(arg[0], PROGRAM);
    arg[1] = (char *)malloc(strlen(argv[2]) + 1);
    strcpy(arg[1], argv[2]);
    arg[2] = NULL;

    // invocazione programma
    if (spawn(PROGRAM, arg) < 0)
    {
        printf("Errore creazione processo\r\n");
        free(arg[0]);
        free(arg[1]);
        return 0;
    }

    // apertura in scrittura FIFO
    fifo = open("my_fifo", O_WRONLY);
    if (fifo < 0)
    {
        printf("Errore apertura FIFO\r\n");
        free(arg[0]);
        free(arg[1]);
        return 0;
    }

    // apertura in lettura file di origine
    file = fopen(argv[1], "rb");
    if (file == NULL)
    {
        printf("Errore apertura file \"%s\"\r\n", argv[1]);
        close(fifo); // chiusura FIFO
        free(arg[0]);
        free(arg[1]);
        return 0;
    }

    // lettura da file di blocchi di dati e inserimento nella FIFO
    while ((n = fread(buffer, 1, sizeof(buffer), file)) > 0)
        write(fifo, buffer, n);
    fclose(file); // chiusura file
    close(fifo);  // chiusura FIFO
    free(arg[0]);
    free(arg[1]);
    return 1;
}