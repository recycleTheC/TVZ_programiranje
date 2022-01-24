#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
	char registracija[7];
	int sifraModela;
	char ime[50];
	char luka[4];
} Jahta;

typedef struct {
	char sifra[4];
	char naziv[50];
	double lat;
	double lng;
	Jahta* jahte;
	int brJahti;
} Luka;

typedef struct {
	int id;
	char naziv[100];
	char kategorija[50];
	float duljina;
	int brojLezajeva;
	int brojSoba;
	int cijena;
} Model;

Jahta* ucitajJahte(int* pn);
Luka* ucitajLuke(int* pn);
Model dohvatiModel(int id);

void sortiraj(Jahta* jahte, int n);
Jahta* pronadjiJahte(Jahta* niz, int n, char* sifra, int* brJahti);

int main()
{
	int brLuka;
	Luka* luke = ucitajLuke(&brLuka);

	int brJahti;
	Jahta* jahte = ucitajJahte(&brJahti);

	for (int j = 0; j < brLuka; j++) {
		luke[j].jahte = pronadjiJahte(jahte, brJahti, luke[j].sifra, &luke[j].brJahti);
	}

	for (int i = 0; i < brLuka; i++) {

		sortiraj(luke[i].jahte, luke[i].brJahti);

		printf("Luka: %s\n", luke[i].sifra);
		for (int j = 0; j < luke[i].brJahti; j++) {
			Model m = dohvatiModel(luke[i].jahte[j].sifraModela);

			printf("   %s %s %s, %s %s %d\n", luke[i].sifra, luke[i].jahte[j].registracija, luke[i].jahte[j].ime,
			m.kategorija, m. naziv, m.cijena);
		}
	}

	return 0;
}

Model dohvatiModel(int id) {
	FILE* fin = fopen("modeli.dat", "rb");

	/*fseek(fin, 0, SEEK_END);
	int n = ftell(fin) / sizeof(Model);
	rewind(fin);
	
	Model* niz = (Model*)malloc(sizeof(Model) * n);
	fread(niz, sizeof(Model), n, fin);*/

	fseek(fin, sizeof(Model) * (id - 1), SEEK_SET);

	Model rez;
	fread(&rez, sizeof(Model), 1, fin);
	
	fclose(fin);

	return rez;
}

Jahta* pronadjiJahte(Jahta* niz, int n, char* sifra, int* brJahti)
{
	int br = 0;
	int max = 5;
	Jahta* rez = (Jahta*)malloc(sizeof(Jahta) * max);

	for (int i = 0; i < n; i++) {
		if (strcmp(sifra, niz[i].luka) == 0) {
			if (br == max)
			{
				// realloc niza
				rez = (Jahta*)realloc(rez, sizeof(Jahta) * max * 2);
				max *= 2;
			}

			rez[br++] = niz[i];
		}
	}

	*brJahti = br;
	return rez;
}

void sortiraj(Jahta* jahte, int n)
{
	int bilaZamjena = 1;
	while (bilaZamjena)
	{
		bilaZamjena = 0;
		for (int i = 0; i < n - 1; i++) {
			if (strcmp(jahte[i].registracija, jahte[i + 1].registracija) > 0) {
				Jahta tmp = jahte[i];
				jahte[i] = jahte[i + 1];
				jahte[i + 1] = tmp;
				bilaZamjena = 1;
			}
		}
	}
}

Luka* ucitajLuke(int* pn)
{
	FILE* fp = fopen("luke.txt", "r");
	// BRL Port of Barcelona (41.356761000000000, 2.178724299999999)

	Luka* luke = (Luka*)malloc(sizeof(Luka) * 53);
	int br = 0;

	while (fscanf(fp, "%s %[^(](%lf, %lf)", luke[br].sifra, luke[br].naziv, &luke[br].lat, &luke[br].lng) == 4)
	{
		int nazivLen = strlen(luke[br].naziv);

		if (luke[br].naziv[nazivLen - 1] == ' ') {
			luke[br].naziv[nazivLen - 1] = '\0';
		}

		luke[br].brJahti = 0;

		br++;
	}

	fclose(fp);
	*pn = br;
	return luke;
}

Jahta* ucitajJahte(int* pn)
{
	FILE* jah = NULL;
	jah = fopen("mojejahte.txt", "r");
	//TV9950 48 Carmenta#BRL
	Jahta* jahte;
	jahte = (Jahta*)malloc(sizeof(Jahta) * 487);
	int br = 0;

	while (fscanf(jah, "%s %d %[^#]# %s", jahte[br].registracija, &jahte[br].sifraModela, jahte[br].ime, jahte[br].luka) == 4)
	{
		br++;
	}

	fclose(jah);
	*pn = br;
	return jahte;
}
