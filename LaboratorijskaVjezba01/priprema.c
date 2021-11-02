#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>

int pretvarac(char zn, int baza, int poz);
void ispis(int broj, int baza, int nZn);

void main() {
	char ulaz[4];
	int i, broj = 0, ok = 0;
	
	for (i = 0; i < 4; i++) {
		scanf("%c", &ulaz[i]);
	}

	if (ulaz[0] == '0' && ulaz[1] != 'x') {
		// okatalni zapis

		for (i = 1; i < 4; i++) {
			if (ulaz[i] >= '0' && ulaz[i] <= '7') {
				ok = 1;
			}
			else {
				ok = 0; break;
			}
		}

		if (ok) {
			for (i = 1; i < 4; i++) {
				broj += pretvarac(ulaz[i], 8, 3 - i);
			}
			ispis(broj, 8, 3);
		}
		else {
			printf("Pogresan unos!\n");
		}
	}
	else if (ulaz[0] == '0' && ulaz[1] == 'x') {
		// heksadekadski zapis

		for (i = 2; i < 4; i++) {
			if ((ulaz[i] >= '0' && ulaz[i] <= '9') || (ulaz[i] >= 'A' && ulaz[i] <= 'F')) {
				ok = 1;
			}
			else {
				ok = 0; break;
			}
		}

		if (ok) {
			broj += pretvarac(ulaz[2], 16, 1);
			broj += pretvarac(ulaz[3], 16, 0);

			ispis(broj, 16, 2);
		}
		else {
			printf("Pogresan unos!\n");
		}
	}
	else {
		printf("Pogresan unos!\n");
	}
}

int pretvarac(char zn, int baza, int poz) {
	
	switch (zn) {
		case '0': return 0;
		case '1': return 1 * pow(baza, poz);
		case '2': return 2 * pow(baza, poz);
		case '3': return 3 * pow(baza, poz);
		case '4': return 4 * pow(baza, poz);
		case '5': return 5 * pow(baza, poz);
		case '6': return 6 * pow(baza, poz);
		case '7': return 7 * pow(baza, poz);
		case '8': return 8 * pow(baza, poz);
		case '9': return 9 * pow(baza, poz);
		case 'A': return 10 * pow(baza, poz);
		case 'B': return 11 * pow(baza, poz);
		case 'C': return 12 * pow(baza, poz);
		case 'D': return 13 * pow(baza, poz);
		case 'E': return 14 * pow(baza, poz);
		case 'F': return 15 * pow(baza, poz);
	}

	return -1;
}

void ispis(int broj, int baza, int nZn) {
	int i, mask, n;

	n = (int)(log(baza) / log(2)) * nZn;
	
	for (i = n-1; i >= 0; i--) {
		mask = broj & (1 << i);
		if (mask != 0) printf("1");
		else printf("0");
	}
}