#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void main() {
	int i, n;

	scanf("%d", &n);

	for (i = 1; i <= (n * 2) - 1; i++) {
		if (i <= n) {
			printf("%d ", i);
		}
		else {
			printf("%d ", 2*n-i);
		}
	}
}