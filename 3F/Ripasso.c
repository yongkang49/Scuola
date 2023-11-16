#include <stdio.h>
#include <limits.h>

int Massimo(int n[], int *p)
{
    int max = 0;
    for (int i = 0; i < (*p); i++)
    {
        if (n[i] > max)
        {
            max = n[i];
        }
    }
    return max;
}
//============================================
int Controllo(int n[], int *p, int numero)
{
    for (int i = 0; i < (*p); i++)
    {
        if (n[i] == numero)
        {
            return i;
        }
    }
    return -1;
}
//============================================
void ArrayInverso(int n[], int *p)
{
    for (int i = (*p) - 1; i >= 0; i--)
    {
        printf("%d\n", n[i]);
    }
}
//============================================
void InsertWith(int n[], int *p)
{
    int valido, num;
    printf("inserisci la posizione\n");
    scanf("%d", &valido);
    if (valido < (*p))
    {
        printf("inserisci il numero\n");
        scanf("%d", &num);
        n[valido] = num;
    }else
    {
        printf("posizione non valida\n");
    }
}
//============================================
void Ricerca(int n[], int *p)
{
    int change, valido;
    printf("inserisci il numero che vuoi cercare\n");
    scanf("%d", &change);
    valido = Controllo(n, p, change);
    if (valido == -1)
    {
        printf("il numero non esiste\n");
    }
    else
    {
        printf("il numero è presente nella posizione %d", valido);
    }
}
//============================================
void Elimina(int n[], int *p)
{
    int change, valido;
    printf("inserisci il numero che vuoi eliminare\n");
    scanf("%d", &change);
    valido = Controllo(n, p, change);
    if (valido == -1)
    {
        printf("il numero non esiste\n");
    }
    else
    {
        for (int i = valido; i < (*p) - 1; i++)
        {
            n[i] = n[i + 1];
        }
        (*p)--;
    }
}
//============================================
void Modifica(int n[], int *p)
{
    int change, valido;
    printf("inserisci il numero che vuoi cambiare\n");
    scanf("%d", &change);
    valido = Controllo(n, p, change);
    if (valido == -1)
    {
        printf("il numero non esiste\n");
    }
    else
    {
        printf("inserisci il nuovo numero\n");
        scanf("%d", &change);
        n[valido] = change;
    }
}
//============================================
void InsertCoda(int n[], int *p)
{
    printf("inserisci il numero che vuoi aggiungere\n");
    scanf("%d", &n[*p]);
    (*p)++;
}
//============================================
void Mostra(int n[], int *p)
{
    for (int i = 0; i < (*p); i++)
    {
        printf("%d\n", n[i]);
    }
}
//============================================
void Inserisci(int n[], int *p)
{
    int numero;
    for (int i = 0; numero != -1; i++)
    {
        printf("inserisci il %d numero\n", i + 1);
        scanf("%d", &numero);
        if (numero != -1 && numero > 0)
        {
            n[i] = numero;
            (*p)++;
        }
        else if (numero <= 0 && numero != -1)
        {
            printf("numero non valido\n");
            i--;
        }
    }
}
//============================================
int Menù(int n[], int *p)
{
    int opzione;
    
    printf("[1] per mostrare il contenuto dell'array\n[2] per inserire un elemento in coda\n[3] per modificare un elemento, se presente\n[4] per eliminare un elemento, se presente\n[5] per ricercare un elemento\n[6] per inserire un elemento in una certa posizione\n[7] per mostrare il contenuto dell'array all'inverso\n[8] per mostrare il valore massimo dell'array\n[0] per terminare\n");
    do
    {
        printf("inserisci quale operazione desideri fare\n");
        scanf("%d", &opzione);
    } while (opzione < 0 && opzione > 8);
    switch (opzione)
    {
    case 0:
        return 0;
        break;
    case 1:
        Mostra(n, p);
        break;
    case 2:
        InsertCoda(n, p);
    case 3:
        Modifica(n, p);
        break;
    case 4:
        Elimina(n, p);
        break;
    case 5:
        Ricerca(n, p);
        break;
    case 6:
        InsertWith(n, p);
        break;
    case 7:
        ArrayInverso(n, p);
        break;
    case 8:
        printf("il numero massimo è: %d\n", Massimo(n, p));
        break;
    }
    return 1;
}
//============================================
int main(int argc, char *argv[])
{
    int n[SHRT_MAX], last, esci = 1;
    Inserisci(n, &last);
    do
    {
        esci = Menù(n, &last);
    } while (esci);
    return 0;
}