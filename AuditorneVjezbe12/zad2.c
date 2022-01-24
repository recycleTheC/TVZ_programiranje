#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int a, b;

	sscanf(argv[1], "%d", &a);
	sscanf(argv[2], "%d", &b);

	printf("%d + %d = %d", a, b, a + b);

	return 0;
}