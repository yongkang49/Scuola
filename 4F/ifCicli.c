#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n[5], lim1, lim2;
    double somma = 0;
    if (argc = !3)
    {
        printf("Errore argomenti\n");
        exit(0);
    }
    lim1 = atoi(argv[1]);
    lim2 = atoi(argv[2]);
    for (int i = 0; i < 5; i++)
    {
        printf("Inserisci il %d numero\n", i + 1);
        scanf("%d", &n[i]);
        if (n[i] > lim1 && n[i] < lim2)
        {
            somma += n[i];
        }
    }
    printf("la somma dei numeri compresi tra %d e %d è uguale a %f\n", lim1, lim2, somma);
    return 0;
}