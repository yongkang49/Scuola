/*Es2
Scrivere un programma in C che dopo aver inserito una stringa ed un carattere
da linea comando , elimini il carattere inserito dalla stringa stessa (se esistente).*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("argomento errato\n");
        exit(0);
    }
    char str[30], car;
    int cont = 0;
    strcpy(str, argv[1]);
    car = argv[2];
    printf("stringa dopo l'eliminazione: ");
    for (int i = 0; i < strlen(str); i++)
    {
        if (car != str[i])
        {
            printf("%c", str[i]);
        }
    }
    printf("\n");
    return 0;
}