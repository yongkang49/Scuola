/*Progettare un algoritmo che effettui le seguenti operazioni:
• continui a leggere da tastiera due valori numerici, fermandosi quando uno dei due numeri è
0 (zero)
• per ogni coppia di numeri letti:
◦ calcoli il prodotto dei due numeri e ne stampi il valore
◦ sommi il prodotto calcolato ad una variabile che memorizzi la somma di tutti i prodotti
• all’uscita del ciclo, stampi il valore della somma*/
#include <stdio.h>
void main()
{
    float num1, num2, prodotto, somma = 0;
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
                prodotto = num2 * num1;
                printf("il prodotto tra il numero minore e il numero maggiore è pari a %.2f\n", prodotto);
            }
            else
            {
                if (num2 > num1)
                {
                    prodotto = num1 * num2;
                    printf("il prodotto tra il numero minore e il numero maggiore è pari a %.2f\n", prodotto);
                }
            }
            somma = somma + prodotto;
        }
        else
        {
            printf("uno dei due valori o entrambi sono uguali a zero\nprogramma terminata\n");
        }
    } while (num1 != 0 && num2 != 0);
    printf("la somma dei prodotti inseriti è pari a %.2f\n", somma);
}