#include <stdio.h>
void main()
{
    float num1, num2, rapporto;
    do
    {
        printf("inserisci il primo numero\n");
        scanf("%f", &num1);
        printf("inserisci il secondo numero\n");
        scanf("%f", &num2);
        if (num1 != 0 && num2 != 0)
        {

            if (num1 >= num2)
            {
                rapporto = num2 / num1;
                printf("il rapporto tra il numero minore e il numero maggiore è pari a %.2f\n", rapporto);
            }
            else
            {
                if (num2 > num1)
                {
                    rapporto = num1 / num2;
                    printf("il rapporto tra il numero minore e il numero maggiore è pari a %.2f\n", rapporto);
                }
            }
        }
        else
        {
            printf("uno dei due valori o entrambi sono uguali a zero\nprogramma terminata\n");
        }
    } while (num1 != 0 && num2 != 0);
}