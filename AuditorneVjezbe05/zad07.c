// Simetrièno polje n x n Potrebno je ispisati arimtetièku sredinu glavne i sporedne dijagonale

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int mat[10][10];
	int n; // n = broj redaka

	n = 10;

	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j] = rand() % 10;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d", mat[i][j]);
		}
		printf("\n");
	}

	double zbrS = 0, kS = 0, zbrG = 0, kG = 0, arsr;

	printf("\nGlavna: ");

	for (int i = 0; i < n; i++) { // glavna
		zbrG += mat[n-i-1][i];
		kG++;
		printf("%d ", mat[n - i - 1][i]);
	}

	printf("\nSporedna: ");

	for (int i = 0; i < n; i++) { // sporedna
		zbrS += mat[i][i];
		kS++;
		printf("%d ", mat[i][i]);
	}

	arsr = zbrG / kG;
	printf("\nGlavna: %f\n", arsr);

	arsr = zbrS / kS;
	printf("Sporedna: %f\n", arsr);

	return 0;
}