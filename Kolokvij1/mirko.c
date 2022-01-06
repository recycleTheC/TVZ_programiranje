#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {
	int n = 0, ocjene[6] = {0}, nOcj = 0;
	double arsr = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			int br;
			scanf("%d", &br);

			ocjene[j] += br;

			arsr += ocjene[j] * j;
			nOcj += ocjene[j];
		}
	}

	printf("Za %d razred/razreda\n\n", n);
	printf("bilo je:\n");
	printf("%d nedovoljan, %d dovoljan, %d dobar, %d vrlo dobar i %d odlican\n\n", ocjene[1], ocjene[2], ocjene[3], ocjene[4], ocjene[5]);
	printf("prosjecna ocjena je:\n");

	arsr /= nOcj;
	
	if (arsr < 2) {
		printf("nedovoljan");
	}
	else if (arsr < 2.5) {
		printf("dovoljan");
	}
	else if (arsr < 3.5) {
		printf("dobar");
	}
	else if (arsr < 4.5) {
		printf("vrlo dobar");
	}
	else {
		printf("odlican");
	}

	printf("\n");
}