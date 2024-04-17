#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct
{
    char nome[20];
    char cognome[20];
    int media;
    int classe;
}Studente;

// thread POSIX
void *stampa(void *arg) {
    Studente *studente = (Studente *)arg;
    printf("Dati dello studente:\n");
    printf("Nome: %s\n", studente->nome);
    printf("Cognome: %s\n", studente->cognome);
    printf("Classe: %d\n", studente->classe);
    printf("Media: %d\n", studente->media);
    pthread_exit(NULL);
}

// Funzione per stampare i dati dello studente su file di testo
void *salva(void *arg) {
    Studente *studente = (Studente *)arg;
    FILE *file = fopen("dati_studente.txt", "w");
    if (file == NULL) {
        perror("Errore durante l'apertura del file");
        exit(0);
    }
    fprintf(file, "Dati dello studente:\n");
    fprintf(file, "Nome: %s\n", studente->nome);
    fprintf(file, "Cognome: %s\n", studente->cognome);
    fprintf(file, "Classe: %d\n", studente->classe);
    fprintf(file, "Media: %d\n", studente->media);
    fclose(file);
    pthread_exit(NULL);
}
int main()
{
     Studente st1;
    pthread_t tStampa, tSalva;
    printf("inserisci il nome: ");
    scanf("%s", st1.nome);
    printf("inserisci il cognome: ");
    scanf("%s", st1.cognome);
    printf("inserisci la classe: ");
    scanf("%d", &st1.classe);
    printf("inserisci la media: ");
    scanf("%d", &st1.media);
    pthread_create(&tStampa, NULL, &stampa, &st1);
    pthread_create(&tStampa, NULL, &salva, &st1);
    pthread_join(tStampa, NULL);
    pthread_join(tSalva, NULL);
    return 0;
}