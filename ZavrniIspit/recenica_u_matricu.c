#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

#define N 10
#define M 20

void upisiUMatricu(char mat[][M], char rec[]);

int main() {
	char mat[N][M] = { {0} };
	char rec[200] = { 0 };

	scanf("%[^\n]", rec);

	upisiUMatricu(mat, rec);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%c ", mat[i][j]);
		}
		printf("\n");
	}
}

void upisiUMatricu(char mat[][M], char rec[]) {
	int k = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (k == strlen(rec)) break;

			mat[i][j] = rec[k];
			k++;
		}
	}
}