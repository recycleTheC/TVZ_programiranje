#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char** izvuciRijeci(char* rec, int* brRijeci) {
	int n = 0, max = 5;

	char** rijeci = (char**)malloc(sizeof(char*) * max);

	while (1) {
		char tmp[255] = { 0 };
		sscanf(rec, " %[^ ]", tmp);
		int len = strlen(tmp);

		rijeci[n] = (char*)calloc(len + 1, sizeof(char));
		strcpy(rijeci[n], tmp);

		n++;

		if (n == max) {
			max += 5;
			rijeci = (char**)realloc(rijeci, sizeof(char*) * max);
		}

		if (*(rec + len) == '\0') break;
		rec += len + 1;
	}

	*brRijeci = n;

	return rijeci;
}

int zbroj(char* rijec) {
	int zbr = 0;

	for (int i = 0; i < strlen(rijec); i++)
	{
		zbr += rijec[i];
	}

	return zbr;
}

char* najveciZbroj(char** rijeci, int brRijeci, int* maxLen) {
	char* najveca = (char*)calloc(100, sizeof(char));

	int max = zbroj(rijeci[0]);
	strcpy(najveca, rijeci[0]);

	for (int i = 1; i < brRijeci; i++)
	{
		int trenutni = zbroj(rijeci[i]);
		if (trenutni > max) {
			strcpy(najveca, rijeci[i]);
			max = trenutni;
		}
	}

	for (int i = 0; i < brRijeci; i++)
	{
		int trenutniZbr = zbroj(rijeci[i]);

		if (trenutniZbr == max) {
			if (strcmp(rijeci[i], najveca) == -1) {
				strcpy(najveca, rijeci[i]);
			}
		}
	}

	*maxLen = max;

	return najveca;
}

int main() {
	int brRijeci, max;
	char rec[255] = { 0 };

	scanf("%[^.].", rec);

	char** rijeci = izvuciRijeci(&rec, &brRijeci);
	char* trazena = najveciZbroj(rijeci, brRijeci, &max);

	printf("%s: %d\n", trazena, max);

	return 0;
}