#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
	char pojam[15];
	char** sinonimi;
	int nSinonima;
} Pojam;

Pojam* ucitajPojmove(int* brPojmova);
void pronadjiPojmove(char* recenica, Pojam* pojmovi, int brPojmova);

int main() {
	int nPojmova;
	char recenica[255] = { 0 };

	Pojam* pojmovi = ucitajPojmove(&nPojmova);

	scanf("%[^\n]", recenica);
	pronadjiPojmove(recenica, pojmovi, nPojmova);

	return 0;
}

int duljinaPodstringa(char* podstring, char stoper) {

	int n = 0;

	while (1)
	{
		if (*podstring == stoper) {
			break;
		}
		else if (*podstring == '\0') {
			break;
		}
		else {
			n++;
			podstring++;
		}
	}

	return n;
}

char** pronadjiRijeci(char* upisaniNiz, int* brElemenata, char stoper) {
	int n = 0, max = 5, k = 1;

	if (stoper == ',') k = 2;

	char** rijeci = (char**)malloc(sizeof(char*) * max);
	if (rijeci == NULL) exit(1);

	int len = duljinaPodstringa(upisaniNiz, stoper);

	while (len != 0) {
		rijeci[n] = (char*)calloc(len + 1, sizeof(char));
		strncpy(rijeci[n], upisaniNiz, len);
		n++;

		upisaniNiz += len;
		if (*upisaniNiz == '\0') break;
		else upisaniNiz += k;

		len = duljinaPodstringa(upisaniNiz, stoper);

		if (n == max) {
			max += 5;
			rijeci = (char**)realloc(rijeci, sizeof(char*) * max);
		}
	}

	*brElemenata = n;

	return rijeci;
}

Pojam* ucitajPojmove(int* brPojmova) {
	int n = 0, max = 5;

	Pojam* pojmovi = (Pojam*)malloc(sizeof(Pojam) * max);

	FILE* datoteka = fopen("sinonimi.txt", "r");
	if (datoteka == NULL) exit(1);

	char temp[255] = { 0 };

	while (fscanf(datoteka, " %[^:]: %[^\n]", pojmovi[n].pojam, temp) == 2) {

		pojmovi[n].sinonimi = pronadjiRijeci(temp, &pojmovi[n].nSinonima, ',');
		n++;

		if (max == n) {
			max += 5;
			pojmovi = (Pojam*)realloc(pojmovi, sizeof(Pojam) * max);
		}
	}

	*brPojmova = n;

	return pojmovi;
}

int imaLiSinonima(Pojam* pojmovi, int brPojmova, char* recenica) {

	int brRijeci;

	char** rijeci = pronadjiRijeci(recenica, &brRijeci, ' ');

	int index = brRijeci - 1;
	int len = strlen(rijeci[index]) - 1;

	if (rijeci[index][len] == '.') rijeci[index][len] = '\0';

	for (int i = 0; i < brPojmova; i++)
	{
		for (int j = 0; j < brRijeci; j++)
		{
			if (strcmp(pojmovi[i].pojam, rijeci[j]) == 0) {
				free(rijeci);
				return 1;
			}
		}
	}

	free(rijeci);
	return 0;
}

void pronadjiPojmove(char* recenica, Pojam* pojmovi, int brPojmova) {

	FILE* datoteka = fopen("Kombinacije.txt", "w");

	if (imaLiSinonima(pojmovi, brPojmova, recenica)) {
		for (int i = 0; i < brPojmova; i++)
		{
			char* pocetak = strstr(recenica, pojmovi[i].pojam);

			if (pocetak != NULL) {
				for (int j = 0; j < pojmovi[i].nSinonima; j++)
				{
					int subLen = duljinaPodstringa(pocetak, ' ');
					int len = strlen(recenica) - subLen + strlen(pojmovi[i].sinonimi[j]) + 2;

					char* original = (char*)calloc(len + 1, sizeof(char));
					strcpy(original, recenica);

					char* temp = original + (pocetak - recenica);
					char* kraj = recenica + (pocetak - recenica) + subLen;

					if (*kraj == '\0') kraj--;

					strcpy(temp, pojmovi[i].sinonimi[j]);
					strcat(temp, kraj);

					fprintf(datoteka, "%s\n", original);

					free(original);
				}
			}

		}
	}
	else {
		fprintf(datoteka, "NEMA SINONIMA.\n");
	}

	fclose(datoteka);
}