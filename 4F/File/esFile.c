#include <stdio.h>
#include <stdlib.h>
#define BUFFER_DIM 1024
int main(int argc, char *argv[])
{
    FILE *origine, *destinazione;
    int n;
    unsigned char buffer[BUFFER_DIM];
    if (argc = !3)
    {
        printf("errore argomenti");
        exit(1);
    }
    origine = fopen(argv[1], "r");
    if (origine == NULL)
    {
        printf("errore apertura file origine");
        exit(1);
    }
    destinazione = fopen(argv[2], "w");
    if (destinazione == NULL)
    {
        printf("errore apertura file destinazione");
        exit(1);
    }
    while (!feof(origine))
    {
        n = fread(buffer, 1, BUFFER_DIM, origine);
        if (n > 0)
        {
            fwrite(buffer, 1, n, destinazione);
        }
    }
    fclose(origine);
    fclose(destinazione);
    return 0;
}