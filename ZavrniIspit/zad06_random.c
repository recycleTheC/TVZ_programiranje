#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int* generirajRandom(int n, int min, int max) {

	int brElemenata = abs(max - min) + 1;

	srand(time(NULL));

	int* elementi = (int*)calloc(brElemenata, sizeof(int));

	for (int i = 0, k = min; i < brElemenata, k <= max; i++, k++) {
		elementi[i] = k;
	}

	for (int i = 0; i < n; i++) {
		int indx = rand() % brElemenata;

		int br = elementi[i];
		elementi[i] = elementi[indx];
		elementi[indx] = br;
	}

	int* niz = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) {
		niz[i] = elementi[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (niz[i] > niz[j]) {
				int tmp = niz[i];
				niz[i] = niz[j];
				niz[j] = tmp;
			}
		}
	}

	return niz;
}

void ispis(int* niz, int n) {
	for (int i = 0; i < n; i++) {
		printf("%4d", niz[i]);
	}
	printf("\n");
}

int main() {
	int* niz = generirajRandom(7, 1, 35);
	ispis(niz, 5);
}