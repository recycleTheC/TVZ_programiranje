#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 512

int main() {
	int n, max = 0;

	scanf("%d", &n);

	int* niz = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++)
	{
		int sel;
		scanf("%d", &sel);

		niz[sel] += 1;

		if (sel > max) max = sel;
	}

	for (int i = 0; i <= max; i++)
	{
		printf("%d: ", i);
		int k = ((double)niz[i] / n) * 100;

		for (int j = 0; j < k; j++)
		{
			printf("x");
		}

		printf("\n");
	}

	return 0;
}
