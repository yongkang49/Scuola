#include <stdio.h>

int main(int argc, char *argv[])
{
    int n, v[100],somma = 0;
    float media;
    do
    {
        printf("quanti elementi voui inserire?\n");
        scanf("%d", &n);
    } while (n < 0 || n > 100);

    for (int i = 0; i < n; i++)
    {
        printf("inserisci un numero di posizione %d\n",(i+1));
        scanf("%d", &v[i]);
        somma = somma +v[i];
    }
    media = (float)somma / n;
    printf("il vettore inserito è il seguente");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("la somma dei valori è %d\n",somma);
    printf("la media dei valori è %f\n",media);
    return 0;
}