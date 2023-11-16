#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[20];
    char cognome[20];
    int media;
} student_t;

void Inserisci()
{
    
}
int main(int argc, char *argv[])
{
    student_t *punt[3];
    for (int i = 0; i < 3; i++)
    {
        punt[i] = malloc(sizeof(student_t));
        printf("inserisci il nome: ");
        scanf("%s", punt[i]->nome);
        printf("inserisci il cognome: ");
        scanf("%s", punt[i]->cognome);
        printf("inserisci la media: ");
        scanf("%d", &punt[i]->media);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%s, %p\n ", punt[i]->nome, &punt[i]->nome);
        printf("%s, %p\n ", punt[i]->cognome, &punt[i]->cognome);
        printf("%d, %p\n", punt[i]->media, &punt[i]->media);
        free(punt[i]);
    }
}
