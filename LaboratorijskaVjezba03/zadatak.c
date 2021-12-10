#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define N 10
#define M 5

// 0 - postaja
// 1 - vjetar
// 2 - temp
// 3 - vlaznost
// 4 - tlak

int main() {
	int n;

	scanf("%d", &n);

	while (!(n >= 3 && n <= 10)) {
		printf("Ponovi unos!\n");
		scanf("%d", &n);
	}

	int postaje[N][M] = { 0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &postaje[i][j]);
		}
	}

	double arsr = 0; int nManjeOdProsj = 0;

	for (int i = 0; i < n; i++) {
		arsr += postaje[i][2];
	}

	arsr /= n;

	int manjeOdProsjeka[N][M] = { 0 };

	for (int i = 0; i < n; i++) {
		if (postaje[i][2] < arsr) {
			for (int j = 0; j < M; j++) {
				manjeOdProsjeka[nManjeOdProsj][j] = postaje[i][j];
			}
			nManjeOdProsj++;
		}
	}

	for (int i = 0; i < nManjeOdProsj; i++) {
		printf("%03d ", manjeOdProsjeka[i][0]);
		for (int j = 1; j < M; j++) {
			printf("%d ", manjeOdProsjeka[i][j]);
		}
		printf("\n");
	}

	int maxTlak = manjeOdProsjeka[0][4];
	int maxTlakPost[N][M] = { {0} };
	int nMaxTlak = 1;

	for (int j = 0; j < M; j++) {
		maxTlakPost[0][j] = manjeOdProsjeka[0][j];
	}

	for (int i = 1; i < nManjeOdProsj; i++) {
		if (manjeOdProsjeka[i][4] >= maxTlak) {
			maxTlak = manjeOdProsjeka[i][4];
			for (int j = 0; j < M; j++) {
				maxTlakPost[nMaxTlak][j] = manjeOdProsjeka[i][j];
			}
			nMaxTlak++;
		}
	}

	int nMaxTlak1 = 0;
	int maxTlakPostKonacni[N][M] = { {0} };

	for (int i = 0; i < nMaxTlak; i++) {
		if (maxTlakPost[i][4] >= maxTlak) {
			for (int j = 0; j < M; j++) {
				maxTlakPostKonacni[nMaxTlak1][j] = maxTlakPost[i][j];
			}
			nMaxTlak1++;
		}
	}

	printf("\n\nNajvisi tlak:\n");

	for (int i = 0; i < nMaxTlak1; i++) {
		printf("%03d ", maxTlakPostKonacni[i][0]);
		for (int j = 1; j < M; j++) {
			printf("%d ", maxTlakPostKonacni[i][j]);
		}
		printf("\n");
	}
}