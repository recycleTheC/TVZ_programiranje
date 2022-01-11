#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {

	FILE* datoteka = fopen("ucenici.txt", "w+");

	if (datoteka == NULL) {
		printf("Datoteka se ne može otvoriti za pisanje.\n");
		exit(-1);
	}

	for (int i = 0; i < 5; i++)
	{
		char ime[25] = { 0 };
		double koef = 0;

		scanf("%s %lf", ime, &koef);

		fprintf(datoteka, "%d %s %lf\n", i, ime, koef);
	}

	fclose(datoteka);

	datoteka = fopen("ucenici.txt", "r+");

	char ime[100][25] = { {0} };
	double koef[100] = { 0 };
	int id[100] = { 0 }, n = 0;

	if (datoteka == NULL) {
		printf("Datoteka se ne moze otvoriti za citanje.\n");
		exit(-1);
	}

	while (fscanf(datoteka, "%d %s %lf\n", &id[n], ime[n], &koef[n]) == 3) {
		n++;
	}

	fclose(datoteka);

	for (int i = 0; i < n; i++)
	{
		printf("%d %s %lf", id[i], ime[i], koef[i]);
	}

	return 0;
}