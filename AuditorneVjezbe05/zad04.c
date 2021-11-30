// Ispisati redak ciji zbroj elemenata je najmanji

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

	int zbr = 0, min = 0;
	int lok = 0;

	for (int j = 0; j < m; j++) {
		min += mat[0][j];
	}

	for (int i = 1; i < n; i++) {
		zbr = 0;
		for (int j = 0; j < m; j++) {
			zbr += mat[i][j];
		}

		if (zbr < min) {
			min = zbr;
			lok = i;
		}
	}

	for (int j = 0; j < m; j++) {
		printf("%3d", mat[lok][j]);
	}

	return 0;
}