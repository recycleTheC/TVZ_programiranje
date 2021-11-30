#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

#define MAX 10000

int main() {

	int niz[MAX], temp, i;

	srand(time(NULL));

	for (i = 0; i < MAX; i++) {
		niz[i] = rand() % 100;
	}

	/*for (i = 0; i < MAX; i++) {
		printf("%3d", niz[i]);
		if (i % 10 == 9) printf("\n");
	}*/

	int bilaZamjena = 0;

	do {
		bilaZamjena = 0;

		for (i = 0; i < MAX - 1; i++) {
			if (niz[i] > niz[i + 1]) {
				temp = niz[i];
				niz[i] = niz[i + 1];
				niz[i + 1] = temp;

				bilaZamjena = 1;
			}
		}
	} while (bilaZamjena);

	printf("\n\n");
	for (i = 0; i < MAX; i++) {
		printf("%3d", niz[i]);
		if (i % 10 == 9) printf("\n");
	}

	return 0;
}