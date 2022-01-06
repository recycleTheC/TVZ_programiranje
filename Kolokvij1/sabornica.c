#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>

#define MAX 250

int main() {
	int sabornica[MAX][MAX] = { {0} };
	int m, n, sjednice;

	scanf("%d %d", &m, &n);
	scanf("%d", &sjednice);

	for (int k = 0; k < sjednice; k++)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int zastupnik;
				scanf("%d,", &zastupnik);
				sabornica[i][j] += zastupnik;
			}
		}
	}

	int ljencine = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (sabornica[i][j] < 1) {
				printf(" -");
				ljencine++;
			}
			else printf(" 0");
		}
		printf("\n");
	}

	if (ljencine) {
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (sabornica[i][j] < 1) {
					printf("Ukoriti (%d, %d).\n", i + 1, j + 1);
				}
			}
		}
	}
}