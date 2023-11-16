/*Scrivere un programma in c che dopo aver acquisito da tastiera un elenco di prezzi relativi alle vendite di N
prodotti ed il relativo incremento del prezzo secondo una percentuale, visualizzi a video:
1) Il prezzo incrementato per ogni inserimento effettuato;
2) Il totale e la media dei prezzi incrementati;
3) La media dei prezzi incrementati maggiori di 50€;*/
#include <stdio.h>
void main()
{
    float prezzo, pIncrementato, percentuale, tot = 0, media, mediaIncrementati, somma = 0;
    int N, contatore1 = 0, contatore2 = 0;
    printf("quanti prodotti desideri comprare?\n");
    scanf("%d", &N);
    // dato che inserisce l'utente il numero di oggeti si usa un ciclo definito
    for (int i = 1; i <= N; i++)
    {
        printf("inserisci il prezzo del %d prodotto\n", i);
        scanf("%f", &prezzo);
        printf("inserisci il percentuale d'incremento per il %d prodotto\n", i);
        scanf("%f", &percentuale);
        printf("il prezzo iniziale: %.2f\n", prezzo);
        printf("incremento è del %f percento\n", percentuale);
        pIncrementato = prezzo + prezzo * percentuale / 100;
        printf("il prezzo incrementato è pari a: %.2f\n", pIncrementato);
        // verifico i prezzi se sono maggiori o minori del 50
        if (pIncrementato > 50)
        {
            somma = somma + pIncrementato;
            contatore1++;
        }
        tot = tot + pIncrementato;
        contatore2++;
    }
    //faccio le somme e medie di vari prezzi
    media = tot / contatore2;
    mediaIncrementati = somma / contatore1;
    printf("il totale dei prezzi è pari a: %.2f\n", tot);
    printf("la media dei prezzi incrementati sono: %.2f\n", media);
    printf("ci sono %d prodotti con il prezzo maggiore a 50", contatore1);
    printf(" , equivalgono a %.2f", somma);
    printf(" e la media è pari a %.2f \n", mediaIncrementati);
}