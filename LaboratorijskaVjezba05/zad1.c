#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int dan, mjesec, godina;
} Datum;

typedef struct {
	int sati, minuta;
} Vrijeme;

typedef struct {
	int sati, minute, sekunde;
} Trajanje;

typedef struct {
	char broj_korisnika[14];
	Datum datum;
	Vrijeme vrijeme;
	char broj_poziva[14];
	Trajanje trajanje;
	int trajanje_s;
} Poziv;

Poziv* ucitajPozive(int* brPoziva);
Poziv* filtrirajPozive(Poziv* pozivi, int brPoziva, char korisnik[], int* brFiltriranih);
void sortirajPozive(Poziv* pozivi, int brPoziva);

int main() {
	char korisnik[14];
	int brPoziva, brFiltriranih;

	scanf("%s", korisnik);

	Poziv* pozivi = ucitajPozive(&brPoziva);
	Poziv* filtrirani = filtrirajPozive(pozivi, brPoziva, korisnik, &brFiltriranih);

	free(pozivi);

	FILE* datoteka = fopen("pozivi.txt", "w");
	if (datoteka == NULL) exit(1);

	if (brFiltriranih == 0) {
		fprintf(datoteka, "NE POSTOJI KORISNIK S TIM BROJEM!");
	}
	else {
		int n, total = 0;

		if (brFiltriranih <= 10) n = brFiltriranih;
		else n = 10;

		sortirajPozive(filtrirani, brFiltriranih);

		for (int i = 0; i < n; i++)
		{
			fprintf(datoteka, "%s->%s %02d:%02d:%02d\n",
				filtrirani[i].broj_korisnika,
				filtrirani[i].broj_poziva,
				filtrirani[i].trajanje.sati,
				filtrirani[i].trajanje.minute,
				filtrirani[i].trajanje.sekunde
			);

			total += filtrirani[i].trajanje_s;
		}

		fprintf(datoteka, "Ukupno trajanje svih poziva (s): %d\n", total);
	}

	fclose(datoteka);

	return 0;
}

int trajanje(Trajanje trajanje) {
	return trajanje.sati * 3600 + trajanje.minute * 60 + trajanje.sekunde;
}

Poziv* ucitajPozive(int* brPoziva) {
	int n = 0, max = 10;

	Poziv* pozivi = (Poziv*)malloc(sizeof(Poziv) * max);
	if (pozivi == NULL) exit(1);

	FILE* dat = fopen("racun.txt", "r");
	if (dat == NULL) exit(1);

	while (fscanf(dat, " %s %d.%d.%d. %d:%d %s %d:%d:%d",
		pozivi[n].broj_korisnika,
		&pozivi[n].datum.dan,
		&pozivi[n].datum.mjesec,
		&pozivi[n].datum.godina,
		&pozivi[n].vrijeme.sati,
		&pozivi[n].vrijeme.minuta,
		pozivi[n].broj_poziva,
		&pozivi[n].trajanje.sati,
		&pozivi[n].trajanje.minute,
		&pozivi[n].trajanje.sekunde
	) == 10) {

		pozivi[n].trajanje_s = trajanje(pozivi[n].trajanje);

		n++;

		if (n == max) {
			max += 10;

			pozivi = (Poziv*)realloc(pozivi, sizeof(Poziv) * max);
		}
	}

	fclose(dat);

	*brPoziva = n;

	return pozivi;
}

Poziv* filtrirajPozive(Poziv* pozivi, int brPoziva, char korisnik[], int* brFiltriranih) {
	int n = 0;
	Poziv* filtrirani = (Poziv*)malloc(sizeof(Poziv) * brPoziva);

	for (int i = 0; i < brPoziva; i++)
	{
		if (strcmp(pozivi[i].broj_korisnika, korisnik) == 0) {
			filtrirani[n] = pozivi[i];
			n++;
		}
	}

	*brFiltriranih = n;

	return filtrirani;
}

void sortirajPozive(Poziv* pozivi, int brPoziva) {
	for (int i = 0; i < brPoziva - 1; i++)
	{
		for (int j = i + 1; j < brPoziva; j++)
		{
			if (pozivi[i].trajanje_s < pozivi[j].trajanje_s) {
				Poziv tmp = pozivi[i];
				pozivi[i] = pozivi[j];
				pozivi[j] = tmp;
			}
		}
	}
}