#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 50

int main() {
	int br[MAX], i, parni = 0; // neparni = 0;

	srand(time(NULL));

	for (i = 0; i < MAX; i++) {
		br[i] = rand();
	}

	for (i = 0; i < MAX; i++) {
		if (br[i] % 2 == 0) parni++;
	}

	printf("Parni: %d\n", parni);
	// printf("Neparni: %d", neparni);
	printf("Neparni: %d", 50 - parni); // dobar trik :)
}