#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char buffer[200];
enum categorie
{
	Narrativa,
	Avventura,
	Scienza,
	Giallo,
	Saggistica
} categoria;
typedef struct Libri
{
	char titolo[50];
	char autore[30];
	int anno;
	double prezzo;
	enum categorie categoria;
}t_libro;

int PopolaLibri(FILE *lista, t_libro libri[])
{
	int i = 0;
	char *temp;
    while (fgets(buffer, sizeof(buffer), lista))
    {
        temp = strtok(buffer, ",");
        strcpy(libri[i].titolo, temp); //Titolo
        temp = strtok(NULL, ",");
        strcpy(libri[i].autore, temp); //Autore
        temp = strtok(NULL, ",");
        libri[i].anno = atoi(temp);    //Anno
        temp = strtok(NULL, ",");
        libri[i].prezzo = atof(temp);  //Prezzo
        temp = strtok(NULL, "\n");
		i++;
    }
	return i;
}
void VisualizzaLibri(t_libro libri[], int k)
{
	for (int i = 0; i < k; i++)
	{
		printf("[%d] ", &i+1);
		printf("%s", libri[i].titolo);
		printf("%s", libri[i].autore);
		printf("%d", libri[i].anno);
		printf("%f", libri[i].prezzo);
	}
	
}
void menu()
{
    printf("1-Popolare i libri\n");
    printf("2-inserire un libro\n");
    printf("3-Visualizzare lista dei libri\n");
    printf("4-Visualizza somma e media\n");
    printf("5-Visualizzare i numeri pari\n");
    printf("6-Visualizzare i numeri dispari\n");
    printf("7-Ricercare un numero\n");
    printf("8-Eliminare un numero\n");
    printf("9-Alternare i numero\n");
    printf("10-Ordinare i numero\n");
    printf("11-esci\n");
}
int main()
{
	FILE *lista;
	t_libro libri[20];
	int n, opzione;
	lista = fopen("libri.txt", "r");
	if (lista == NULL)
    {
        printf("Errore nell'aprire il file.\n");
        return 1;
    }

	fclose(lista);
	return 0;
}