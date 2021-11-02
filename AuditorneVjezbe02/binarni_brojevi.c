#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void main() {
	char a1, a2, a3, a4, a5;
	int br = 0;
	
	scanf("%c%c%c%c%c", &a1, &a2, &a3, &a4, &a5);

	if (a1 > '1' || a2 > '1' || a3 > '1' || a4 > '1' || a5 > '1') {
		printf("Pogresan unos!");
		return;
	}

	if (a2 == '1') {
		br |= 1 << 3;
	}

	if (a3 == '1') {
		br |= 1 << 2;
	}

	if (a4 == '1') {
		br |= 1 << 1;
	}

	if (a5 == '1') {
		br |= 1;
	}

	if (a1 == '1') {
		br ^= 15;
		br = (br * -1) - 1;
	}

	printf("%d", br);
}