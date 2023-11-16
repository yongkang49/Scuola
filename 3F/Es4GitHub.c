/*Progettare un algoritmo che effettui la lettura da tastiera di una serie
di coppie di valori numerici reali (sia positivi che negativi che zero).
Per ciascuna coppia, l’algoritmo deve calcolare e stampare il valore
della radice quadrata del rapporto tra il valore maggiore e quello
minore dei due. Il programma termina quando vengono inseriti dei valori
che non permettono di svolgere il calcolo nel dominio dei numeri reali.
Il programma prima di terminare si richiede di stampare un messaggio che indichi la
ragione per cui non è stato possibile svolgere il calcolo.*/
#include <stdio.h>
#include <math.h>
void main()
{
    float num1, num2, rapporto;
    double radice;
    do
    {
        printf("inserisci il primo numero\n");
        scanf("%f", &num1);
        printf("inserisci il secondo numero\n");
        scanf("%f", &num2);
        if (num1 >= num2)
        {
            rapporto = num2 / num1;
        }
        else
        {
            if (num2 > num1)
            {
                rapporto = num1 / num2;
            }
        }
        if (rapporto>0)
        {
            radice = sqrt(rapporto);
            printf("il radice è pari a %.2f\n", radice);
        }
    } while (rapporto>0);
    
}