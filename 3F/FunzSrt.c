#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int i = 0, lung = 0;
    char str1[20], str2[20], str3[40];
    printf("inserisci la stringa\n");
    scanf("%s", str1);
    lung = strlen(str1);
    printf("la lunghezsza della stringa: %d\n", lung);
    printf("inserisci la seconda stringa\n");
    scanf("%s", str2);
    lung = strlen(str2);
    printf("la lunghezsza della stringa: %d\n", lung);
    // confronto tra due stringhe se sono uguali torna 0
    if (strcmp(str1, str2) == 0)
    {
        printf("le due stringhe sono uguali\n");
    }
    else
    {
        printf("le due stringhe sono diverse\n");
    }
    // concatena str2 con str1
    strcat(str1, str2);
    printf("%s\n", str1);
    // copia la str2 in str1
    strcpy(str1, str2);
    printf("la prima stringa è diventata %s\n\n", str1);
    return 0;
}