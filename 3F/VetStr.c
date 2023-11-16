/*Es 1
Scrivere un programma in C che dopo aver inserito N numeri interi in un vettore,
alterni (o scambi ) a due a due le posizioni del vettore. Esempio:
vettore inserito: 1,2,3,4  vettore alternato: 2,1,4,3.*/
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int N, swap;
    do
    {
        printf("quanti numeri vuoi inserire?\n(deve essere pari)\n");
        scanf("%d", &N);
    } while (N < 0 || N % 2 == 1);
    int vet[N];
    for (int i = 0; i < N; i++)
    {
        printf("inserisci il %d numero: ", i + 1);
        scanf("%d", &vet[i]);
    }
    for (int i = 0; i < N - 1; i++)
    {
        if (i % 2 == 0)
        {
            swap = vet[i];
            vet[i] = vet[i + 1];
            vet[i + 1] = swap;
        }
    }
    for (int i = 0; i < N; i++)
    {
        printf("%d", vet[i]);
    }
    printf("\n\n");
    return 0;
}