#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* imeIzUnosa(char* unos);
char* zivotinjaIzUnosa(char* unos);
char** upisPodatka(char** matrica, char* podatak, int index);
int jeLiNetkoPogodio(char** zivotinje, char* zivotinja, int n);
void ispisiPogotke(char** zivotinje, char* zivotinja, char** studenti, int n);

int main() {

	char unos[256];
	int nStudenata = 0;

	scanf("%256[^\n]", unos);

	char* imeUnositelja = imeIzUnosa(unos);
	char* unesenaZivotinja = zivotinjaIzUnosa(unos);

	char** studenti = (char**)malloc(sizeof(char**) * 1);
	char** zivotinje = (char**)malloc(sizeof(char**) * 1);

	while (strcmp(imeUnositelja, "Profesor Ivan") != 0) {

		nStudenata++;

		studenti = upisPodatka(studenti, imeUnositelja, nStudenata);
		zivotinje = upisPodatka(zivotinje, unesenaZivotinja, nStudenata);

		scanf(" %512[^\n]", unos);

		imeUnositelja = imeIzUnosa(unos);
		unesenaZivotinja = zivotinjaIzUnosa(unos);
	}

	int pogodak = 0;

	if (nStudenata != 0) {
		pogodak = jeLiNetkoPogodio(zivotinje, unesenaZivotinja, nStudenata);
		printf("Broj studenata koji su pogodili zivotinju: %d od %d.\n\n", pogodak, nStudenata);

		if (pogodak != 0) {
			printf("Studenti koji su pogodili zivotinju:\n");
			ispisiPogotke(zivotinje, unesenaZivotinja, studenti, nStudenata);
		}
	}

	if (nStudenata == 0 || pogodak == 0) {
		printf("Vise srece drugi put!\n");
	}

	return 0;
}

char* imeIzUnosa(char* unos) {

	char* start = strstr(unos, " ") + 1;
	char* end = strstr(start, ": ");

	int len = end - start;
	char* ime = (char*)calloc(len + 1, sizeof(char*));

	strncpy(ime, start, len);

	return ime;
}

char* pocetakZivotinje(char* unos) {
	char* pocetak = NULL;
	char* podstring = strstr(unos, ":");

	while (podstring != NULL) {
		podstring++;
		pocetak = podstring;
		podstring = strstr(podstring, ":");
	}

	return pocetak + 1;
}

char* zivotinjaIzUnosa(char* unos) {
	char* start = pocetakZivotinje(unos);
	int len = strlen(start);

	char* zivotinja = (char*)calloc(len + 1, sizeof(char*));
	strncpy(zivotinja, start, len);

	return zivotinja;
}

char** upisPodatka(char** matrica, char* podatak, int index) {

	matrica = (char**)realloc(matrica, sizeof(char**) * index);

	matrica[index - 1] = (char*)calloc(strlen(podatak), sizeof(char*));
	strcpy(matrica[index - 1], podatak);

	free(podatak);

	return matrica;
}

int ispitivanje(char* unos, char* pravaZivotinja) {
	return strstr(_strlwr(unos), _strlwr(pravaZivotinja)) != NULL;
}

int jeLiNetkoPogodio(char** zivotinje, char* zivotinja, int n) {

	int pogodak = 0;

	for (int i = 0; i < n; i++)
	{
		if (ispitivanje(zivotinje[i], zivotinja)) {
			pogodak++;
		}
	}

	return pogodak;
}

void ispisiPogotke(char** zivotinje, char* zivotinja, char** studenti, int n) {
	for (int i = 0; i < n; i++)
	{
		if (ispitivanje(zivotinje[i], zivotinja)) {
			printf("%s\n", studenti[i]);
		}
	}
}