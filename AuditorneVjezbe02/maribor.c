#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {
	unsigned int D, M, G, H, m, s;
	// unsigned int D1, M1, G1, H1, m1, s1;
	unsigned long vrijeme = 0;

	scanf("%d %d %d %d %d %d", &D, &M, &G, &H, &m, &s);

	while (G < 1900 || G > 2015) {
		scanf("%d %d %d %d %d %d", &D, &M, &G, &H, &m, &s);
	}

	scanf("%d", &vrijeme);

	s += vrijeme % 60;
	vrijeme /= 60;

	if (s / 60 > 0) {
		m += s / 60;
		s %= 60;
	}

	m += vrijeme % 60;
	vrijeme /= 60;

	if (m / 60 > 0) {
		H += m / 60;
		m %= 60;
	}

	H += vrijeme % 24;
	vrijeme /= 24;

	if (H / 24 > 0) {
		D += H / 24;
		H %= 24;
	}

	int daniMj = 30, daniG = 365;

	switch (M) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		daniMj = 31;
		break;

	case 6:
	case 9:
	case 4:
	case 11:
		daniMj = 30;
		break;

	case 2:
		if (G % 100 == 0 && G % 400 == 0) {
			daniG = 366;
			daniMj = 29;
		}
		else {
			daniG = 365;
			daniMj = 28;
		}

	}

	// tu je broj dana u vrijeme

	D += vrijeme;

	if (D / daniMj > 0) {
		M += D / daniMj;
		D %= daniG;
		D %= daniMj;
	}

 	if (M / 12 > 0) {
		G += M / 12;
		if (M % 12 == 0) M = 1;
		else M %= 12;
	}

	printf("%d %d %d %d %d %d", D, M, G, H, m, s);
 }