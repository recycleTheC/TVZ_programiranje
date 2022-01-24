#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct {
	char pojam[25];
	char prijevod[100];
} Rjecnik;

Rjecnik* ucitajRjecnik(int* n);
void pronadjiPojam(const Rjecnik* rjecnik, const int zapisi, const char* pojam);

int main() {

	int zapisi;
	Rjecnik* rjecnik = ucitajRjecnik(&zapisi);

	char pojam[25]; // engleski
	scanf("%[^\n]", pojam);

	pronadjiPojam(rjecnik, zapisi, &pojam);

	return 0;
}

Rjecnik* ucitajRjecnik(int* n) {
	int ucitano = 0, max = 5;
	*n = 0;

	FILE* datoteka = fopen("Rjecnik.txt", "r");
	if (datoteka == NULL) exit(1);

	Rjecnik* rjecnik = (Rjecnik*)malloc(sizeof(Rjecnik) * max);
	if (rjecnik == NULL) exit(1);

	while (fscanf(datoteka, "%[^:]: %[^\n]%*c", rjecnik[ucitano].pojam, rjecnik[ucitano].prijevod) == 2) {

		ucitano++;

		if (ucitano == max) {
			max += 5;

			rjecnik = (Rjecnik*)realloc(rjecnik, sizeof(Rjecnik) * max);
			if (rjecnik == NULL) exit(1);
		}
	}

	*n = ucitano;

	return rjecnik;
}

int duljinaPodstringa(char* podstring) {
	int len = 0;

	while (*podstring != ' ' && *podstring != '\0') {
		podstring++;
		len++;
	}

	return len;
}

char** razdvojiRijeci(char* string, int * brojRijeci) {
	int n = 0, max = 5;

	char** rijeci = (char**)malloc(sizeof(char*) * max);

	int len = duljinaPodstringa(string);

	while (len != 0) {
		rijeci[n] = (char*)calloc(len + 1, sizeof(char));
		strncat(rijeci[n], string, len);

		n++;

		if (n == max) {
			max += 5;
			rijeci = (char**)realloc(rijeci, sizeof(char*) * max);
		}

		if (*(string + len) == '\0') break;
		string += len + 1;

		len = duljinaPodstringa(string);
	}

	*brojRijeci = n;

	return rijeci;
}

char* generirajNaglasak(const char* pojam, const char* prijevod) {
	char* naglasak = (char*)calloc(strlen(prijevod) + 1, sizeof(char));
	if (naglasak == NULL) return NULL;

	int n;
	char** rijeci = razdvojiRijeci(prijevod, &n);

	int ispred = 0, iza = 0, redPojma = 0;

	for (int i = 0; i < n; i++)
	{
		if (strcmp(pojam, rijeci[i]) != 0) {
			ispred++;
		}
		else {
			redPojma = i;
			break;
		}
	}

	iza = n - ispred - 1;

	if (ispred >= 2) {
		strcat(naglasak, "... ");
		ispred = 2;
	}


	for (int i = redPojma - ispred; i >= 0 && i < redPojma; i++)
	{
		strcat(naglasak, rijeci[i]); 
		strcat(naglasak, " ");
	}

	strcat(naglasak, _strupr(rijeci[redPojma]));
	if(iza != 0) strcat(naglasak, " ");

	for (int i = redPojma + 1; i <= redPojma + 2 && i < n; i++)
	{
		strcat(naglasak, rijeci[i]);
		strcat(naglasak, " ");
	}

	if(iza >= 2) strcat(naglasak, " ...");
	
	return naglasak;
}

void pronadjiPojam(const Rjecnik* rjecnik, const int zapisi, const char* pojam) {

	FILE* datoteka = fopen("Prijevod.txt", "w");
	if (datoteka == NULL) exit(1);

	int nPojavljivanja = 0;

	for (int i = 0; i < zapisi; i++)
	{
		char* pojavaPojma = strstr(rjecnik[i].prijevod, pojam);

		if (pojavaPojma != NULL) {
			nPojavljivanja++;
			char* naglasak = generirajNaglasak(pojam, rjecnik[i].prijevod);

			printf("%s: %s\n", rjecnik[i].pojam, naglasak);
			fprintf(datoteka, "%s: %s\n", rjecnik[i].pojam, naglasak);
		}
	}

	if (nPojavljivanja == 0) {
		printf("NE POSTOJI RIJEC!\n");
		fprintf(datoteka, "NE POSTOJI RIJEC!\n");
	}

	fclose(datoteka);
}