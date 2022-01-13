#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MARIO 'M'
#define ZID '#'
#define PRAZNO '.'

void ispis(char** matrica, int n);
int kretanje(char** matrica, int n, int m);

int main1() {

	int n, m;

	scanf("%d %d", &n, &m);

	char** mat = (char**)malloc(sizeof(char*) * n);

	for (int i = 0; i < n; i++)
	{
		mat[i] = (char*)calloc((m + 1), sizeof(char));
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf(" %c", &mat[i][j]);
		}
	}

	int rezultat = kretanje(mat, n, m);

	ispis(mat, n);

	if (rezultat == m) {
		printf("\n\nUspjeh!");
	}
	else {
		printf("\n\nFail.");
	}

	return 0;
}

void ispis(char** matrica, int n) {
	for (int i = 0; i < n; i++)
	{
		printf("%s\n", matrica[i]);
	}
}

int kretanje(char** matrica, int n, int m) {
	int korak = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrica[i][j] != MARIO) continue;

			if (j == m - 1 && matrica[i][j] == MARIO) {
				korak = j + 1;
			}

			if (matrica[i][j + 1] == PRAZNO) {

				if (i < n - 1) {
					if (matrica[i + 1][j] == PRAZNO) {
						matrica[i + 1][j] = MARIO;
						break;
					}
				}

				matrica[i][j + 1] = MARIO;
				korak = j + 1; // krece od nule
			}

			if (i < n - 1) {
				if (matrica[i + 1][j] == PRAZNO) {
					matrica[i + 1][j] = MARIO;
					break;
				}
			}
		}
	}

	return korak;
}