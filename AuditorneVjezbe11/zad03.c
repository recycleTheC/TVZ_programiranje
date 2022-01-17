#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char registracija[7];
	int id;
	char ime[50];
	char oznakaLuke[4];
} Jahta;

typedef struct {
	char oznaka[4];
	char naziv[50];
	double lat;
	double lng;
	Jahta* jahte;
	int nJahti;
} Luka;

Jahta* ucitajJahte(int* n);
Luka* ucitajLuke(int* n);
void povezivanjePodataka(Jahta* jahte, const int brJahti, Luka* luke, const int brLuka);
void sortirajLuke(Luka* luke, const int n);
void sortirajJahte(Jahta* jahte, const int n);
void pronadjiJathu(Jahta* jahte, const int n);
void pronadjiLuku(Luka* luke, const int n);

int main() {

	int nJahti, nLuka;

	Jahta* jahte = ucitajJahte(&nJahti);
	Luka* luke = ucitajLuke(&nLuka);

	sortirajLuke(luke, nLuka);
	sortirajJahte(jahte, nJahti);
	povezivanjePodataka(jahte, nJahti, luke, nLuka);

	printf("1: Ispisi jahte u luci\n");
	printf("2: Ispisi jahtu\n");
	printf(": ");

	int ch = 0;

	scanf("%d", &ch);

	switch (ch) {
	case 1:
		pronadjiLuku(luke, nLuka);
		break;
	case 2:
		pronadjiJathu(jahte, nJahti);
		break;
	default:
		printf("Neispravan odabir!");
	}

	free(jahte);
	free(luke);

	return 0;
}

Jahta* ucitajJahte(int* n) {
	int max = 5, index = 0;

	FILE* datoteka = fopen("mojejahte.txt", "r");

	if (datoteka == NULL) {
		printf("Nije moguce otvoriti datoteku mojejahte.txt\n");
		exit(1);
	}

	Jahta* jahte = (Jahta*)malloc(sizeof(Jahta) * max);

	while (fscanf(datoteka, "%s %d %[^#]# %s", jahte[index].registracija, &jahte[index].id, jahte[index].ime, jahte[index].oznakaLuke) == 4) {
		index++;

		if (index == max) {
			max += 5;
			jahte = (Jahta*)realloc(jahte, sizeof(Jahta) * max);
		}
	}

	*n = index;

	return jahte;
}

Luka* ucitajLuke(int* n) {
	int max = 5, index = 0;

	FILE* datoteka = fopen("luke.txt", "r");

	if (datoteka == NULL) {
		printf("Nije moguce otvoriti datoteku luke.txt\n");
		exit(1);
	}

	Luka* luke = (Luka*)malloc(sizeof(Luka) * max);

	while (fscanf(datoteka, "%s %[^(](%lf,%lf)", luke[index].oznaka, luke[index].naziv, &luke[index].lat, &luke[index].lng) == 4) {

		luke[index].nJahti = 0;

		luke[index].jahte = (Jahta*)malloc(sizeof(Jahta));

		int len = strlen(luke[index].naziv);

		if (luke[index].naziv[len - 1] == ' ') {
			luke[index].naziv[len - 1] = '\0';
		}

		index++;

		if (index == max) {
			max += 5;

			luke = (Luka*)realloc(luke, sizeof(Luka) * max);
		}
	}

	*n = index;

	return luke;
}

void sortirajLuke(Luka* luke, const int n) {
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(luke[i].oznaka, luke[j].oznaka) == 1) {
				Luka temp = luke[i];
				luke[i] = luke[j];
				luke[j] = temp;
			}
		}
	}
}

void sortirajJahte(Jahta* jahte, const int n) {
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(jahte[i].registracija, jahte[j].registracija) == 1) {
				Jahta temp = jahte[i];
				jahte[i] = jahte[j];
				jahte[j] = temp;
			}
		}
	}
}

void pronadjiJathu(Jahta* jahte, const int n) {
	char registracija[10] = { 0 };

	printf("Upisite registraciju jahte: ");
	scanf("%s", registracija);

	int index = -1;

	for (int i = 0; i < n; i++)
	{
		if (strcmp(jahte[i].registracija, registracija) == 0) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		printf("Nije moguce pronaci jahtu!\n");
	}
	else {
		printf("Jahta '%s'\n", jahte[index].ime);
		printf("  registracija: %s\n", jahte[index].registracija);
		printf("  luka: %s\n", jahte[index].oznakaLuke);
		printf("  ID: %d\n", jahte[index].id);
	}
}

void ispisJahtiULuci(Jahta* jahte, const int n) {
	for (int i = 0; i < n; i++)
	{
		printf("  %s, %s, %d\n", jahte[i].registracija, jahte[i].ime, jahte[i].id);
	}
	printf("\n");
}

void pronadjiLuku(Luka* luke, const int n) {
	char naziv[50] = { 0 };

	printf("Upisite dio naziva luke: ");
	scanf("%s", naziv);

	int pronalazak = -1, max = 5;
	int* index = (int*)calloc(max, sizeof(int));

	printf("\n");

	for (int i = 0; i < n; i++)
	{
		if (strstr(luke[i].naziv, naziv) != NULL) {
			pronalazak++;
			index[pronalazak] = i;

			if (pronalazak + 1 == max) {
				max += 5;
				index = (int*)realloc(index, sizeof(int) * max);
			}
		}
	}

	pronalazak++;

	if (pronalazak == 0) {
		printf("Nije moguce pronaci luku!\n");
	}
	else {
		for (int i = 0; i < pronalazak; i++)
		{
			int sel = index[i];
			printf("Luka '%s' (%s)\n", luke[sel].naziv, luke[sel].oznaka);
			ispisJahtiULuci(luke[sel].jahte, luke[sel].nJahti);
		}
	}
}

void povezivanjePodataka(Jahta* jahte, const int brJahti, Luka* luke, const int brLuka) {

	for (int i = 0; i < brLuka; i++)
	{
		int max = 10, index = 0;

		luke[i].jahte = (Jahta*)realloc(luke[i].jahte, sizeof(Jahta) * max);

		for (int j = 0; j < brJahti; j++)
		{
			if (strcmp(luke[i].oznaka, jahte[j].oznakaLuke) == 0) {

				luke[i].jahte[index] = jahte[j];
				luke[i].nJahti++;
				index++;

				if (max == index) {
					max += 5;
					luke[i].jahte = (Jahta*)realloc(luke[i].jahte, sizeof(Jahta) * max);
				}
			}
		}
	}
}