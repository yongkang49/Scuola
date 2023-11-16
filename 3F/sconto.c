#include <stdio.h>
void main(){
    int risposta;
    float spesa;
    const float sconto1=0.90,sconto2=0.80,sconto3=0.70;
    do
    {
        printf("inserisci l'importo \n");
        scanf("%f",&spesa);
        while (spesa<0)
        {
            printf("spesa non valida, prova di nuovo \n");
            scanf("%f",&spesa);
        }
        if (spesa<500)
        {
            spesa= spesa*sconto1;
        }else
        {
            if (spesa<1000)
            {
                spesa = spesa * sconto2;
            }else
            {
                spesa = spesa * sconto3;
            } 
        }
        
        printf("la spesa scontata è pari a %.2f\n",spesa);
        printf("desideri inserire un nuovo importo? (1/0)\n");
        scanf("%d",&risposta);
    } while (risposta==1);
    
    
    
}