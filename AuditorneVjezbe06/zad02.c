// Definirati matricu n x m
// Napuniti slucajnim brojevima od[-7, 198]
// Ispisati element èiji susjedi daju najveæi zbroj
// i njegovu lokaciju

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

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

	int maxZbrojSusjeda = -7 * 4;
	int red, stupac;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int zbr = 0;

			if(i > 0) zbr += mat[i - 1][j];
			if(i < n - 1) zbr += mat[i + 1][j];
			if(j > 0) zbr += mat[i][j - 1];
			if (j < m - 1) zbr += mat[i][j + 1];

			if (zbr > maxZbrojSusjeda) {
				maxZbrojSusjeda = zbr;
				red = i;
				stupac = j;
			}
		}
	}

	printf("Max zbroj susjeda: %d, na lokaciji: [%d, %d]", maxZbrojSusjeda, red + 1, stupac + 1);


	return 0;
}