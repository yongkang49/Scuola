#include <stdio.h>
#include <string.h>
#define MAX_AUTO 100 // Definizione della struttura Auto
typedef struct Auto
{
    char ModelloAuto[50];
    char Marca[50];
    int Cilindrata;
    float Prezzo;
    int AnnoImmatricolazione;
}t_auto; 
void TrovaPrezzoMassimoMinimo(t_auto auti[], int n)
{
    int iMax = 0, iMin = 0;
    for (int i = 1; i < n; i++)
    {
        if (auti[i].Prezzo > auti[iMax].Prezzo)
        {
            iMax = i;
        }
        if (auti[i].Prezzo < auti[iMin].Prezzo)
        {
            iMin = i;
        }
    }
    printf("Auto con il prezzo più alto:\n");
    printf("Modello: %s, Prezzo: %.2f\n", auti[iMax].ModelloAuto, auti[iMax].Prezzo);
    printf("Auto con il prezzo più basso:\n");
    printf("Modello: %s, Prezzo: %.2f\n", auti[iMin].ModelloAuto, auti[iMin].Prezzo);
} 
void OrdinaPerAnno(t_auto auti [], int n)
{
    t_auto temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (auti [j].AnnoImmatricolazione > auti [j + 1].AnnoImmatricolazione)
            {
                temp = auti [j];
                auti [j] = auti [j + 1];
                auti [j + 1] = temp;
            }
        }
    }
    printf("\nAuto ordinate per anno di immatricolazione:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Modello: %s, Anno: %d\n", auti[i].ModelloAuto, auti[i].AnnoImmatricolazione);
    }
}
void VisualizzaAutoPerPrezzo(t_auto auti[], int n, float min)
{
    int trovate = 0;
    printf("\nAuto con prezzo maggiore o uguale a %.2f:\n", min);
    for (int i = 0; i < n; i++)
    {
        if (auti[i].Prezzo >= min)
        {
            printf("Modello: %s, Prezzo: %.2f\n", auti[i].ModelloAuto, auti[i].Prezzo);
            trovate = 1;
        }
    }
    if (!trovate)
    {
        printf("Nessuna auto trovata con un prezzo superiore o uguale a %.2f.\n", min);
    }
}
int main()
{
    t_auto auti[MAX_AUTO];
    int n;
    printf("Inserisci il numero di auto: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nInserisci i dati dell'auto %d:\n", i + 1);
        printf("Modello: ");
        scanf("%s", auti[i].ModelloAuto);
        printf("Marca: ");
        scanf("%s", auti[i].Marca);
        printf("Cilindrata: ");
        scanf("%d", &auti[i].Cilindrata);
        printf("Prezzo: ");
        scanf("%f", &auti[i].Prezzo);
        printf("Anno di immatricolazione: ");
        scanf("%d", &auti[i].AnnoImmatricolazione);
    } 
    TrovaPrezzoMassimoMinimo(auti, n); 
    OrdinaPerAnno(auti, n);            
    float prezzoMinimo;
    printf("\nInserisci il prezzo minimo per visualizzare le auto: ");
    scanf("%f", &prezzoMinimo);
    VisualizzaAutoPerPrezzo(auti, n, prezzoMinimo);
    return 0;
}