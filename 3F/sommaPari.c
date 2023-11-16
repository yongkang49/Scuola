
#include <stdio.h>
void main()
{
    int resto, num1,i=0,n;
    float somma=0;
    printf("Es2 \n");
    printf("quanti numeri vuoi inserire? vengono sommati solo i numeri pari");
    scanf("%d", &n);
    do
    {
        i++;
        printf("inserisci il %d numero \n",i);
        scanf("%d", &num1);
        resto = num1 %2;
        if (resto==0)
        {
           somma = somma + num1;
        }
        n--;
    } while (n != 0);
    printf("\n");
    printf("la somma risulta: %.2f \n", somma);
}