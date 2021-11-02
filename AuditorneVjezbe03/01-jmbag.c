#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void main() {
	int x, rez = -1;

	for (int i = 1; i <= 13; i++) {
		scanf("%d", &x);

		if (i == 10) {
			if (x == 0) rez = 0;
			else if (x == 5) rez = 1;
		}
	}

	if (rez == 0) printf("Musko");
	else if (rez == 1) printf("Zensko");
	else printf("Greska");
}