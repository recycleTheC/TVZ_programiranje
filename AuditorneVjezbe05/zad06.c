// Za uèitani element, ispisati koliko je veæih elemanata od njega u matrici

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 25

int main()
{
	char pasnjak[MAX][MAX];
	int n, m; // n = broj redaka, m = broj stupaca

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &pasnjak[i][j]);
		}
	}

	printf("\n\n");

	int ovce = 0;
	int maxOvaca = 0, bestRed = -1, bestStupac = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%c", pasnjak[i][j]);

			if (pasnjak[i][j] == '*') ovce++;
		}
		printf("\n");
	}

	for (int i = 0; i < n-4; i++) {
		for (int j = 0; j < m-4; j++) {
			int ovajTor = 0;

			for (int k = 0; k < 4 && i+k < n; k++) {
				for (int l = 0; l < 4 && j+l < m; l++) {
					ovajTor++;
				}
			}

			if (ovajTor > maxOvaca) {
				maxOvaca = ovajTor;
				bestRed = i;
				bestStupac = j;
			}
		}
	}

	printf("(%d,%d) = %d", bestRed + 1, bestStupac + 1, maxOvaca);

	return 0;
}