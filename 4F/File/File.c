#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *nomi;                    // FILE = struttura
    char vetNomi[20];              // a = append (aggiunge nel file senza cancellare)
    nomi = fopen("nomi.txt", "w"); // fopen = file open (se esiste il file apre, altrimenti crea il file) w = write
    if (nomi == NULL)              // se file non è aperto
    {
        printf("errore");
        exit(0);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("inserisci il nome %d: ", i + 1);
        scanf("%s", vetNomi);
        fputs(vetNomi, nomi);
        fputc('\n', nomi);
    }
    fclose(nomi);
    return 0;
}