#include <stdio.h>
int main()
{
    int i = 0, cons = 0, voc = 0, lung = 0;
    char str[20];
    printf("inserisci la stringa\n");
    scanf("%s", str);
    while (str[i] != '\0')
    {
        i++;
    }
    lung = i;
    for (int i = 0; i < lung; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'o' || str[i] == 'i' || str[i] == 'u')
        {
            voc++;
        }
        else if ((str[i] != 'a' || str[i] != 'e' || str[i] != 'o' || str[i] != 'i' || str[i] != 'u') && (str[i] > 97 && str[i] < 122))
        {
            cons++;
        }
    }
    printf("le consonanti presenti nella stringa sono: %d\n", cons);
    printf("le vocali presenti nella stringa sono: %d\n", voc);
    return 0;
}