#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {
	int x;

	scanf("%d", &x);

	int s = x % 60;
	x /= 60;
	int min = x % 60;
	x /= 60;
	int h = x % 24;
	x /= 24;
	int d = x;
	

	printf("%d dan\n", d);
	printf("%02d h\n", h);
	printf("%02d min\n", min);
	printf("%02d s\n", s);
}