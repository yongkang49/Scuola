#include <stdio.h>
#include <string.h>

int Controlla(char frase[])//funzione che serve per controllare se i caratteri sono validi
{
    int valido = 0;//variabile "booleano" 
    for (int i = 0; i < strlen(frase) && !valido; i++)//ciclo per controllare ogni carattere fino alla fine della stringa
    {
        if (frase[i] >= 'a' && frase[i] <= 'z' || frase[i] >= '0' && frase[i] <= '9' || frase[i] >= 'A' && frase[i] <= 'Z')//per controllare se i caratteri sono validi
        {
            valido = 0;//faccio continuare il ciclo
        }
        else
        {
            valido = 1;//faccio interrompere il ciclo 
        }
    }
    return valido;//torno nel main con il valore che assume valido
}
int Diversi(char frase[])//funzione che serve per controllare se sono presenti dei caratteri uguali
{
    int valido = 0;//variabile "booleano" 
    for (int i = 0; i < strlen(frase) && !valido; i++)//ciclo esterno che prende il carattere da confrontare 
    {
        for (int j = 0; j < strlen(frase) && !valido; j++)//ciclo interno che serve per prendere tutti i caratteri della stringa
        {
            if (i != j)//se due indici sono uguali è ovvio che sono uguali quindi devono essere diversi
            {
                if (frase[i] == frase[j])//confronto i due carrateri presi(che hanno indici per forza diversi)
                {
                    valido = 1;//se sono uguali interronpo il ciclo
                }
            }
        }
    }
    return valido;//torno nel main con il valore che assume valido(1 o 0)
}
int main(int argc, char *argv[])
{
    char frase[40];
    do
    {
        printf("inserisci una frase con soli caratteri e numeri\n");//chiedo di inserire una frase
        scanf("%s", frase);//memorizzo la frase
    } while (Controlla(frase));//chiamo la funzione Controlla che mi torno 1 o 0
    if(Diversi(frase))//chiamo la funzione Diversi che mi torno 1 o 0
    {
        printf("la frase contiene caratteri uguali: %s\n\n", frase);//stampo a video questa frase se Divide mi torna 1 
    }
    else
    {
        printf("la frase non contiene caratteri uguali: %s\n\n", frase);//stampo a video questa frase se Divide mi torna 0
    }
    return 0;//fine programma
}