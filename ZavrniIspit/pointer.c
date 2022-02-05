#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {
	int a, b;
	int* pA = &a, * pB = &b;

	*pA = 8;
	*pB = 11;

	int** pp = &pB;

	**pp = (*pA) * (*pA);
}