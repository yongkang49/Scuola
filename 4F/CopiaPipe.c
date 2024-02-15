#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

#define BUFFER_DIM 1024
int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("errore argomenti\n");
        exit(-1);
    }
    FILE *file;
    int lenghth;
    int p, p2, status;
    int pp[2], pp2[2];
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
        if (pipe(pp2) == -1)
        {
            printf("pipe non riuscita\n");
            exit(-1);
        }
        p2 = fork();
        if (p2 < 0)
        {
            printf("fork non riuscita\n");
            exit(0);
        }
        if (p2 == 0) // figlio 2
        {
            char car;
            int contCar = 0;
            car = *argv[3];
            file = fopen(argv[1], "rb");
            while ((lenghth = read(pp2[0], buffer, sizeof(buffer))) > 0)
            {
                if (buffer[lenghth] == car)
                {
                    contCar++;
                }
            }
            printf("il carattere %c è comparsa %d volte\n", car, contCar);
        }
        else
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
    }
    return 0;
}