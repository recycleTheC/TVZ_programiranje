#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void main() {
	int s1, s2, s3, s4, s5, s6, s7, s8, s9, s10;
	
	scanf("%d", &s1);
	scanf("%d", &s2);
	scanf("%d", &s3);
	scanf("%d", &s4);
	scanf("%d", &s5);
	scanf("%d", &s6);
	scanf("%d", &s7);
	scanf("%d", &s8);
	scanf("%d", &s9);
	scanf("%d", &s10);

	printf("%c ", s1 + 64);
	printf("%c ", s2 + 64);
	printf("%c ", s3 + 64);
	printf("%c ", s4 + 64);
	printf("%c ", s5 + 64);
	printf("%c ", s6 + 64);
	printf("%c ", s7 + 64);
	printf("%c ", s8 + 64);
	printf("%c ", s9 + 64);
	
	if (s10 == 0) {
		printf("\nKRAJ PORUKE!\n");
	}
	else {
		printf("%c\n", s10 + 64);
	}
}