#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void main() {
	double iznos;
	scanf("%f", &iznos);

	int petsto = iznos / 500;
	printf("%d x 500\n", petsto);
	iznos -= petsto * 500;

	int dvjesto = iznos / 200;
	printf("%d x 200\n", dvjesto);
	iznos -= dvjesto * 200;

	int sto = iznos / 100;
	printf("%d x 100\n", sto);
	iznos -= sto * 100;

	int pedeset = iznos / 50;
	printf("%d x 50\n", pedeset);
	iznos -= pedeset * 50;

	int dvadeset = iznos / 20;
	printf("%d x 20\n", dvadeset);
	iznos -= dvadeset * 20;

	int deset = iznos / 10;
	printf("%d x 10\n", deset);
	iznos -= dvadeset * 10;
}