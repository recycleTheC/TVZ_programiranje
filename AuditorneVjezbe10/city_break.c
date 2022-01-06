#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100


int main() {

	int k, n, kg[MAX], vrijednost[MAX], a, b, i, j, zbroj_kg = 0, zbroj_vrijed = 0, naj_vrijed = 0;

	scanf("%d%d", &k, &n);

	for (i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		kg[i] = a;
		vrijednost[i] = b;
	}

	for (i = 0; i < n; i++) {
		zbroj_kg = kg[i];
		zbroj_vrijed = vrijednost[i];
		if (zbroj_kg <= k) {
			if (zbroj_vrijed > naj_vrijed) {
				naj_vrijed = zbroj_vrijed;
			}
		}
		for (j = i + 1; j < n; j++) {
			zbroj_kg += kg[j];
			zbroj_vrijed += vrijednost[j];
			if (zbroj_kg <= k) {
				if (zbroj_vrijed > naj_vrijed) {
					naj_vrijed = zbroj_vrijed;
				}
			}
			if (zbroj_kg > k) {
				zbroj_kg -= kg[j];
				zbroj_vrijed -= vrijednost[j];
			}
		}
	}

	for (i = n-1; i >= 0; i--) {
		zbroj_kg = kg[i];
		zbroj_vrijed = vrijednost[i];
		if (zbroj_kg <= k) {
			if (zbroj_vrijed > naj_vrijed) {
				naj_vrijed = zbroj_vrijed;
			}
		}
		for (j = i - 1; j >= 0; j--) {
			zbroj_kg += kg[j];
			zbroj_vrijed += vrijednost[j];
			if (zbroj_kg <= k) {
				if (zbroj_vrijed > naj_vrijed) {
					naj_vrijed = zbroj_vrijed;
				}
			}
			if (zbroj_kg > k) {
				zbroj_kg -= kg[j];
				zbroj_vrijed -= vrijednost[j];
			}
		}
	}

	printf("%d", naj_vrijed);
}