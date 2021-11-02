#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void main() {
	int n, i;

	do {
		scanf("%d", &n);
	} while (n <= 0 || n > 10000000);

	for (int x = 1; x <= n; x++) {
		int sumaDj = 1;

		for (int i = 2; i * i <= x; i++) {
			if (x % i == 0) {
				sumaDj += i;
				if (i * i != x) {
					sumaDj += x / i;
				}
			}
		}

		// Ako je x savrsen broj, ispisujemo ga

		if (sumaDj == x) {
			printf("%d ", x);
		}
	}
}