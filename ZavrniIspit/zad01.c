#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int suma(int n);

int main() {
	int n;

	scanf("%d", &n);

	int rezultat = suma(n);
	printf("%d\n", rezultat);

	return 0;
}

int suma(int n) {
	return ((n / 2.0) * (1 + n));
}