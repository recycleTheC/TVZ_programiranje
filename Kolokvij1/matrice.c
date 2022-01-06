#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {
	char polje[10][10] = { {0} };
	int m, n, p, q;

	scanf("%dx%d", &m, &n);
	scanf("%dx%d", &p, &q);

	while (!(m >= 3 && m <= 10 && n >= 3 && n <= 10)) {
		printf("Nedozvoljena dimenzija polja!\n");
		scanf("%dx%d", &m, &n);
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			polje[i][j] = '-';
		}
	}

	
}