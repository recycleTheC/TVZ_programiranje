#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void main() {
	int broj, zbr = 0, n = 0;
	double arsr;

	scanf("%d", &broj);

	while (broj > 0) {
		zbr += broj;
		n++;
		scanf("%d", &broj);
	} 

	if (n != 0) {
		arsr = (double)zbr / n;
		printf("%g", arsr);
	}
	else {
		printf("Niste unijeli prirodne brojeve");
	}

}