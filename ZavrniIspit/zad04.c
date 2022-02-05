#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void vrijeme(long sek);

int main() {
	long n;
	scanf("%ld", &n);
	vrijeme(n);
}

void vrijeme(long sek) {
	int h = sek / 3600;
	sek %= 3600;

	int min = sek / 60;
	sek %= 60;

	printf("%02d:%02d:%02d\n", h, min, sek);
}