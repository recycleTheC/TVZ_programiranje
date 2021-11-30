#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int main() {
	int br[MAX] = { 0 }, i, j, n = 4, k, postoji;

	for (i = 0; i < n; i++) {
		scanf("%d", &br[i]);
	}

	while(1){
		scanf("%d", &k);

		postoji = 0;

		for (i = 0; i < n; i++) {
			if (k == br[i]) {
				postoji = 1;
				for (j = n; j > i; j--) {
					br[j] = br[j - 1];
				}
				br[i] /= 2;
				br[i + 1] = (br[i + 1] / 2) + 1;
				
				n++;
			}
		}

		if (!postoji) break;

		for (i = 0; i < n; i++) printf("%d ", br[i]);
		printf("\n");
	}
}