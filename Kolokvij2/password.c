#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
	char ime[25];
	char lozinka[25];
} Korisnik;

char** ucitajLozinke(int* brLozinki);
Korisnik* ucitajKorisnike(int* brKorisnika);
int jeLiCestaLozinka(char lozinka[], char** lozinke, int brLozinki);
int slicnostLozinke(Korisnik korisnik);

int main() {

	int brLozinki, brKorisnika;

	char** lozinke = ucitajLozinke(&brLozinki);
	Korisnik* korisnici = ucitajKorisnike(&brKorisnika);
	
	FILE* datoteka = fopen("RezultatiAnalize.txt", "w");
	if (datoteka == NULL) exit(1);

	for (int i = 0; i < brKorisnika; i++)
	{
		fprintf(datoteka, "%s\n", korisnici[i].lozinka);
	}

	fprintf(datoteka, "\nPopis sigurnih lozinki:\n");

	for (int i = 0; i < brKorisnika; i++)
	{
		int cestaLozinka = jeLiCestaLozinka(korisnici[i].lozinka, lozinke, brLozinki);
		int slicnost = slicnostLozinke(korisnici[i]);

		if (!cestaLozinka && !slicnost) {
			fprintf(datoteka, "%s\n", korisnici[i].lozinka);
		}
	}

	fclose(datoteka);

	return 0;
}

char** ucitajLozinke(int* brLozinki) {
	int n = 0, max = 5;

	FILE* datoteka = fopen("common_passwords.txt", "r");
	if (datoteka == NULL) exit(1);

	char** lozinke = (char**)malloc(sizeof(char*) * max);
	if (lozinke == NULL) exit(1);

	lozinke[n] = (char*)calloc(50, sizeof(char));

	while (fscanf(datoteka, " %[^\n]", lozinke[n]) == 1) {
		n++;

		if (n == max) {
			max += 5;

			lozinke = (char**)realloc(lozinke, sizeof(char*) * max);
			if (lozinke == NULL) exit(1);
		}

		lozinke[n] = (char*)calloc(50, sizeof(char));
	}

	fclose(datoteka);

	*brLozinki = n;

	return lozinke;
}

Korisnik* ucitajKorisnike(int* brKorisnika) {
	int n = 0, max = 5;
	char ulaz[255] = { 0 };

	Korisnik* korisnici = (Korisnik*)malloc(sizeof(Korisnik) * max);
	if (korisnici == NULL) exit(1);

	scanf(" %[^\n]", ulaz);

	while (strcmp(ulaz, ":") != 0) {
		char ime[25] = { 0 }, lozinka[25] = { 0 };
		sscanf(ulaz, "%[^:]:%s", ime, lozinka);

		strcpy(korisnici[n].ime, ime);
		strcpy(korisnici[n].lozinka, lozinka);

		n++;

		if (n == max) {
			max += 5;

			korisnici = (Korisnik*)realloc(korisnici, sizeof(Korisnik) * max);
			if (korisnici == NULL) exit(1);
		}

		scanf(" %[^\n]", ulaz);
	}

	*brKorisnika = n;

	return korisnici;
}

int jeLiCestaLozinka(char lozinka[], char** lozinke, int brLozinki) {
	for (int i = 0; i < brLozinki; i++)
	{
		if (strcmp(lozinka, lozinke[i]) == 0) {
			return 1;
		}
	}

	return 0;
}

int slicnostLozinke(Korisnik korisnik) {
	int n = 0;

	for (int i = 0; i < strlen(korisnik.ime); i++)
	{
		int ok = 0;

		for (int j = 0; j < strlen(korisnik.lozinka); j++)
		{
			if (korisnik.ime[i+j] == korisnik.lozinka[j]) {
				ok++;
			}
		}

		if (ok > n) n = ok;
	}

	if (n < 5) return 0;
	else return 1;
}