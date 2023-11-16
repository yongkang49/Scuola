#include <stdio.h>
#include <string.h>
int Sostituisci(char frase2[], char num, int p)
{
    frase2[p] = num;
}
int main(int argc, char *argv[])
{
    char frase[30];
    char frase2[30];
    int cont = 0;
    printf("inserisci una frase\n");
    scanf("%s", frase);
    for (int i = 0; i < strlen(frase); i++)
    {
        if (frase[i] >= 0 && frase[i] <= 9)
        {
            Sostituisci(frase2, frase[i], cont);
            cont++;
        }
    }
    printf("la frase con solo numeri è: ");
    for (int i = 0; i < strlen(frase2); i++)
    {
        printf("%c", frase2[i]);
    }
    return 0;
}