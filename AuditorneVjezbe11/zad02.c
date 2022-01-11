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
	Jahta jahte[50];
	int brJahti;
} Luka;

Jahta* ucitajJahte(int* n);
Luka* ucitajLuke(int* pn);

Jahta* pronadjiJahte(Jahta* niz, int n, char* sifra, int* brJahti) {
	int br = 0;
	int max = 5;

	Jahta* rez = (Jahta*)malloc(sizeof(Jahta) * max);

	for (int i = 0; i < n; i++)
	{
		if (strcmp(sifra, niz[i].luka) == 0) {
			if (br == max) {
				rez = (Jahta*)realloc(rez, sizeof(Jahta) * max);
			}
		}
	}
}

int main() {

	int brJahti = 0, brLuka = 0;
	Jahta* jahte = ucitajJahte(&brJahti);
	Luka* luke = ucitajLuke(&brLuka);

	for (int i = 0; i < brLuka; i++)
	{
		printf("%s %d %s %s\n", luke[i].skracenica, jahte[i].sifraModela, jahte[i].ime, jahte[i].luka);
	}

	for (int i = 0; i < brJahti; i++)
	{
		for (int j = 0; j < brLuka; j++)
		{
			if (strcmp(luke[j].skracenica, jahte[i].luka) == 0) {
				int index = luke[j].brJahti;
				luke[j].jahte[index] = jahte[i];
				luke[j].brJahti++;
			}
		}
	}

	for (int i = 0; i < brLuka; i++)
	{
		printf("%s\n", luke[i].naziv);
		for (int j = 0; j < luke[i].brJahti; j++)
		{
			printf("    %s %s\n", luke[i].jahte[j].registracija, luke[i].jahte[j].ime);
		}
	}

	return 0;
}

Jahta* ucitajJahte(int* pn) {
	FILE* mojeJahte = fopen("mojejahte.txt", "r");

	// TV9950 48 Carmenta#BRL

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