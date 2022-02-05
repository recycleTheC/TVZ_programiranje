#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char naziv[41];
	double cijena;
	int red;
	int sjedalo;
	char datum[12];
	char vrijeme[6];
	int status;
} Koncert;

Koncert* ucitajKoncerte(int* brKoncerata);
double statistika(char naziv[], char datum[], char vrijeme[], Koncert* koncerti, int brKoncerata);

int main() {
	int brKoncerata;

	Koncert* koncerti = ucitajKoncerte(&brKoncerata);

	int brUpita;
	char datum[12] = { 0 }, vrijeme[6] = { 0 }, naziv[41] = { 0 };

	scanf("%d", &brUpita);

	FILE* datoteka = fopen("podaci.txt", "w");

	for (int i = 0; i < brUpita; i++)
	{
		scanf(" %s %s %[^\n]", datum, vrijeme, naziv);
		double rezultat = statistika(naziv, datum, vrijeme, koncerti, brKoncerata);
		if (rezultat != -1) fprintf(datoteka, "%s %s %s: %.2f kn\n", naziv, datum, vrijeme, rezultat);
	}

	fclose(datoteka);

	return 0;
}

Koncert* ucitajKoncerte(int* brKoncerata) {

	FILE* datoteka = fopen("karte.dat", "rb");

	fseek(datoteka, 0, SEEK_END);
	int n = ftell(datoteka) / sizeof(Koncert);
	rewind(datoteka);

	Koncert* koncerti = (Koncert*)malloc(sizeof(Koncert) * n);

	fread(koncerti, sizeof(Koncert), n, datoteka);

	*brKoncerata = n;

	fclose(datoteka);

	return koncerti;
}

double statistika(char naziv[], char datum[], char vrijeme[], Koncert* koncerti, int brKoncerata) {
	int n = 0;
	double total = 0;

	for (int i = 0; i < brKoncerata; i++)
	{
		int pogodakNaziv = strcmp(naziv, koncerti[i].naziv);
		int pogodakDatum = strcmp(datum, koncerti[i].datum);
		int pogodakVrijeme = strcmp(vrijeme, koncerti[i].vrijeme);

		if (pogodakNaziv == 0 && pogodakDatum == 0 && pogodakVrijeme == 0) {
			if (koncerti[i].status == 2) {
				total += koncerti[i].cijena;
				n++;
			}
		}
	}

	if (n == 0) return -1;
	else return total;
}