#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CRNA_F 'C'
#define BIJELA_F 'B'
#define BIJELO_P 'O'
#define CRNO_P 'X'

char** napraviMatircu(int n, int m);

int main() {
	
	int n, m;

	scanf("%d %d", &n, &m);

	char** matrica = napraviMatircu(n, m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int odabir = (i + j) % 2;

			if (odabir == 1) matrica[i][j] = CRNO_P;
			else matrica[i][j] = BIJELO_P;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrica[i][j] = CRNA_F;
		}
	}

	for (int i = n - 2; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrica[i][j] = BIJELA_F;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%c", matrica[i][j]);
		}
		printf("\n");
	}
}

char** napraviMatircu(int n, int m) {

	char** matrica = (char**)malloc(sizeof(char*) * n);

	for (int i = 0; i < n; i++)
	{
		matrica[i] = (char*)calloc(m, sizeof(char));
	}

	return matrica;
}