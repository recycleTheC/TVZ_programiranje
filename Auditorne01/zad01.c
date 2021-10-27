#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void main() {
	double iznos = 943.3;
	// scanf("%f", &iznos);

	int petsto = iznos / 500;
	printf("%d x 500\n", petsto);
	iznos -= petsto * 500;

	int dvjesto = iznos / 200;
	printf("%d x 200\n", dvjesto);
	iznos -= dvjesto * 200;

	int sto = iznos / 100;
	printf("%d x 100\n", sto);
	iznos -= sto * 100;


}