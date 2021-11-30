#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>

#define MAX 100

int main() {

	double sirina, duzina, razmak;
	int objekti = 0;

	scanf("%lf %lf", &duzina, &sirina);
	double povrsina = duzina * sirina;

	while (povrsina < 1.0 || povrsina > 100.00) {
		printf("Unesena povrsina nije odgovarajuca. Ponovite unos.\n");
		scanf("%lf %lf", &duzina, &sirina);
		povrsina = duzina * sirina;
	}

	scanf("%lf", &razmak);
	scanf("%d", &objekti);

	int mat[MAX][MAX] = { { 0 } }; // 1 - objekt, 2 - student, 3 - razmak
	int lokI, lokJ;

	if (objekti != 0) {
		int zauzece;

		for (int i = 0; i < objekti; i++) {
			scanf("%d %d %d", &zauzece, &lokI, &lokJ);

			for (int j = 0; j < zauzece; j++) {
				mat[lokI][lokJ + j] = 1;
			}
		}
	}

	for (int s = 0; s < duzina + 1; s++) { // stupac
		for (int r = 0; r < sirina + 1; r++) { // redak
			if (mat[r][s] == 1 || mat[r][s] == 3) continue;
			else mat[r][s] = 2;
		}
	}

	lokI = -1, lokJ = -1;

	for (int s = 0; s < duzina; s++) { // stupac
		for (int r = 0; r < sirina; r++) { // redak
			if (mat[r][s] == 2) {
				for (int j = 0; j < duzina; j++) { // stupac
					for (int i = 0; i < sirina; i++) { // redak
						if (r == i && s == j) continue;

						if (mat[i][j] == 2) {
							if (s < j) {
								lokJ = j - 1;
							}
							else if (s > j) {
								lokJ = j + 1;
							}
							else {
								lokJ = j;
							}

							if (r < i) {
								lokI = i - 1;
							}
							else if (r > i) {
								lokI = i + 1;
							}
							else {
								lokI = i;
							}

							double udaljenost = sqrt((r - lokI) * (r - lokI) + (s - lokJ) * (s - lokJ));

							if (udaljenost < razmak) {
								mat[i][j] = 3;
							}
						}
					}
				}
			}
		}
	}

	int n = 0;

	for (int i = 0; i < sirina; i++) {
		for (int j = 0; j < duzina; j++) {
			switch (mat[i][j]) {
			case 0: printf("Z "); break;
			case 1:
				printf("X "); break;
			case 2:
				printf("S ");
				n++;
				break;
			case 3:
				printf("O "); break;
			}
		}
		printf("\n");
	};

	printf("\nU prostoriju stane ukupno osoba: %d.", n);

	return 0;
}