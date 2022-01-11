#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char registracija[7];
	int sifraModela;
	char ime[50];
	char luka[4];
} Jahta;

typedef struct {
	char skracenica[4];
	char naziv[50];
	double lat;
	double lng;
	Jahta* jahte;
	int brJahti;
} Luka;

Luka* ucitajLuke(int* pn);
Jahta* ucitajJahte(int* n);
Jahta* pronadjiJahte(Jahta* niz, int n, char* sifra, int* brJahti);
void sortiranje(Jahta* niz, int n);

int main() {

	int brJahti = 0, brLuka = 0;

	Jahta* jahte = ucitajJahte(&brJahti);
	Luka* luke = ucitajLuke(&brLuka);

	for (int i = 0; i < brLuka; i++) {
		luke[i].jahte = pronadjiJahte(jahte, brJahti, luke[i].skracenica, &luke[i].brJahti);
	}

	for (int i = 0; i < brLuka; i++)
	{
		sortiranje(luke[i].jahte, luke[i].brJahti);

		printf("Luka: %s\n", luke[i].skracenica);
		for (int j = 0; j < luke[i].brJahti; j++)
		{
			printf("\t%s %s %s\n", luke[i].skracenica, luke[i].jahte[j].registracija, luke[i].jahte[j].ime);
		}
	}

	return 0;
}

Jahta* ucitajJahte(int* pn) {
	FILE* mojeJahte = fopen("mojejahte.txt", "r");

	Jahta* jahte;
	jahte = (Jahta*)malloc(sizeof(Jahta) * 487);

	int n = 0;

	while (fscanf(mojeJahte, "%s %d %[^#]# %s", jahte[n].registracija, &jahte[n].sifraModela, jahte[n].ime, jahte[n].luka) == 4) {
		n++;
	}

	fclose(mojeJahte);

	*pn = n;

	return jahte;
}

Luka* ucitajLuke(int* pn) {
	FILE* sveLuke = fopen("luke.txt", "r"); 

	Luka* luke;
	luke = (Luka*)malloc(sizeof(Luka) * 487);

	int n = 0;

	while (fscanf(sveLuke, "%s %[^(](%lf, %lf)", luke[n].skracenica, luke[n].naziv, &luke[n].lat, &luke[n].lng) == 4) {
		int len = strlen(luke[n].naziv);

		if (luke[n].naziv[len - 1] == ' ') {
			luke[n].naziv[len - 1] = '\0';
		}

		luke[n].brJahti = 0;

		n++;
	}

	fclose(sveLuke);

	*pn = n;

	return luke;
}

Jahta* pronadjiJahte(Jahta* niz, int n, char* sifra, int* brJahti) {
	int br = 0;
	int max = 5;

	Jahta* rez = (Jahta*)malloc(sizeof(Jahta) * max);

	for (int i = 0; i < n; i++)
	{
		if (strcmp(sifra, niz[i].luka) == 0) {
			if (br == max) {
				rez = (Jahta*)realloc(rez, sizeof(Jahta) * max * 2);
				max *= 2;
			}

			rez[br++] = niz[i];
		}
	}

	*brJahti = br;

	return rez;
}

void sortiranje(Jahta* niz, int n) {
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (strcmp(niz[i].registracija, niz[j].registracija) > 0) {
				Jahta temp = niz[i];
				niz[i] = niz[j];
				niz[j] = temp;
			}

		}
	}
}