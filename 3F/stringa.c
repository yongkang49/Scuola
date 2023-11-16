#include <stdio.h>
int main()
{
    /*char carattere;
    printf("inserisci il carattere\n");
    //scanf("%c", &carattere);
    carattere = getchar();
    //printf("hai inserito il seguente carattere: %c\n", carattere);
    putchar(carattere);
    printf("il codice ascii del carattere inserito %d\n",carattere);*/

    char stringa[20];
    int i=0;
    printf("inserisci una stringa\n");
    scanf("%s", &stringa);
    printf("hai inserito una stringa %s\n", stringa);
    while(stringa[i] != '\0')
    {
        i++;
    }
    printf("la stringa è lunga %d\n",i);
}
    