// Napravite funkciju koja prima niz, velicinu niza i dimenzije matrice,
// te alocira memoriju za matricu i prepisuje vrijednosti iz niza u matricu.
// Treba vratiti NULL ako dimenzije matrice ne odgovaraju dimenziji niza (svi brojevi se trebaju prepistati).

#include<stdio.h>
#include<stdlib.h>

int** generiraj(int niz[], int velicina, int n, int m) {
	if ((n * m) < velicina) return NULL;

	int** matrica = (int**)malloc(sizeof(int*) * n);

	for (int i = 0; i < n; i++)
	{
		matrica[i] = (int*)calloc(m, sizeof(int));
	}

	// Nakon ovoga profesor je napisao: "OK, imate 5, mozete ici"

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i * m + j >= velicina) break;

			matrica[i][j] = niz[i * m + j];
		}
	}

	return matrica;
}

int main() {
	int niz[5] = { 1,2,3,4,5 };
	int n = 2, m = 3;

	int** mat = generiraj(niz, 5, n, m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf(" %d", mat[i][j]);
		}
		printf("\n");
	}

	return 0;
}