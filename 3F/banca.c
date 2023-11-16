#include <stdio.h>
void main()
{
    float prezzo, sommatot = 0, somma = 0, mediatot = 0, media, min = 9999, max = 0;
    int cont1 = 0, cont2 = 0;
    do
    {
        cont1++;
        printf("inserisci l'importo dell'azione %d\n", cont1);
        scanf("%f", &prezzo);
        if (prezzo > max)
        {
            max = prezzo;
        }
        if (prezzo > 0 && prezzo < min)
        {
            min = prezzo;
        }
        if (prezzo > 2, 50 && prezzo < 3, 50)
        {
            cont2++;
            somma = somma + prezzo;
        }
        sommatot = sommatot + prezzo;
    } while (prezzo > 0);
    media = somma / (cont2-1);
    mediatot = sommatot / (cont1-1);
    printf("la somma dei prezzi compresi tra 2,50 e 3,50 è pari a %.2f\n",somma);
    printf("la somma totale è pari a %.2f\n",sommatot);
    printf("la media dei prezzi compresi tra 2,50 e 3,50 è pari a %.2f\n",media);
    printf("la media totale è pari a %.2f\n",mediatot);
    printf("il prezzo minimo è %.2f\n",min);
    printf("il prezzo massimo è %.2f\n",max);
}