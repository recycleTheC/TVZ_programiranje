// Ispisati cijeli stupac gdje se nalazi najmanji broj

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

	int min = mat[0][0];
	int lok = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (mat[i][j] < min) {
				min = mat[i][j];
				lok = j;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d\n", mat[i][lok]);
	}

	return 0;
}