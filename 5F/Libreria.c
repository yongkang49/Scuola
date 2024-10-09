#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_LIBRI 50

enum categorie // enumeratore per definire le categorie
{
	Narrativa,
	Avventura,
	Scienza,
	Giallo,
	Saggistica
} categoria;
typedef struct Libri // struct dei libri
{
	char titolo[40];
	char autore[30];
	int anno;
	double prezzo;
	enum categorie categoria;
} t_libro;

int PopolaLibri(t_libro libri[]) // popola i libri presenti nel file 'Libri.c'
{
	FILE *lista;
	char *temp;
	char buffer[100];				 // per contenere i dati letti
	int i = 0;						 // contatore per sapere quanti libri sono stati letti
	lista = fopen("Libri.txt", "r"); // si apre il file in lettura
	if (lista == NULL)				 // controllo dell'operazione fopen
	{
		printf("Errore nell'aprire il file.\nEsegui prima 'LeggiLibri.c'");
		return 1;
	}
	while (fgets(buffer, sizeof(buffer), lista)) // popola tutti i libri che sono presenti nel file
	{
		temp = strtok(buffer, ",");
		strcpy(libri[i].titolo, temp); // titolo
		temp = strtok(NULL, ",");
		strcpy(libri[i].autore, temp); // autore
		temp = strtok(NULL, ",");
		libri[i].anno = atoi(temp); // anno
		temp = strtok(NULL, ",");
		libri[i].prezzo = atof(temp); // prezzo
		i++;
	}
	printf("libri popolati con successo\n");
	sleep(1);
	fclose(lista); // chiusura del file
	return i;
}
const char *getCategoria(enum categorie categoria)
{
	switch (categoria)
	{
	case Narrativa:
		return "Narrativa";
	case Avventura:
		return "Avventura";
	case Scienza:
		return "Scienza";
	case Giallo:
		return "Giallo";
	case Saggistica:
		return "Saggistica";
	}
}

void VisualizzaLibri(t_libro libri[], int k, int *nCate) // visualizza i libri in modo tabellare
{
	printf("%-42s %-32s %-4s %-7s %-12s\n", "Titolo", "Autore", "Anno", "Prezzo", "Categoria");
	printf("----------------------------------------------------------\n");
	for (int i = 0; i < k; i++)
	{
		printf("[%-2d]", i + 1);
		printf("%-40s", libri[i].titolo);
		printf("%-30s", libri[i].autore);
		printf("%-2d  ", libri[i].anno);
		printf("  %-5.2f", libri[i].prezzo);
		if (*nCate != 0)
		{
			printf("%-10s", getCategoria(libri[i].categoria));
		}
		printf("\n");
	}
}
int ControllaNumeri(char temp[])
{
	for (int i = 0; i < strlen(temp); i++)
	{
		if (!isdigit(temp[i]) || !temp[i] == '.') // se trova un carattere ritorna 0
		{
			return 0;
		}
	}
	return 1; // se trova solo numeri ritorna 1
}
int AggiungiCategoria(t_libro libri[], int n, int *nCate)
{
	int cate;
	int esci = 1;
	do // categoria
	{
		printf("Specifica la categoria\n");
		printf("1-Narrativa\n2-Avventura\n3-Scienza\n4-Giallo\n5-Saggistica\n6-Continua dopo\n");
		scanf("%d", &cate);
		switch (cate)
		{
		case 1:
			libri[n].categoria = Narrativa;
			break;
		case 2:
			libri[n].categoria = Avventura;
			break;
		case 3:
			libri[n].categoria = Scienza;
			break;
		case 4:
			libri[n].categoria = Giallo;
			break;
		case 5:
			libri[n].categoria = Saggistica;
			break;
		case 6:
			esci = 0;
			break;
		}
	} while (cate < 0 || cate > 6 && !esci);
	system("clear");
	if (esci) // ritorna 1 per continuare il ciclo esteno
	{
		*nCate++;
		return 1;
	}
	else // se si vuole continuare dopo ritorna 0
	{
		return 0;
	}
}
void Inserisci(t_libro libri[], int n, int *nCate)
{
	char temp[40];
	int cate;
	printf("Inserisci il titolo\n");
	scanf("%s", temp);
	strcpy(libri[n].titolo, temp); // titolo
	printf("Inserisci l'autore\n");
	scanf("%s", temp);
	strcpy(libri[n].autore, temp); // autore
	do
	{
		printf("Inserisci l'anno di pubblicazione\n");
		scanf("%s", temp);
	} while (!ControllaNumeri(temp));
	libri[n].anno = atoi(temp); // anno
	do
	{
		printf("Inserisci il prezzo\n");
		scanf("%s", temp);
	} while (!ControllaNumeri(temp));
	libri[n].prezzo = atof(temp); // prezzo
	AggiungiCategoria(libri, n, &(*nCate));
}

int RicercaTitolo(t_libro libri[], int n)
{
	char titolo[40];
	printf("Inserisci il titolo del libro da cercare: ");
	scanf(" %[^\n]", titolo); // Legge il titolo con spazi
	int trovato = 0;
	for (int i = 0; i < n && !trovato; i++)
	{
		if (strcmp(libri[i].titolo, titolo) == 0) // Confronta i titoli
		{
			printf("Libro trovato:\n");
			printf("[%-2d]", i);
			printf("%-40s", libri[i].titolo);
			printf("%-30s", libri[i].autore);
			printf("%-2d  ", libri[i].anno);
			printf("  %-5.2f", libri[i].prezzo);
			trovato = 1;
		}
	}
	return trovato;
} // Funzione per visualizzare i libri di una stessa categoria
int VisualizzaCategoria(t_libro libri[], int n)
{
	int scelta;
	do
	{
		printf("Scegli una categoria:\n");
		printf("1-Narrativa\n2-Avventura\n3-Scienza\n4-Giallo\n5-Saggistica\n");
		scanf("%d", &scelta);
	} while (scelta < 1 || scelta > 5);
	enum categorie cate = (enum categorie)(scelta - 1);
	printf("Libri nella categoria %s:\n", getCategoria(cate));
	printf("%-40s %-30s %-4s %-7s\n", "Titolo", "Autore", "Anno", "Prezzo");
	printf("----------------------------------------------------------\n");
	int trovato = 0;
	for (int i = 0; i < n; i++)
	{
		if (libri[i].categoria == cate)
		{
			printf("[%-2d] ", i + 1);
			printf("%-40s", libri[i].titolo);
			printf("%-30s", libri[i].autore);
			printf("%-2d  ", libri[i].anno);
			printf("  %.2f\n", libri[i].prezzo);
			trovato = 1;
		}
	}
	return trovato;
}

int menu() // mostra all'utente tutte le opzioni possibili
{
	int i = 0;
	do
	{
		printf("1-Popolare i libri\n");
		printf("2-inserire un nuovo libro\n");
		printf("3-Inserisci le categorie\n");
		printf("4-Visualizzare lista dei libri\n");
		printf("5-Visualizza libri con titolo\n");
		printf("6-Visualizza libri con categoria\n");
		printf("7-esci\n");
		scanf("%d", &i);
	} while (i < 1 || i > 8);
	system("clear");
	return i;
}
int main()
{
	FILE *lista;
	t_libro libri[MAX_LIBRI];
	int n = 0, opzione;
	int nCate = 0, stopCate = 1;
	int esci = 1;
	do
	{
		opzione = menu();
		switch (opzione)
		{
		case 1: // Popola libri
			n = PopolaLibri(libri);
			break;
		case 2: // Inserisci libri
			Inserisci(libri, n, &nCate);
			n++;
			break;
		case 3: // insersci categoria
			if (n == 0)
			{
				printf("inserisci/popola prima i libri\n");
			}
			else
			{
				for (int i = 0; i < n && stopCate; i++)
				{
					printf("Inserisci la categoria per il libro: \n<%s>\n", libri[i].titolo);
					stopCate = AggiungiCategoria(libri, n, &nCate);
				}
			}
			break;
		case 4: // visualizza libri
			if (n == 0)
			{
				printf("inserisci/popola prima i libri\n");
			}
			else
			{
				VisualizzaLibri(libri, n, &nCate);
			}
			break;
		case 5: // ricerca libri con titolo
			if (n == 0)
			{
				printf("inserisci/popola prima i libri\n");
			}
			else
			{
				if (!RicercaTitolo(libri, n))
				{
					printf("Libro non trovato.\n");
				}
			}
			break;
		case 6: // visualizza libri con categoria
			if (nCate == 0)
			{
				printf("inserisci prima le categorie\n");
			}
			else
			{
				if (!VisualizzaCategoria(libri, n))
				{
					printf("Nessun libro trovato in questa categoria.\n");
				}
			}
			break;
		case 7:
			esci = 0;
			break;
		}
	} while (esci);
	return 0;
}