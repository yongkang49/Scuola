//Es1: dopo aver letto in input i valori della base e dell'altezza di un rettangolo calcolare il 2p e A. visualizzando a video i risultati.
//Es2: dopo aver letto in input il valore di un lato di un quadrato calcolare il 2p e A. visualizzando a video i risultati.

#include<stdio.h>
void main()
{
    float Aquad, Aret, lato, base, h,Pquad, Pret;
    //Es1
    printf("inserisci la base del rettangolo \n ");
    scanf("%f",&base);
    printf("inserisci l'altezza del rettangolo \n ");
    scanf("%f",&h);
    Pret = 2*(base+h);
    Aret = base*h;
    printf("\n");
    printf("Area del rettangolo è uguale a: %.2f\n", Aret);
    printf("perimetro del rettangolo è uguale a: %.2f\n", Pret);

    //Es2
    printf("inserisci il lato del quadrato: ");
    scanf("%f",&lato);
    Pquad = lato*4;
    Aquad = lato*lato;
    printf("\n");
    printf("Area del quadrato è uguale a: %.2f\n", Aquad);
    printf("perimetro del quadrato è uguale a: %.2f\n", Pquad);
}