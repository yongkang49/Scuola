/*Progettare un algoritmo che risolva il seguente problema. Si richieda
all’utente di inserire una serie di terne di dati numerici (A, B, C).
Il programma deve terminare quando uno dei valori inseriti è minore di
zero. Si scartino le terne nelle quali i valori non sono in ordine
strettamente crescente, ovvero quelle terne per cui non valga A < B < C.
Su tutte le terne non scartate si calcoli il massimo e il minimo dei
valori inseriti. Si stampino a video tali valori massimi e minimi prima
di terminare il programma.*/
#include <stdio.h>
void main()
{
    int a, b, c, min = 99999, max = 0;

    do
    {
        printf("inserisci il 1 numero\n");
        scanf("%d", &a);
        printf("inserisci il 2 numero\n");
        scanf("%d", &b);
        printf("inserisci 3 numero\n");
        scanf("%d", &c);
        if (a < b && b < c)
        {
            if (a < min)
            {
                min = a;
            }
            if (c > max)
            {
                max = c;
            }
        }
        else
        {
            printf("numeri non validi\n");
        }
    } while (a >= 0 && b >= 0 && c >= 0);

    printf("il numero più grande: %d\n", max);
    printf("il numero più piccolo: %d\n", min);
}