#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BLOCK_DIM 1024

int main(int argc, char *argv[])
{
    FILE *file;
    unsigned char buffer[BLOCK_DIM];
    int n;
    int fifo;
    if (argc != 2)
    {
        printf("Uso: %s file\r\n", argv[0]);
        return 0;
    }
    // apertura in lettura FIFO
    fifo = open("my_fifo", O_RDONLY);
    if (fifo < 0)
    {
        printf("Errore apertura FIFO es2\r\n");
        return 0;
    }
    // apertura in scrittura file di destinazione
    file = fopen(argv[1], "wb");
    if (file == NULL)
    {
        printf("Errore apertura file es2\"%s\"\r\n", argv[1]);
        close(fifo);
        return 0;
    }
    // estrazione dalla FIFO dei dati a blocchi e scrittura nel file di destinazione
    while ((n = read(fifo, buffer, sizeof(buffer))) > 0)
    {
        fwrite(buffer, 1, n, file);
    }
    close(fifo);  // chiusura FIFO
    fclose(file); // chiusura file
    return 1;
}
