#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct {
	int min;
	int sec;
} Duljina;

typedef struct {
	int redniBroj;
	char izvodjac[32];
	char pjesma[32];
	Duljina duljina;
} Pjesma;

Pjesma* ucitajPjesme(int* brPjesama) {
	int n = 0, max = 5;

	FILE* datoteka = fopen("pjesme.txt", "r");
	if (datoteka == NULL) exit(1);

	Pjesma* pjesme = (Pjesma*)malloc(sizeof(Pjesma) * max);

	while (fscanf(datoteka, " %d#%[^#]#%[^#]#%d:%d",
		&pjesme[n].redniBroj,
		pjesme[n].izvodjac,
		pjesme[n].pjesma,
		&pjesme[n].duljina.min,
		&pjesme[n].duljina.sec
	) == 5) {
		n++;

		if (n == max) {
			max += 5;
			pjesme = (Pjesma*)realloc(pjesme, sizeof(Pjesma) * max);
		}
	}

	*brPjesama = n;
	fclose(datoteka);

	return pjesme;
}

void sortirajPjesme(Pjesma* pjesme, int brPjesama) {
	for (int i = 0; i < brPjesama - 1; i++) {
		for (int j = i + 1; j < brPjesama; j++) {
			if (pjesme[i].redniBroj > pjesme[j].redniBroj) {
				Pjesma tmp = pjesme[i];
				pjesme[i] = pjesme[j];
				pjesme[j] = tmp;
			}
		}
	}
}

int main() {
	int brPjesama;

	Pjesma* pjesme = ucitajPjesme(&brPjesama);
	sortirajPjesme(pjesme, brPjesama);

	FILE* datoteka = fopen("pjesme.bin", "wb");

	for (int i = 0; i < brPjesama; i++) {
		int total = pjesme[i].duljina.min * 60 + pjesme[i].duljina.sec;

		if (total >= (4 * 60)) {
			fwrite(&pjesme[i], sizeof(Pjesma), 1, datoteka);
		}
	}

	fclose(datoteka);
}