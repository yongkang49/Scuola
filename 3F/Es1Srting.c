#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char str[30], car;
    int cont = 0;
    printf("inserisci una stringa\n");
    scanf("%s", str);
    printf("inserisci un caratere\n");
    scanf("%s", &car);
    for (int i = 0; i <strlen(str); i++)
    {
        if (str[i] == car)
        {
            cont++;
        }
    }
    printf("il carattere %c è presente %d volte\n\n", car, cont);
    return 0;
}