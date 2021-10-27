#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {
	double x, y;

	scanf("%lf %lf", &x, &y);

	double zbr = x + y;

	if (zbr == (int)zbr) printf("%d", (int)zbr);
	else printf("%.1f", zbr);
}