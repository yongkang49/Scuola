/*Es 3
Scrivere un programma in C che dopo aver inserito N numeri interi in un vettore,
determini:
1) il massimo ed il minimo dei numeri pari inseriti;
2) il massimo ed il minimo dei numeri dispari inseriti;
3) le posizioni di inserimento dei numeri precedentemente determinati.*/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int arr[100], N, i = 0, maxP = 0, minP = __INT32_MAX__, maxD = 0, minD = __INT32_MAX__;
    int posMaxP, posMinP, posMaxD, posMinD;
    do
    {
        printf("quanti numeri voui inserire?\n");
        scanf("%d", &N);
    } while (N <= 0);
    for (i = 0; i < N; i++)
    {
        printf("inserisci il numero: ");
        scanf("%d", &arr[i]);
        if (arr[i] > maxP && arr[i] % 2 == 0)
        {
            maxP = arr[i];
            posMaxP = i;
        }
        if (arr[i] < minP && arr[i] % 2 == 0)
        {
            minP = arr[i];
            posMinP = i;
        }
        if (arr[i] > maxD && arr[i] % 2 == 1)
        {
            maxD = arr[i];
            posMaxD = i;
        }
        if (arr[i] < minD && arr[i] % 2 == 1)
        {
            minD = arr[i];
            posMinD = i;
        }
    }
    printf("il numero massimo pari è %d, presente nella posizione %d\n", maxP, posMaxP + 1);
    printf("il numero massimo dispari è %d, presente nella posizione %d\n", maxD, posMaxD + 1);
    if (minP == __INT32_MAX__)
    {
        printf("non è presente il numero minimo pari\n");
    }
    else
    {
        printf("il numero minimo pari è %d, presente nella posizione %d\n", minP, posMinP);
    }
    if (minD == __INT32_MAX__)
    {
        printf("non è presente il numero minimo dispari\n");
    }
    else
    {
        printf("il numero minimo dispari è %d, presente nella posizione %d\n\n", minD, posMinD);
    }
    return 0;
}