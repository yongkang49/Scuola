#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

#define BUFFER_DIM 1024
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("errore argomenti\n");
        exit(-1);
    }
    FILE *file;
    int lenghth;
    int p, status;
    int pp[2];
    unsigned char buffer[BUFFER_DIM];
    if (pipe(pp) == -1)
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
        close(pp[1]);
        file = fopen(argv[2], "wb");
        if (file == NULL)
        {
            printf("errore apertura file argv[2]\n");
            close(pp[1]);
            exit(0);
        }
        while ((lenghth = read(pp[0], buffer, sizeof(buffer))) > 0)
        {
            fwrite(buffer, 1, lenghth, file);
        }
        close(pp[0]);
        fclose(file);
    }
    else // padre
    {
        close(pp[0]);
        file = fopen(argv[1], "rb");
        if (file == NULL)
        {
            printf("errore apertura file argv[1]\n");
            close(pp[1]);
            wait(&status);
            exit(0);
        }

        while ((lenghth = fread(buffer, 1, sizeof(buffer), file)) > 0)
        {
            write(pp[1], buffer, lenghth);
        }
        close(pp[1]);
        fclose(file);
    }
    return 0;
}