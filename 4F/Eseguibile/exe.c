#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Sono il processo in originale: il mio PID=%d\n", getpid());
    execl("./es1", "ciao", "buongiorno\n", NULL); // finisce questo programma se è andata a buon fine
                                                  // crea un nuovo processo con lo stesso pid
    printf("Se leggi questo messaggio, significa che la chiamata ad exec non è andata a buon fine\n");
    // quindi legge questo messaggio solo se c'è un errore
    return 0;
}