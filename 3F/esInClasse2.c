#include <stdio.h>
void main()
{
    float numero1, numero2;
    printf("inserisci il primo numero \n");
    scanf("%f", &numero1);
    printf("inserisci il secondo numero \n");
    scanf("%f", &numero2);
    if (numero1 > numero2)
    {
        printf("il primo numero è maggiore del secondo");
    }
    else
    {
        if (numero1 < numero2)
        {
            printf("il primo numero è minore del secondo");
        }
        else
        {  
            printf("i numeri sono uguali");
        }
        printf("\n");
    }
}