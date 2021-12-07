#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

void ucitavanje(int p[], int n) {
	for (int i = 0; i < n; i++) {
		scanf("%d", p + i);
	}
}

void popuniRnd(int p[], int n, int min, int max) {
	for (int i = 0; i < n; i++) {
		p[i] = rand() % (max - min + 1) + min; // [min,max]
	}
}

void ispis(int p[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%4d", p[i]);
	}
}

int main() {
	int n, polje[MAX];

	scanf("%d", &n);
	srand(time(NULL));

	//ucitavanje(polje, n);
	popuniRnd(polje, n, 1, 100);
	ispis(polje, n);
}