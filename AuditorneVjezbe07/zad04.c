#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX 100

void ucitajNiz(int* p, int n);
void popuniRandom(char p[], int n, int min, int max);
void ispisiNiz(char* p, int n);
void ubaci(char* p, int *n, char novi, int index);

int main()
{
	srand(time(NULL));

	int n;
	char niz[MAX];

	scanf("%d", &n);

	//ucitajNiz(niz, n);
	popuniRandom(niz, n, 'a', 'z');
	ispisiNiz(niz, n);

	ubaci(niz, &n, 'X', 10);
	ubaci(niz, &n, 'Y', 1);
	ubaci(niz, &n, 'D', 15);

	ispisiNiz(niz, n);
}

void ucitajNiz(char* p, int n) {
	for (int i = 0; i < n; i++) {
		scanf(" %c", p + i);
	}
}

void popuniRandom(char p[], int n, int min, int max) {
	for (int i = 0; i < n; i++) {
		p[i] = rand() % (max - min + 1) + min;
	}
}

void ispisiNiz(char* p, int n) {
	for (int i = 0; i < n; i++) {
		printf("%c ", p[i]);
	}
	printf("\n");
}

void ubaci(char* p, int* n, char novi, int index) {
	for (int i = *n - 1; i >= index; i--) {
		p[i + 1] = p[i];
	}

	p[index] = novi;
	*n += 1;
}