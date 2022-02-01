#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char rijec[32];
	int vrijednost;
} Sentiment;

Sentiment* ucitajSentimente(int* brSentimenta);
char** izvuciRijeci(char* recenica, int* brRijeci);
void provjeriSentiment(char** rijeci, int brRijeci, Sentiment* sentimenti, int brSentimenta);

int main() {
	int brSentimenta, brRijeci;

	Sentiment* sentimenti = ucitajSentimente(&brSentimenta);
	char recenica[512] = { 0 };

	scanf("%[^\n]", recenica);
	char** rijeci = izvuciRijeci(recenica, &brRijeci);

	FILE* datoteka = fopen("RezultatAnalize.txt", "w");
	fprintf(datoteka, "%s\n", recenica);
	fclose(datoteka);

	provjeriSentiment(rijeci, brRijeci, sentimenti, brSentimenta);
}

Sentiment* ucitajSentimente(int* brSentimenta) {
	int n = 0, max = 5;

	Sentiment* sentimenti = (Sentiment*)malloc(sizeof(Sentiment) * max);
	if (sentimenti == NULL) exit(1);

	FILE* datoteka = fopen("Sentiment.txt", "r");
	char rijec[32] = { 0 }, vrijed[4] = {0};

	if (datoteka == NULL) exit(1);

	while (fscanf(datoteka, " %[^:]: %s", rijec, vrijed) == 2) {
		strcpy(sentimenti[n].rijec, rijec);

		if (strcmp(vrijed, "POZ") == 0) sentimenti[n].vrijednost = 1;
		else if (strcmp(vrijed, "NEG") == 0) sentimenti[n].vrijednost = 0;

		n++;

		if (n == max) {
			max += 5;

			sentimenti = (Sentiment*)realloc(sentimenti, sizeof(Sentiment) * max);
		}
	}

	*brSentimenta = n;

	return sentimenti;
}

char** izvuciRijeci(char* recenica, int* brRijeci) {
	int n = 0, max = 5;

	char** rijeci = (char**)malloc(sizeof(char*) * max);
	if (rijeci == NULL) exit(1);

	char* pocetak = recenica;
	char* kraj = strstr(recenica, " ");

	while (1) {
		int len;
		if (kraj != NULL) len = kraj - pocetak;
		else len = strlen(pocetak);

		rijeci[n] = (char*)calloc(len + 1, sizeof(char));
		strncpy(rijeci[n], pocetak, len);

		switch (rijeci[n][len-1])
		{
			case '!':
			case '.':
			case ',':
			case '?':
				rijeci[n][len - 1] = '\0';
				break;
		}
		
		n++;

		if (n == max) {
			max += 5;
			rijeci = (char**)realloc(rijeci, sizeof(char*) * max);
		}

		if (kraj == NULL) break;

		pocetak = kraj + 1;
		kraj = strstr(pocetak, " ");
	}

	*brRijeci = n;

	return rijeci;
}

void provjeriSentiment(char** rijeci, int brRijeci, Sentiment* sentimenti, int brSentimenta){
	
	FILE* datoteka = fopen("RezultatAnalize.txt", "a");
	int neg = 0, poz = 0;
	
	for (int i = 0; i < brRijeci; i++)
	{
		for (int j = 0; j < brSentimenta; j++)
		{
			if (strcmp(rijeci[i], sentimenti[j].rijec) == 0) {

				fprintf(datoteka, "%s\n", sentimenti[j].rijec);

				if (sentimenti[j].vrijednost) poz++;
				else neg++;
			}
		}
	}

	fprintf(datoteka, "Analiza: ");

	if (poz > neg) {
		fprintf(datoteka, "pozitivna\n");
	}
	else if (poz < neg) {
		fprintf(datoteka, "negativna\n");
	}
	else {
		fprintf(datoteka, "neutralna\n");
	}

	fclose(datoteka);
}