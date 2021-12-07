#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX 100

void ucitajNiz(int* p, int n);
void popuniRandom(int p[], int n, int min, int max);
void ispisiNiz(int* p, int n);
void sortiranje(int p[], int n);
void swap(int* a, int* b);

int main()
{
	srand(time(NULL));

	int n;
	int niz[MAX];
	scanf("%d", &n);

	//ucitajNiz(niz, n);
	popuniRandom(niz, n, -2, 14);
	ispisiNiz(niz, n);
	sortiranje(niz, n);
	ispisiNiz(niz, n);
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
	printf("\n");
}

void sortiranje(int p[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (p[i] > p[j]) {
				swap(&p[i], &p[j]);
			}
		}
	}
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}