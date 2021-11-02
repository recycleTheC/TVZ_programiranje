#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void main() {
	int a, b, c, min;

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	min = a;

	if (b > min) min = b;
	if (c > min) min = c;

	for (int i = min; i >= 1; i--) {
		if (a % i == 0 && b % i == 0 && c % i == 0) {
			printf("%d", i);
			break;
		}
	}
}