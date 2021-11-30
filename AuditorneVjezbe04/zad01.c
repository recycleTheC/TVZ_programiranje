#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	int i, br[20], min, max;

	srand(time(NULL));

	for (i = 0; i < 20; i++) {
		br[i] = rand() % 201;
	}

	min = br[0];
	max = br[0];

	for (i = 1; i < 20; i++) {
		if (br[i] < min) min = br[i];
		if (br[i] > max) max = br[i];
	}

	printf("Min: %d\nMax: %d", min, max);
}