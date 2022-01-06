#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int main() {
	int niz[MAX] = { 0 }, n, k, nMax = 0, nMin = 0, x = 0;
	int sortirano[MAX] = { 0 };

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &niz[i]);
		sortirano[i] = niz[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (sortirano[i] < sortirano[j]) {
				int temp = sortirano[i];
				sortirano[i] = sortirano[j];
				sortirano[j] = temp;
			}
		}
	}

	int max[MAX] = { 0 };

	for (int i = 0; i < n; i++)
	{
		int ok = 1;

		for (int j = 0; j < k; j++)
		{
			if (niz[i] == sortirano[j]) {
				ok = 0;
				break;
			}
		}

		if (ok) {
			max[x] = niz[i];
			x++;
		}
	}

	for (int i = 0; i < x; i++)
	{
		printf("%d ", max[i]);
	}

	int min[MAX] = { 0 };

	printf("\n");

	x = 0;

	for (int i = 0; i < n; i++)
	{
		int ok = 1;

		for (int j = 0; j < k; j++)
		{
			if (niz[i] == sortirano[n-j-1]) {
				ok = 0;
				break;
			}
		}

		if (ok) {
			min[x] = niz[i];
			x++;
		}
	}

	for (int i = 0; i < x; i++)
	{
		printf("%d ", min[i]);
	}

	printf("\n");
}