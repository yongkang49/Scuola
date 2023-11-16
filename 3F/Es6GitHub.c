/*Progettare un algoritmo che effettui le seguenti operazioni:
• legga da tastiera una coppia di valori interi A e B con A<B;
• continui a leggere da tastiera una serie di valori interi, terminando
quando il valore letto è al di fuori dell’intervallo [A, B];
• conteggi la media dei valori letti;
• prima di terminare, stampi il valore calcolato.*/
#include <stdio.h>
void main()
{
    int a, b, n, cont;
    float media = 0, somma = 0;
    do
    {
        printf("inserisci il primo numero\n");
        scanf("%d", &a);
        printf("inserisci il secondo numero\n");
        scanf("%d", &b);
    } while (a > b);
    do
    {
        printf("inserisci un numero\n");
        scanf("%d", &n);

        if (n >= a && n <= b)
        {
            somma = somma + n;
            cont++;
        }
    } while (n >= a && n <= b);
    media = (double)somma / (double)cont;

    printf("la media è: %f\n", media);
}