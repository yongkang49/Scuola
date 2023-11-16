
// scrivere una programma che effettui la somma di due numeri interi
#include<stdio.h>
void main()
{
    int n1, n2 = 8, somma,diff,prod,contatore=0; // dichiarazioni di variabili e n2=8 è un'inizializzazione
    float var1, var2, somma2,quoz;
    n1 = 5;                // assegnazione
    somma = n1 + n2;
    printf("la somma e' %d : \n", somma); // d=decimal f=numeri reali
    var1 = 3.50;
    var2 = 2.75;
    somma2 = var1 + var2;
    printf("la somma e' %.2f : \n", somma2);//.2 serve per indicare quanti decimali si vuole
    quoz =(float) n1/n2; //casting
    printf("il quoziente e' %.2f : \n", quoz);
    diff = n1-n2;
    printf("la differenza e' %d : \n", diff);
    prod=n1*n2;
    printf("la differenza e' %d : \n", prod);
    //contatore=contatore+1;
    do
    {
        contatore++;
        printf("il contatore e' %d : \n", contatore);
    } while (contatore!=10);
    
    }