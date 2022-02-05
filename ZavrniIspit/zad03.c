#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void zbrojUmnozak(int n, int* umn, int* zbr);

int main() {
	int  n, umn, zbr;

	scanf("%d", &n);

	zbrojUmnozak(n, &umn, &zbr);

	printf("zbroj: %ld\numnozak: %ld\n", zbr, umn);
}

void zbrojUmnozak(int n, int* umn, int* zbr) {
	*umn = 1;
	*zbr = 0;

	for (int i = 1; i <= n; i++) {
		*zbr += i;
		if (i % 2 == 0) *umn *= i;
	}
}