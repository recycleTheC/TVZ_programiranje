#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>

#define N 9

int ucitajSudoku() {
	char znak;
	scanf(" %c", &znak);

	if (znak >= '0' && znak <= '9') {
		return znak - '0';
	}

	return -1;
}

int ispravnostReda(int matrica[][N], int* stupac, int* redak, int* kvadrat) {

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++) {
				if (matrica[i][j] == matrica[i][k]) {
					*(redak) = i;
					*(stupac) = j;
					*(kvadrat) = kojiKvadrat(i, j);
					return 1;
				}
			}
		}
	}

	return 0;
}

int ispravnostStupca(int matrica[][N], int* stupac, int* redak, int* kvadrat) {

	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N - 1; i++)
		{
			for (int k = i + 1; k < N; k++) {
				if (matrica[i][j] == matrica[k][j]) {
					*(stupac) = i;
					*(redak) = j;
					*(kvadrat) = kojiKvadrat(i, j);
					return 1;
				}
			}
		}
	}

	return 0;
}

int kojiKvadrat(int red, int stupac) {
	int kvadrat = -1;

	if (red < 3) {
		if (stupac < 3) kvadrat = 1;
		else if (stupac < 3 * 2) kvadrat = 2;
		else if (stupac < 3 * 3) kvadrat = 3;
	}
	else if (red < 3 * 2) {
		if (stupac < 3) kvadrat = 4;
		else if (stupac < 3 * 2) kvadrat = 5;
		else if (stupac < 3 * 3) kvadrat = 6;
	}
	else {
		if (stupac < 3) kvadrat = 7;
		else if (stupac < 3 * 2) kvadrat = 8;
		else if (stupac < 3 * 3) kvadrat = 9;
	}

	return kvadrat;
}

int main() {
	int matrica[N][N] = { {0} };
	int errRedak = -1, errStupac = -1, errKvadrat = -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		{
			matrica[i][j] = ucitajSudoku();
		}
	}

	int error = ispravnostReda(matrica, &errStupac, &errRedak, &errKvadrat);

	if (!error) error = ispravnostStupca(matrica, &errStupac, &errRedak, &errKvadrat);

	if (error) {
		printf("Neispravno!\nGreska u: %d. redak, %d. stupac, %d. kvadrat.\n", errRedak + 1, errStupac + 1, errKvadrat);
	}
	else {
		printf("Ispravno!\n");
	}
}