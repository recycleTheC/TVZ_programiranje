#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int a = 2, b = 3;
	float g = 4;

	int* p1 = &a;
	int* p2 = NULL;

	float* pg = &g;
	float** ppg = &pg;

	p2 = &a;
	*p1 = 6;

	printf("%d\n", *p2);

	p1 = &b;

	printf("%d %d %d %d", *p1, *p2, a, b);

	**ppg = 8;

	printf("%f %f %f", g, *pg, *ppg);

	return 0;
}