#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define MAX 25 // 'Z' - 'A'

int main() {
	char znak, abeceda[MAX];
	int i, pojava[MAX] = { 0 };

	for (i = 0; i < MAX; i++) {
		abeceda[i] = 'a' + i;
	}

	scanf("%c", &znak);

	while (znak != '*') {
		for (i = 0; i < MAX; i++) {
			if (znak >= 'A' && znak <= 'Z') znak += 32;

			if (znak == abeceda[i]) {
				pojava[i] += 1;
				break;
			}
		}
		scanf("%c", &znak);
	}

	for (i = 0; i < MAX; i++) {
		if (pojava[i] != 0) {
			printf("%c: %d\n", abeceda[i], pojava[i]);
		}
	}

}