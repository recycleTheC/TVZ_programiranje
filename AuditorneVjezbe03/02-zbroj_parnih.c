#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void main() {
	int m, n, zbr = 0;

	do {
		scanf("%d %d", &m, &n);
	} while (!(m < n));


	for (int i = m; i <= n; i++) {
		if (i % 2 == 0) zbr += i;
	}

	printf("%d", zbr);
}