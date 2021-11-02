#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>

void pretvarac16(char zn);
void pretvarac8(char zn);


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
				pretvarac8(ulaz[i]);
			}
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
			pretvarac16(ulaz[2]);
			pretvarac16(ulaz[3]);
		}
		else {
			printf("Pogresan unos!\n");
		}
	}
	else {
		printf("Pogresan unos!\n");
	}
}

void pretvarac16(char zn) {
	switch (zn) {
	case '0': printf("0000"); break;
	case '1': printf("0001"); break;
	case '2': printf("0010"); break;
	case '3': printf("0011"); break;
	case '4': printf("0100"); break;
	case '5': printf("0101"); break;
	case '6': printf("0110"); break;
	case '7': printf("0111"); break;
	case '8': printf("1000"); break;
	case '9': printf("1001"); break;
	case 'A': printf("1010"); break;
	case 'B': printf("1011"); break;
	case 'C': printf("1100"); break;
	case 'D': printf("1101"); break;
	case 'E': printf("1110"); break;
	case 'F': printf("1111"); break;
	}
}

void pretvarac8(char zn) {
	switch (zn) {
		case '0': printf("000"); break;
		case '1': printf("001"); break;
		case '2': printf("010"); break;
		case '3': printf("011"); break;
		case '4': printf("100"); break;
		case '5': printf("101"); break;
		case '6': printf("110"); break;
		case '7': printf("111"); break;
	}
}