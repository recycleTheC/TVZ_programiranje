#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char ime[25];
	char oib[12];
	double placa;
} Osoba;

int brojZapisa(FILE* dat);

int main(int argc, char* argv[]) {

	FILE* datoteka = fopen("zaposlenici.bin", "ab");

	if (datoteka == NULL) {
		exit(1);
	}

	int n;

	printf("Broj zaposlenika: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("Upisi podatke za %d. zaposlenika:\n", i + 1);

		Osoba osoba;

		printf("- ime: ");
		scanf(" %25[^\n]", osoba.ime);

		printf("- OIB: ");
		scanf(" %11[^\n]", osoba.oib);

		printf("- placa: ");
		scanf(" %lf", &osoba.placa);

		fwrite(&osoba, sizeof(osoba), 1, datoteka);
	}

	fclose(datoteka);

	datoteka = fopen("zaposlenici.bin", "rb");

	if (datoteka == NULL) {
		exit(1);
	}

	n = brojZapisa(datoteka);

	printf("Broj zaposlenika: %d\n", n);

	for (int i = 0; i < n; i++)
	{
		Osoba osoba;

		fread(&osoba, sizeof(osoba), 1, datoteka);

		printf("%s, %s, %g\n", osoba.ime, osoba.oib, osoba.placa);
	}

	fclose(datoteka);
}

int brojZapisa(FILE* dat) {

	fseek(dat, 0, SEEK_END);
	int n = ftell(dat) / sizeof(Osoba);
	fseek(dat, 0, SEEK_SET);

	return n;
}