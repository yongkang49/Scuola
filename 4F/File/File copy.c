#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *nomi;                    // FILE = struttura
    char c;                        // a = append (aggiunge nel file senza cancellare)
    nomi = fopen("nomi.txt", "r"); // fopen = file open (se esiste il file apre, altrimenti crea il file) w = write
    if (nomi == NULL)              // se file non è aperto
    {
        printf("errore");
        exit(0);
    }
    for (int i = 0; i < 3; i++)
    {
        c = fgetc(nomi); // fgetc = file get char
        putchar(c);      // output char
    }
    fclose(nomi);
    return 0;
}