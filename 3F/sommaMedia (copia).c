// dopo aver letto n numeri reali calcola la somma dei numeri minori di 4 e maggiore di 8 estremi esclusi
#include <stdio.h>
void main()
{
    float num, somma = 0, media = 0;
    int n, cont = 0, nValidi=0;
    printf("quanti numeri vuoi inserire?\n(vengono sommati solo i numeri compresi tra 4 e 8)\n");
    scanf("%d", &n);
    while (cont != n)
    {
        cont++;
        printf("inserisci un numero\n");
        scanf("%f", &num);
        if (num <= 4 || num >= 8)
        {
            nValidi++;
            somma = somma + num;
        }
        media = somma / nValidi;
    }
    printf("la somma risulta: %.2f\n", somma);
    printf("la media risulta: %.2f\n", media);
}