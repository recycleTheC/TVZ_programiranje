#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void main() {
	int a, b, rez;
	char ch;

	scanf("%d", &a);
	scanf("%c", &ch);
	if(ch != 'K') scanf("%d", &b);

	switch (ch) {
		case '+': rez = a + b; break;
		case '-': rez = a - b; break;
		case '*': rez = a * b; break;
		case '/': rez = a / b; break;
		case 'K': rez = a * a; break;
	}

	printf("%d", rez);
}