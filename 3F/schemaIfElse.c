#include <stdio.h>
void main()
{
    //Es1
    printf("Es 1");
    printf("\n");
    int numero1=0, numero2, resto;
    printf("inserisci il primo numero \n");
    scanf("%d", &numero1);
    resto = numero1 % 2;
    if (resto == 0)
    {
        printf("il numero è pari");
    }
    else
    {   
        printf("il numero è dispari");
    }
    printf("\n");
    printf("Es 2");
    printf("\n");

    //Es2
    float num1,num2,num3;
    printf("inserisci il primo numero \n");
    scanf("%f", &num1);
    printf("inserisci il secondo numero \n");
    scanf("%f", &num2);
    printf("inserisci il terzo numero \n");
    scanf("%f", &num3);
    if (num1 > num2 && num1>num3)
    {
        printf("il primo numero è il numero maggiore");
    }
    else
    {
        if (num1 < num2 && num2>num3)
        {
            printf("il secondo numero è il numero maggiore");
        }
        else
        {  
            printf("il terzo numero è il numero maggiore");
        }
        printf("\n");
    }
}