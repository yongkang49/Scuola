#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    char titolo[25];
    char autore[25];
    float prezzo;
}Libro;
int main(int argc, char *argv[])
{
    int p;
    int pp[2];     
    if (pipe(pp) < 0)
    {
        printf("\npipe non riuscita\n");
        exit(-1);
    }
    p = fork();
    if (p < 0)
    {
        printf("\nFork non riuscita\n");
        exit(-1);
    }
    if (p == 0) // figlio
    {
        printf("figlio\n");
        close(pp[1]);
        Libro lib1;
        Libro lib2;
        read(pp[0], &lib1, sizeof(Libro));
        read(pp[0], &lib2, sizeof(Libro));
        printf("libro1 titolo: %s autore: %s prezzo: %f\n", lib1.titolo, lib1.autore, lib1.prezzo);
        printf("libro2 titolo: %s autore: %s prezzo: %f\n", lib2.titolo, lib2.autore, lib2.prezzo);
        close(pp[0]);
    }
    else if (p > 0) // padre
    {
        printf("padre\n");
        close(pp[0]);
        Libro libro1;
        Libro libro2;
        printf("Inserisci il titolo del libro1:\n");
        scanf("%s", libro1.titolo);
        printf("Inserisci l'autore del libro1:\n");
        scanf("%s", libro1.autore);
        printf("Inserisci il prezzo del libro1:\n");
        scanf("%f", &libro1.prezzo);
        printf("Inserisci il titolo del libro2:\n");
        scanf("%s", libro2.titolo);
        printf("Inserisci l'autore del libro2:\n");
        scanf("%s", libro2.autore);
        printf("Inserisci il prezzo del libro2:\n");
        scanf("%f", &libro2.prezzo);
        write(pp[1], &libro1, sizeof(Libro));
        write(pp[1], &libro2, sizeof(Libro));
        close(pp[1]);
    }
    return 0;
}