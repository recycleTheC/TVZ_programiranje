#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int** kreirajMatricu(int m);
void ucitajPodatke(int** mat, int m);
void ispisPodataka(int** mat, int m);
int zbrojRetka(int** mat, int redak, int m);
int zbrojStupca(int** mat, int stupac, int m);
int zbrojDijagonale(int** mat, int m);
int magicniKvadrat(int** mat, int m);
int imaNulaUMatrici(int** mat, int m);
void usavrsiKvadrat(int** mat, int m, int brNula);

int main() {
	int m;

	scanf("%d", &m);

	int** matrica = kreirajMatricu(m);

	ucitajPodatke(matrica, m);

	int brNula = imaNulaUMatrici(matrica, m);

	if (brNula != 0) usavrsiKvadrat(matrica, m, brNula);

	int provjera = magicniKvadrat(matrica, m);

	if (provjera) ispisPodataka(matrica, m);
	else printf("Ovo nije magicni kvadrat");

	return 0;
}

int** kreirajMatricu(int m) {
	int** mat = (int**)malloc(sizeof(int*) * m);

	for (int i = 0; i < m; i++)
	{
		mat[i] = (int*)calloc(m, sizeof(int));
	}

	return mat;
}

void ucitajPodatke(int** mat, int m) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
}

void ispisPodataka(int** mat, int m) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%4d", mat[i][j]);
		}
		printf("\n");
	}
}

int zbrojRetka(int** mat, int redak, int m) {

	int zbr = 0;

	for (int j = 0; j < m; j++)
	{
		zbr += mat[redak][j];
	}

	return zbr;
}

int zbrojStupca(int** mat, int stupac, int m) {

	int zbr = 0;

	for (int i = 0; i < m; i++)
	{
		zbr += mat[i][stupac];
	}

	return zbr;
}

int imaNulaUMatrici(int** mat, int m) {

	int nule = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mat[i][j] == 0) nule++;
		}
	}

	return nule;
}

int zbrojDijagonale(int** mat, int m) {

	int zbr = 0;

	for (int i = 0; i < m; i++)
	{
		zbr += mat[i][i];
	}

	return zbr;
}

int magicniKvadrat(int** mat, int m) {

	int potrebno = maxZbr(m);

	for (int i = 0; i < m - 1; i++)
	{
		int zbr1 = zbrojRetka(mat, i, m);
		int zbr2 = zbrojRetka(mat, i + 1, m);

		if (zbr1 != potrebno) return 0;
		if (zbr1 != potrebno) return 0;

	}

	for (int i = 0; i < m - 1; i++)
	{
		int zbr1 = zbrojStupca(mat, i, m);
		int zbr2 = zbrojStupca(mat, i + 1, m);

		if (zbr1 != potrebno) return 0;
		if (zbr1 != potrebno) return 0;
	}

	if (zbrojDijagonale(mat, m) != potrebno) return 0;

	return 1;
}

int maxZbr(int m) {
	int zbr = 0;

	for (int i = 0; i <= m * m; i++)
	{
		zbr += i;
	}

	return zbr / m;
}

void usavrsiKvadrat(int** mat, int m, int brNula) {

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mat[i][j] == 0) {
				int zbr = maxZbr(m);

				for (int k = 1; k <= zbr; k++)
				{
					mat[i][j] = k;

					int zbrRetka = zbrojRetka(mat, i, m);

					if (zbr == zbrRetka) {
						break;
					}
				}
			}
		}
	}
}