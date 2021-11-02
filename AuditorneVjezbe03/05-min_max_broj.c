#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void main() {
	int n, i, br;
	int min, max;

	scanf("%d", &n);
	scanf("%d", &br);

	min = br;
	max = br;

	for (i = 1; i < n; i++) {
		scanf("%d", &br);

		if (br < min) min = br;
		else if (br > max) max = br;
	}

	printf("\n%d", min);
	printf("\n%d", max);
}