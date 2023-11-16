#include <stdio.h>
void main()
{

    float somma = 0, media;
    int n,i=0,i1=0,num;
    printf("quanti numeri vuoi inserire?");
    scanf("%d", &n);
    do
    {
        i++;
        printf("inserisci il %d numero \n",i);
        scanf("%d", &num);
        if (num>5 && num%2==0)
        { 
            i1++;
           somma = somma + num;
        }
        n--;
    } while (n != 0);
    media= somma / i1;
    printf("\n");
    printf("la somma risulta: %.2f \n", somma);
    printf("la media risulta: %.2f \n", media);
}