#include <stdio.h>
#include <math.h>
#include <string.h>

#define NCar 20

int controlloLettera(char stringa[])
{
	int cont = 0;
	for (int i = 0; i < strlen(stringa); i++)
	{
		if (!(stringa[i] >= 65 && stringa[i] <= 90) || !(stringa[i] >= 97 && stringa[i] <= 122))
		{
			cont++;
		}
	}
	return cont;
}
int contLet(char stringa[], char car)
{
	int cont = 0;
	for (int i = 0; i < strlen(stringa); i++)
	{
		if (stringa[i] == car)
		{
			cont++;
		}
	}
	return cont;
}
void separa(char stringa[], char dis[], char par[])
{
	int contP = 0,contD = 0;
	for (int i = 0; i < strlen(stringa); i++)
	{
		if (i % 2 == 0)
		{
			par[contP] = stringa[i];
			contP++;
		}
		else
		{
			dis[contD] = stringa[i];
			contD++;
		}
	}
}
void stampa(char str[])
{
	for(int i = 0; i < strlen(str); i++)
	{
		printf("%s", &str[i]);
	}
	printf("\n");
}
void main()
{
	char stringa[NCar];
	char car;
	int lenDis;
	int cont = 0;
	printf("inserisci una stringa\n");
	scanf("%s", stringa);
	if (controlloLettera(stringa) == 0)
	{
		printf("la stringa contiene solo lettere\n");
	}
	else
	{
		printf("la stringa contiene anche altri tipi di caratteri\n");
	}
	
	printf("inserisci una lettera di ricerca\n");
	scanf("%s", &car);
	cont = contLet(stringa, car);
	if (cont > 0)
	{
		printf("la stringa contiene %d '%c'\n", cont, car);
	}
	
	char copiaPari[strlen(stringa)/2];
	if(strlen(stringa) % 2 == 1)
	{
		lenDis = strlen(stringa)/2 + 1;
	}
	else
	{
		lenDis = strlen(stringa)/2;
	}
	char copiaDispari[lenDis];
	separa(stringa, copiaDispari, copiaPari);
	printf("Copia posizione pari: ");
	stampa(copiaPari);
	printf("Copia posizione dispari: ");
	stampa(copiaDispari);
	
	char stringa2[NCar];
	printf("inserisci una seconda stringa\n");
	scanf("%s", stringa2);
	if(strlen(stringa) > strlen(stringa2))
	{
	    printf("la prima stringa è piu lunga\n");
	}
	else
	{
	    printf("la seconda stringa è piu lunga\n");
	}
}