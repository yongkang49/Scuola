/*Progettare un algoritmo che effettui le seguenti operazioni:
• continui a leggere da tastiera una serie di terne di valori interi A ,
B e C finchè non vengono inseriti dei valori tali per cui A + B < C
• conteggi il numero di volte in cui la differenza tra A e B è pari, dispari, e quando è nulla
• prima di terminare, visualizzi il valore dei valori conteggiati*/
#include <stdio.h>
void main()
{
    int A, B, C, pari = 0, dispari = 0, nullo = 0, ciclo = 0;
    do
    {
        ciclo++;
        printf("ciclo %d\n", ciclo);
        printf("inserisci il primo numero\n");
        scanf("%d", &A);
        printf("inserisci il secondo numero\n");
        scanf("%d", &B);
        printf("inserisci il terzo numero\n");
        scanf("%d", &C);
        if (A - B == 0)
        {
            nullo++;
        }
        else
        {
            if ((A - B) % 2 == 1)
            {
                dispari++;
            }
            else
            {
                pari++;
            }
        }
    } while ((A + B) > C);
    printf("A-B è risultato pari %d volte\n", pari);
    printf("A-B è risultato dispari %d volte\n", dispari);
    printf("A-B è risultato nullo %d volte\n", nullo);
}