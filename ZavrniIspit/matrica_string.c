#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

#define N 10

int sadrziLiString(char mat[][N], char string[]);

int main() {
	char mat[N][N] = { {"Ana voli "}, {"Milovana"} };
	char rec[100] = { 0 };

	scanf("%[^\n]", rec);

	int rez = sadrziLiString(mat, rec);

	printf("%d\n", rez);
}

int sadrziLiString(char mat[][N], char string[]) {
	char upisano1[100] = { 0 };
	char upisano2[100] = { 0 };

	int k = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (mat[i][j] != '\0') {
				upisano1[k] = mat[i][j];
				k++;
			}
		}
	}

	k = 0;

	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = N - 1; j >= 0; j--)
		{

			if (mat[i][j] != '\0') {
				upisano2[k] = mat[i][j];
				k++;
			}
		}
	}

	if (strcmp(upisano1, string) == 0) return 1;
	else if (strcmp(upisano2, string) == 0) return 1;
	else return 0;
}