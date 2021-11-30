#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {
	int broj, n = 0;

	scanf("%d", &broj);

	if (broj <= 1) {
		printf("0");
		return 0;
	}

	for (int i = 2; i*i <= broj; i++)
	{
		if (broj % (i * i) == 0) n++;
	}

	printf("%d", n);
}