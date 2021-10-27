#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void main() { // ugly rjesenje
	int br, last, ok = 0;
	char spol = 'n';

	scanf("%d", &br); // 1

	last = br;
	scanf("%d", &br); // 2

	last = br;
	scanf("%d", &br); // 3

	last = br;
	scanf("%d", &br); // 4

	last = br;
	scanf("%d", &br); // 5

	last = br;
	scanf("%d", &br); // 6

	last = br;
	scanf("%d", &br); // 7

	last = br;
	scanf("%d", &br); // 8

	last = br;
	scanf("%d", &br); // 9

	if (br == 3 && last == 3) ok = 1;

	scanf("%d", &br); // 10
	if (br == 0) spol = 'm';
	else if (br == 5) spol = 'z';
	
	scanf("%d", &br); // 11
	scanf("%d", &br); // 12
	scanf("%d", &br); // 13

	if (ok) {
		switch (spol)
		{
			case 'm': printf("Musko!"); break;
			case 'z': printf("Zensko!"); break;
			default: printf("Greska!");
		}
	}
	else printf("Greska!");
}