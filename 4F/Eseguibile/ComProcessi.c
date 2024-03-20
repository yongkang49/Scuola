#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Studente
{
    char nome[15];
    char cognome[15];
    int eta;
}st, st1;

int main(int argc, char *argv[])
{
    int p;
    int pp[2];
    if(pipe(pp)< 0)
    {
        printf("errore pipe\n");
        exit(0);
    }
    p = fork();
    if (p<0)
    {
        printf("errore fork\n");
        exit(0);
    }
    
    if (p>0)
    {
        close(pp[0]);
        printf("inserisci il nome dello studente: ");
        scanf("%s", st.nome);
        printf("inserisci il cognome dello studente: ");
        scanf("%s", st.cognome);
        printf("inserisci l'età dello studente: ");
        scanf("%d", &st.eta);
        write(pp[1], &st, sizeof(st));
        close(pp[1]);
    }
    else
    {
        close(pp[1]);
        read(pp[0], &st1, sizeof(st));
        printf("Nome: %s\n", st1.nome);
        printf("Cognome: %s\n", st1.cognome);
        printf("Eta: %d\n", st1.eta);
        close(pp[0]);
    }
    return 0;
}