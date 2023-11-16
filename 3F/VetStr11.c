/*Scrivere un programma in C che dopo aver inserito una stringa
crei 2 ulteriori stringhe contenenti, la prima i caratteri speciali
e la seconda lettere ordinate in ordine alfabetico*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int esci = 0, contSpe = 0, contAlfa = 0;
    char frase[40], carSpe[40], carAlfa[40], swap;
    printf("inserisci una frase\n");
    scanf("%s", frase);
    for (int i = 0; i < strlen(frase); i++)
    {
        if (frase[i] >= 'A' && frase[i] <= 'Z')
        {
            frase[i] = tolower(frase[i]);
        }
        if (frase[i] >= 'a' && frase[i] <= 'z')
        {
            carAlfa[contAlfa] = frase[i];
            contAlfa++;
        }
        else
        {
            carSpe[contSpe] = frase[i];
            contSpe++;
        }
    }
    for (int j = 0; j < contAlfa && !esci; j++)
    {
        esci = 1;
        for (int i = 0; i < contAlfa - 1 - j; i++)
        {
            if (carAlfa[i] > carAlfa[i + 1])
            {
                esci = 0;
                swap = carAlfa[i];
                carAlfa[i] = carAlfa[i + 1];
                carAlfa[i + 1] = swap;
            }
        }
    }
    if (contSpe != 0)
    {
        printf("i caratteri speciali sono: \n");
        for (int i = 0; i < contSpe; i++)
        {
            printf("%c ", carSpe[i]);
        }
    }
    else
    {
        printf("non ci sono caratteri speciali\n");
    }
    printf("\ni caratteri dell'alfabeto ordinato:\n ");
    for (int i = 0; i < strlen(carAlfa); i++)
    {
        printf("%c ", carAlfa[i]);
    }
    printf("\n\n");
    return 0;
}