// Definirati matricu n x m
// Napuniti slucajnim brojevima od[-7, 198]
// ispisati broj èiji susjedi ukupno imaju najviše djelitelja

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int brojDjelitelja(int el) {
	int n = 0;

	if (el < 0) el *= -1;

	for (int i = 1; i <= el; i++) {
		if (el % i == 0) n++;
	}

	return n;
}

int main()
{
	int mat[MAX][MAX];
	int n, m;

	scanf("%d %d", &n, &m);
	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mat[i][j] = rand() % 206 - 7; // [-7, 198] = 199 + 7 = 206
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%4d", mat[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");

	int maxDj = 0;
	int red, stupac;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int zbr = 0;

			if (i > 0) zbr += brojDjelitelja(mat[i - 1][j]);
			if (i < n - 1) zbr += brojDjelitelja(mat[i + 1][j]);
			if (j > 0) zbr += brojDjelitelja(mat[i][j - 1]);
			if (j < m - 1) zbr += brojDjelitelja(mat[i][j + 1]);

			if (zbr > maxDj) {
				maxDj = zbr;
				red = i;
				stupac = j;
			}
		}
	}

	printf("Max djelitelja susjeda: %d, na lokaciji: [%d, %d] = %d", maxDj, red + 1, stupac + 1, mat[red][stupac]);

	return 0;
}