#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define MAX 100

int main() {
	char mat[MAX][MAX] = { {0} };
	int m, n, k;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf(" %c", &mat[i][j]);
		}
	}

	scanf("%d", &k);

	for (int x = 0; x < k; x++)
	{
		char selector, zamjeni;

		scanf(" %c %c", &selector, &zamjeni);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (mat[i][j] == selector) {
					mat[i][j] = zamjeni;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%c", mat[i][j]);
		}
		printf("\n");
	}
}