/*Es 10
Scrivere un programma in C che dopo aver inserito 2 stringhe visualizzi a video le lettere comuni ad entrambe.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char frase1[40], frase2[40], comuni[20], cont = 0;
    int esci = 0, presente = 0;
    printf("inserisci la prima frase\n");
    scanf("%s", frase1);
    printf("inserisci la seconda frase\n");
    scanf("%s", frase2);
    for (int i = 0; i < strlen(frase2); i++)
    {
        esci = 0;
        frase2[i] = tolower(frase2[i]);
        for (int j = 0; j < strlen(frase1) && !esci; j++)
        {
            frase1[j] = tolower(frase1[j]);
            if (frase1[j] == frase2[i])
            {
                presente = 0;
                for (int k = 0; k < strlen(comuni) && !presente; k++)
                {
                    if (frase1[j] == comuni[k])
                    {
                        presente = 1;
                    }
                }
                if (!presente)
                {
                    comuni[cont] = frase1[j];
                    cont++;
                }
                    esci = 1;
            }
        }
    }
    printf("ci sono %d lettere in comune e sono: %s\n\n", cont, comuni);
    return 0;
}