#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>

#define MAX 100

int main() {
	int niz[MAX] = {0}, n, m;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &niz[i]);
	}

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);

		int lok = y - 1;

		for (int j = n - 1; j >= lok; j--) {
			niz[j + 1] = niz[j];
		}

		niz[lok] = x;
		n++;

		for (int j = 0; j < n; j++) {
			printf("%d ", niz[j]);
		}
		printf("\n");
	}
}