#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void main() {
	double len;

	scanf("%lf", &len);

	printf("Daska se ");

	if (len < 1) {
		printf("ne pili!");
	}
	else if (len < 3) {
		printf("pili na 2 dijela");
	}
	else if (len < 8) {
		printf("pili na 3 dijela");
	}
	else {
		printf("pili na 4 dijela");
	}
}