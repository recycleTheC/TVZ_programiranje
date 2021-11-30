// Za uèitani element, ispisati koliko je veæih elemanata od njega u matrici

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int main()
{
	int mat[MAX][MAX];
	int n, m; // n = broj redaka, m = broj stupaca
	srand(time(NULL));

	n = 5;
	m = 20;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mat[i][j] = rand() % 100;
		}
	}

	printf("\n===========================\n");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%3d", mat[i][j]);
		}
		printf("\n");
	}

	printf("===========================\n\n");

	int br, k=0;

	//scanf("%d", &br);
	br = 77;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] > br) {
				k++;
			}
		}
	}

	printf("Veæih od %d: %d", br, k);

	return 0;
}