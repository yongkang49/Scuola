/*9) Scrivere un programma in C che dopo aver inserito una stringa a piacere determini e o verifichi:

1)      Che contenga solo lettere;
2)      Crei 2 ulteriori stringhe che contengano: la 1° le lettere di posizione pari; la 2° le lettere di posizione dispari;
Inserita una 2° stringa determinare:
1)      Quale delle 2 è più lunga e più corta;
2)      Quale delle 2 stringhe contiene più vocali;
3)      Quale delle 2 stringhe contiene più consonanti.*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int esci, contPari = 0, contDis = 0;
    char frase1[40], frase2[40], letPari[20], letDis[20];
    do
    {
        esci = 0;
        printf("inserisci la prima frase\n");
        scanf("%s", frase1);
        frase1 = tolower(frase1);
        for (int i = 0; i < strlen(frase1); i++)
        {
            if (frase1[i] < 'a' || frase1[i] > 'z')
            {
                esci = 1;
            }
        }
    } while (esci);
    for (int i = 0; i < strlen(frase1); i++)
    {
        if (i % 2 == 0)
        {
            letPari[contPari] = frase1[i];
            contPari++;
        }
        else if (i % 2 == 1)
        {
            letDis[contDis] = frase1[i];
            contDis++;
        }
    }
    printf("le lettere nelle posizioni pari: %s\n", letPari);
    printf("le lettere nelle posizioni dispari: %s\n", letDis);
    //=========================================
    printf("inserisci la seconda frase\n");
    scanf("%s", frase2);
    if (strlen(frase1) > strlen(frase2))
    {
        printf("è più lunga la prima frase");
    }
    else if (strlen(frase1) < strlen(frase2))
    {
        printf("è più lunga la seconda frase");
    }
    else
    {
        printf("le due frasi sono di uguale lunghezza");
    }
    for (int i = 0; i < strlen(frase1); i++)
    {
        if (frase1[i] == 'a' || frase1[i] == 'o' || frase1[i] == 'e' || frase1[i] == 'i' || frase1[i] == 'u')
        {
            voc1++;
        }
        else
        {
            cons1++;
        }
    }
    for (int i = 0; i < strlen(frase2); i++)
    {
        if (frase2[i] == 'a' || frase2[i] == 'o' || frase2[i] == 'e' || frase2[i] == 'i' || frase2[i] == 'u')
        {
            voc2++;
        }
        else
        {
            cons2++;
        }
    }
    if (voc1 > voc2)
    {
        printf("contiene più vocali la frase 1\n\n");
    }
    else if (voc1 < voc2)
    {
        printf("contiene più vocali la frase 2\n\n");
    }
    else
    {
        printf("le due frasi hanno gli stessi numeri di vocali\n\n");
    }
    if (cons1 > cons2)
    {
        printf("contiene più consonanti la frase 1\n\n");
    }
    else if (cons1 < cons2)
    {
        printf("contiene più consonanti la frase 2\n\n");
    }
    else
    {
        printf("le due frasi hanno gli stessi numeri di consonanti\n\n");
    }
    return 0;
}