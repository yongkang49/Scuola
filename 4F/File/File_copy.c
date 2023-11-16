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
    do
    {
        c = fgetc(nomi); // fgetc = file get char
        putchar(c);      // output char
    } while (c != EOF);  // EOF = end of file
    fclose(nomi);
    return 0;
}