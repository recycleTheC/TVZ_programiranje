#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define MAX 100

int main() {
	int x, y, a, b;

	scanf("%d %d", &x, &y);

	while (!(x >= 1 && x <= 100 && y >= 1 && y <= 100)) {
		printf("Krivi unos brojeva X i Y!\n");
		scanf("%d %d", &x, &y);
	}

	scanf("%d %d", &a, &b);
	int ispis = 0;

	for (int i = y - 1; i >= x; i--)
	{
		int dj1 = i % a;
		int dj2 = i % b;

		if ((dj1 && !dj2) || (dj2 && !dj1)) {
			if (ispis) printf(", ");
			printf("%d", i);
			ispis++;
		}
	}
}