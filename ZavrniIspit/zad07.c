#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int* generirajNiz(int* n) {
	int* niz = (int*)calloc(*n, sizeof(int));

	srand(time(NULL));

	for (int i = 0; i < *n; i++) {
		niz[i] = rand() % (10 - 1 + 1) + 1;
	}

	niz = (int*)realloc(niz, sizeof(int) * (*n + 10));

	for (int i = *n; i < *n + 10; i++) {
		niz[i] = rand() % (200 - 100 + 1) + 100;
	}

	*n += 10;

	return niz;
}

void ispis(int* niz, int n) {
	for (int i = 0; i < n; i++) {
		printf("%4d", niz[i]);
		if ((i + 1) % 5 == 0) printf("\n");
	}
}

int main() {
	int n = 20;

	int* niz = generirajNiz(&n);
	ispis(niz, n);

	return 0;
}