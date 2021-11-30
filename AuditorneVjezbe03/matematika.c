#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define MAX 100

int main() {
	int len = 0, i, j;
	char izraz[MAX], znak;

	scanf("%c", &znak);

	while (znak != '.') {
		izraz[len] = znak;
		len++;
		scanf("%c", &znak);
	}

	for (i = 0; i < len; i++) {
		if (!((izraz[i] >= '0' && izraz[i] <= '9') || (izraz[i] >= '(' && izraz[i] <= '/') || izraz[i] == '{' || izraz[i] == '}' || izraz[i] == '[' || izraz[i] == ']')) {
			printf("NEISPRAVNO");
			return 0;
		}
	}

	for (i = 0; i < len-1; i++) {
		if (izraz[i] == izraz[i + 1]) { // !(izraz[i] >= '0' && izraz[i] <= '9') && 
			printf("NEISPRAVNO");
			return 0;
		}
	}

	for (i = 0; i < len; i++) {
		int k = 0;
		if (izraz[i] == '(') {
			int ok = 0;
			for (j = len - 1; j > i; j--) {
				if (izraz[j] == ')') {
					ok = 1;
				}
			}

			if (!ok) {
				printf("NEISPRAVNO");
				return 0;
			}
		}
	}
}