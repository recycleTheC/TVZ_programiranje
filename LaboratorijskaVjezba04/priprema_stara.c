#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 512

char* imeIzUnosa(char unos[]) {
	int len = strlen(unos);
	char* start = &unos[0], * end = &unos[0];

	for (int i = 0; i < len; i++)
	{
		if (isalpha(unos[i])) {
			start = &unos[i];
			end = &unos[i];

			for (int j = 0; j < len - 1; j++)
			{
				if (*(start + j) == ':') {
					break;
				}
				else end++;
			}

			break;
		}
	}

	len = end - start;
	char* ime = (char*)calloc(len + 1, sizeof(char*));

	strncpy(ime, start, len);

	return ime;
}

char* pocetakZivotinje(char unos[]) {
	int len = strlen(unos);

	for (int i = 1; i < len - 1; i++)
	{
		int prije = isalpha(unos[i + 1]);
		int sada = isspace(unos[i]);
		int poslije = unos[i - 1] == ':';

		if (prije && sada && poslije) {
			return &unos[i + 1];
		}
	}

	return NULL;
}

char* zivotinjaIzUnosa(char unos[]) {
	char* start = pocetakZivotinje(unos);
	int len = strlen(start);

	char* zivotinja = (char*)calloc(len + 1, sizeof(char*));
	strncpy(zivotinja, start, len);

	return zivotinja;
}

char** upisiStudenta(char** studenti, char* ime, int index) {

	studenti[index] = (char*)calloc(strlen(ime), sizeof(char*));
	strcpy(studenti[index], ime);

	return studenti;
}

char** upisiZivotinju(char** zivotinje, char* zivotinja, int index) {

	zivotinje[index] = (char*)calloc(strlen(zivotinja), sizeof(char*));
	strcpy(zivotinje[index], zivotinja);

	return zivotinje;
}

int ispitivanje(char* unos, char* pravaZivotinja) {
	return strstr(_strlwr(unos), _strlwr(pravaZivotinja));
}

int jeLiNetkoPogodio(char** zivotinje, char* zivotinja, int n) {

	int pogodak = 0;

	for (int i = 0; i < n; i++)
	{
		if (ispitivanje(zivotinje[i], zivotinja) != NULL) {
			pogodak++;
		}
	}

	return pogodak;
}

void ispisiPogotke(char** zivotinje, char* zivotinja, char** studenti, int n) {
	for (int i = 0; i < n; i++)
	{
		if (ispitivanje(zivotinje[i], zivotinja) != NULL) {
			printf("%s\n", studenti[i]);
		}
	}
}

int main() {

	char unos[MAX];
	int nStudenata = 0;

	scanf("%512[^\n]", unos);

	char* imeUnositelja = imeIzUnosa(unos);
	char* unesenaZivotinja = zivotinjaIzUnosa(unos);

	char** studenti = (char**)malloc(sizeof(char**) * 1);
	char** zivotinje = (char**)malloc(sizeof(char**) * 1);

	while (strcmp(imeUnositelja, "Profesor Ivan") != 0) {

		nStudenata++;

		studenti = (char**)realloc(studenti, sizeof(char**) * nStudenata);
		zivotinje = (char**)realloc(zivotinje, sizeof(char**) * nStudenata);

		studenti = upisiStudenta(studenti, imeUnositelja, nStudenata - 1);
		zivotinje = upisiZivotinju(zivotinje, unesenaZivotinja, nStudenata - 1);

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