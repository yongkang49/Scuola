#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define BUFFER_DIM 1024
FILE *origine;
FILE *destinazione;

// Funzione per stampare i dati dello studente su file di testo
void *Copia(void *arg)
{
    char buffer[BUFFER_DIM];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, BUFFER_DIM, origine)) > 0) {
        fwrite(buffer, 1, bytes_read, destinazione);
    }

    fclose(origine);
    fclose(destinazione);

    pthread_exit(NULL);
}
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        perror("Errore argomenti");
        exit(0);
    }
    pthread_t tLeggi, tCopia;

    origine = fopen(argv[1], "r");
    if (origine == NULL)
    {
        perror("Errore durante l'apertura del file");
        exit(0);
    }
    destinazione = fopen(argv[2], "w");
    if (destinazione == NULL)
    {
        perror("Errore durante l'apertura del file");
        exit(0);
    }
    pthread_create(&tCopia, NULL, &Copia, NULL);
    pthread_join(tCopia, NULL);
    printf("operazione completato\n");
    return 0;
}