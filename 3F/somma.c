// Scrivere un programma in c che dopo aver richiesto all'utente quanti numeri inserire ne calcola la somma 
#include <stdio.h>
void main()
{
    float num, somma = 0,media;
    int n,i=0;
    printf("quanti numeri vuoi inserire?");
    scanf("%d", &n);
    do
    {
        i++;
        printf("inserisci il %d numero \n",i);
        scanf("%f", &num);
        somma = somma + num;
        n--;
    } while (n != 0);
    printf("\n");
    printf("la somma risulta: %.2f \n", somma);
    printf("la media risulta: %.2f \n", somma/i);
}