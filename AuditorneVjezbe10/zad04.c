#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

/*
C - crne figure
B - bijele figure
O (slovo O kao Ogulin) - bijelo polje
X - crno polje
*/

void upisi(char** polje, int redak, int stupac, char znak) {
	polje[redak][stupac] = znak;
}

void ispisi(char** polje, int red, int stupac) {
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < stupac; j++)
		{
			printf("%c", polje[i][j]);
		}
		printf("\n");
	}
}

int main() {

	int m, n;

	scanf("%d %d", &m, &n);

	char** ploca = (char**)malloc(sizeof(char**) * m);

	for (int i = 0; i < m; i++)
	{
		ploca[i] = (char*)calloc(n, sizeof(char*));
	}

	for (int i = 0; i < m; i++)
	{
		int k = i % 2;

		for (int j = 0; j < n; j++)
		{
			char upis;

			if (k) {
				upis = 'X';
				k = 0;
			}
			else {
				upis = 'O';
				k = 1;
			}

			upisi(ploca, i, j, upis);
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char polje = ploca[i][j];

			if (polje == 'X') {
				upisi(ploca, i, j, 'C');
			}
		}
	}

	for (int i = m - 2; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char polje = ploca[i][j];

			if (polje == 'X') {
				upisi(ploca, i, j, 'B');
			}
		}
	}

	ispisi(ploca, m, n);

	return 0;
}
