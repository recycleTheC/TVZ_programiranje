#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>


int main() {
	int n, prvih, posljednjih, k, rez, br = 0, m = 0, niz[512] = {0};

	scanf("%d %d", &n, &k);
	scanf("%d %d", &prvih, &posljednjih);

	for (int i = 1; i <= n; i++)
	{
		if (i % 2 != 0) continue;

		niz[br] = i;
		br++;
	}

	for (int i = 0; i < prvih; i++)
	{	
		rez = niz[i] * k;
		printf("%d\n", rez);
		m = i;
	}

	for (int i = br - posljednjih -1; i > m; i--)
	{
		rez = niz[i] * k;
		printf("%d\n", rez);
	}

	for (int i = br - posljednjih; i < br; i++)
	{
		rez = niz[i] * k;
		printf("%d\n", rez);
	}
}