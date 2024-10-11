#include <stdio.h>
#include <math.h>
#include <time.h>

#define NDEFAULT 10
void inserisci(int n[], int *i)
{
    printf("inserisci un numero\n");
    scanf("%d", &n[*i]);
    printf("%d", n[*i]);
    (*i)++;
}
void visualizza(int n[], int *i)
{
    for (int j = 0; j < *i; j++)
    {
        printf("%d\n", n[j]);
    }
}
void visualizzaInv(int n[], int *i)
{
    for (int j = *i; j < 0; j--)
    {
        printf("%d\n", n[j]);
    }
}
int somma(int n[], int *i)
{
    int somma = 0;
    for (int j = 0; j < *i; j++)
    {
        somma += n[j];
    }
    return somma;
}
int media(int n[], int *i)
{
    double media = somma(n, &(*i)) / (*i);
    return media;
}
void visualizzaPari(int n[], int *i)
{
    for (int j = 0; j < *i; j++)
    {
        if (n[j] % 2 == 0)
        {
            printf("%d\n", n[j]);
        }
    }
}
void visualizzaDispari(int n[], int *i)
{
    for (int j = 0; j < *i; j++)
    {
        if (n[j] % 2 == 1)
        {
            printf("%d\n", n[j]);
        }
    }
}
int ricerca(int n[], int *i, int num)
{
    int temp = 0;
    for (int j = 0; j < *i; j++)
    {
        if (n[j] == num)
        {
            temp = j;
        }
    }
    return temp;
}

void elimina(int n[], int *i, int num)
{
    for (int j = 0; j < (*i) - 1; j++)
    {
        if (n[j] == num)
        {
            n[j] = n[j + 1];
        }
    }
}
void arterni(int n[], int *i)
{
    int temp = 0;
    for (int j = 0; j < (*i) - 1; j += 2)
    {
        temp = n[j];
        n[j] = n[j + 1];
        n[j + 1] = temp;
    }
}
void ordina(int n[], int *i)
{
    int temp;
    for (int j = 0; j < *i; j++)
    {
        for (int k = 0; k < *i; k++)
        {
            if (n[j] > n[k + j])
            {
                temp = n[k + j];
                n[k + j] = n[j];
                n[j] = temp;
            }
        }
    }
}
int richiedi()
{
    int o;
    printf("inserisci il numero dell'opzione:\n");
    scanf("%d", &o);
    return o;
}
void menu()
{
    printf("1-Inserisci un numero\n");
    printf("2-Visualizzare i numeri\n");
    printf("3-Visualizzare array invertito\n");
    printf("4-Visualizza somma e media\n");
    printf("5-Visualizzare i numeri pari\n");
    printf("6-Visualizzare i numeri dispari\n");
    printf("7-Ricercare un numero\n");
    printf("8-Eliminare un numero\n");
    printf("9-Alternare i numero\n");
    printf("10-Ordinare i numero\n");
    printf("11-esci\n");
}
void main()
{
    int numeri[NDEFAULT], opzione;
    int esci = 1;
    int indice = 0;
    int eliRic;
    do
    {
        menu();
        opzione = richiedi();
        switch (opzione)
        {
        case 1:
            inserisci(numeri, &indice);
            break;
        case 2:
            visualizza(numeri, &indice);
            break;
        case 3:
            visualizzaInv(numeri, &indice);
            break;
        case 4:
            printf("somma è %d \n", somma(numeri, &indice));
            printf("la media è %d\n", media(numeri, &indice));
            break;
        case 5:
            visualizzaPari(numeri, &indice);
            break;
        case 6:
            visualizzaDispari(numeri, &indice);
            break;
        case 7:
            printf("inserisci numero da ricercare \n");
            scanf("%d", &eliRic);
            printf("il numero ricercato è presente nella posizione %d", ricerca(numeri, &indice, eliRic));
            break;
        case 8:
            printf("inserisci numero da eliminare \n");
            scanf("%d", &eliRic);
            elimina(numeri, &indice, eliRic);
            printf("numero eliminato");
            break;
        case 9:
            arterni(numeri, &indice);
            break;
        case 10:
            ordina(numeri, &indice);
            break;
        case 11:
            esci = 0;
            break;
        }
    } while (esci);
}