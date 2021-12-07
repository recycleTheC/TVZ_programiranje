#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX 100

void ucitajNiz(int* p, int n);
void popuniRandom(int p[], int n, int min, int max);
void ispisiNiz(int* p, int n);
double arsr(int p[], int n);
void minMax(int p[], int n, int* pMin, int* pMax);

int main()
{
	srand(time(NULL));

	int n;
	int niz[MAX];

	int lokMin, lokMax;

	scanf("%d", &n);

	ucitajNiz(niz, n);
	//popuniRandom(&niz[0], n, -2, 14);
	ispisiNiz(niz, n);

	printf("\nAritmeticka sredina: %.2f\n", arsr(niz, n));

	minMax(niz, n, &lokMin, &lokMax);

	printf("Max: %d [%d]\n", niz[lokMin], lokMin);
	printf("Max: %d [%d]\n", niz[lokMax], lokMax);
}

void ucitajNiz(int* p, int n) {
	for (int i = 0; i < n; i++) {
		scanf("%d", p + i);
	}
}

void popuniRandom(int p[], int n, int min, int max) {
	for (int i = 0; i < n; i++) {
		p[i] = rand() % (max - min + 1) + min;
	}
}

void ispisiNiz(int* p, int n) {
	for (int i = 0; i < n; i++) {
		printf("%4d", p[i]);
	}
}

double arsr(int p[], int n) {
	double rez = 0;
	for (int i = 0; i < n; i++) {
		rez += p[i];
	}

	return rez / n;
}

void minMax(int p[], int n, int* pMin, int* pMax) {
	int min = p[0];
	int max = p[0];
	int lokMin = 0, lokMax = 0;

	for (int i = 1; i < n; i++) {
		if (p[i] > max) {
			max = p[i];
			lokMax = i;
		}

		if (p[i] < min) {
			min = p[i];
			lokMin = i;
		}
	}

	*pMin = lokMin;
	*pMax = lokMax;
}