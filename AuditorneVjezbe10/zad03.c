#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int prostBroj(int broj) {
	if (broj <= 3) {
		return broj > 1;
	}

	if (broj % 2 == 0 || broj % 3 == 0) {
		return 0;
	}

	for (int i = 5; i * i <= broj; i += 6) {
		if (broj % i == 0 || broj % (i + 2) == 0) {
			return 0;
		}
	}

	return 1;
}

int djeljivSa7IliSa9(int broj) {
	if (broj % 7 == 0) return 1;
	if (broj % 9 == 0) return 1;

	return 0;
}

void provjeriUvjete(int a, int b, int* pp, int* pd) {

	*pp = 0;
	*pd = 0;

	for (int i = a; i <= b; i++)
	{
		if (djeljivSa7IliSa9(i)) *pd += 1;
		if (prostBroj(i)) *pp += 1;
	}
}

void provjera(int* a, int* b) {
	if (*a > *b) {
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

void sortiranje(int polje[], int n) {
	int tmp;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (polje[i] > polje[j]) {
				tmp = polje[i];
				polje[i] = polje[j];
				polje[j] = tmp;
			}
		}
	}
}

int main() {

	int n;
	scanf("%d", &n);

	int* rezultati = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		provjera(&a, &b);

		int pp, pd;

		provjeriUvjete(a, b, &pp, &pd);

		rezultati[i] = pp + pd;
	}

	sortiranje(rezultati, n);

	for (int i = 0; i < n; i++)
	{
		if (i > 0) printf(", ");

		printf("%d", rezultati[i]);
	}

	return 0;
}
