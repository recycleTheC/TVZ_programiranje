#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 100

int main() {
	int br[MAX], n, i, k = 0;
	int lok[MAX] = { 0 };

	scanf("%d", &n);

	srand(time(NULL));

	for (i = 0; i < MAX; i++) {
		br[i] = (rand() - 21) - 10;
	}

	for (i = 0; i < MAX; i++) {
		if (br[i] == n) {
			lok[k] = i;
			k++;
		}
	}

	printf("Broj pojavljivanja: %d - ", k);

	for (i = 0; i < k; i++) {
		printf("%d ", lok[i]);
	}
}