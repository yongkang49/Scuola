#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[20];
    char cognome[20];
    int media;
} student_t;

int main(int argc, char *argv[])
{
    student_t studente;
    student_t *stud = (student_t*)&studente;
    strcpy(stud -> nome, "yongkang");
    strcpy(stud -> cognome, "Hu");
    stud->media = 10;

    printf("%s\n", stud->nome);
    printf("%s\n", stud->cognome);
    printf("%d\n", stud->media);
    return 0;
}