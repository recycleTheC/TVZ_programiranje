#define _CRT_SECURE_NO_WARNINGS

/*
Napisati funkciju koja æe transformirati niz znakova tako da se zadani podniz u nizu zamjenjuje (jednim) uskliènikom.
Funkcija ima prototip
int zamijeni(char *niz, const char *podniz)
Funkcija vraæa broj obavljenih zamjena.
*/

#include<stdio.h>
#include<string.h>

int zamijeni(char* niz, const char* podniz) {

	int n = 0;

	while (1) {
		char* pocetakPodniza = strstr(niz, podniz);
		int index = pocetakPodniza - niz;

		if (pocetakPodniza == NULL) break;

		niz[index] = '!';

		strcpy(&niz[index + 1], pocetakPodniza + strlen(podniz));

		n++;
	}

	return n;
}

int main() {
	char niz[512] = { 0 };
	char podniz[512] = { 0 };

	scanf("%s %s", niz, podniz);

	int rezultat = zamijeni(niz, podniz);

	printf("%s\n%d\n", niz, rezultat);
}