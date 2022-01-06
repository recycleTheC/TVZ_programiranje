#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 512

char* najduljiPodniz(char* niz1, char* niz2, char* niz3);
char* nadjiPodniz(char* niz, int n);

int main() {
	char niz[MAX] = { 0 };

	scanf("%s", niz);

	//_strlwr(niz);

	char* podniz1 = NULL, * podniz2 = NULL, * podniz3 = NULL;

	podniz1 = nadjiPodniz(niz, 1);
	podniz2 = nadjiPodniz(niz, 2);
	podniz3 = nadjiPodniz(niz, 3);

	char* najdulji = najduljiPodniz(podniz1, podniz2, podniz3);

	printf("%s", najdulji);
}

char* nadjiPodniz(char* niz, int n) {
	char* start = niz, * podniz = NULL;
	int len;

	for (int i = 1; i <= n; i++)
	{
		char* end1 = strchr(start, '!');
		char* end2 = strchr(start, '#');
		char* end;

		if (end2) end = end2;
		else if (end1) end = end1;
		else end = niz + strlen(niz);

		len = end - start;

		if (i == n) {
			free(podniz);
			podniz = (char*)calloc(len + 1, sizeof(char));
			strncpy(podniz, start, len);
		}

		start = end + 1;
	}

	return podniz;
}

char* najduljiPodniz(char* niz1, char* niz2, char* niz3) {
	int len = strlen(niz1), k = 0;

	int najmanjaDuljina = strlen(niz1);

	if (strlen(niz2) < najmanjaDuljina) {
		najmanjaDuljina = strlen(niz2);
	}

	if (strlen(niz3) < najmanjaDuljina) {
		najmanjaDuljina = strlen(niz3);
	}

	char** rijeci = (char**)malloc(sizeof(char*) * 1);

	for (int start = 0; start < strlen(niz1) - 2; start++)
	{
		int ok = 0;

		for (int length = 2; length < najmanjaDuljina - 1; length++)
		{
			char* podniz = (char*)calloc(length + 1, sizeof(char));
			strncpy(podniz, niz1 + start, length);

			char* ima1 = strstr(niz2, podniz);
			char* ima2 = strstr(niz3, podniz);

			if (ima1 && ima2) {
				rijeci = (char**)realloc(rijeci, sizeof(char*) * (k + 1));
				rijeci[k] = (char*)calloc(length + 1, sizeof(char));
				strcpy(rijeci[k], podniz);
				k++;
				ok = 1;
			}

			if (podniz) {
				free(podniz);
				podniz = NULL;
			}
		}

		if (ok) break;
	}

	int maxLen = strlen(rijeci[0]);
	char* max = rijeci[0];

	for (int i = 1; i < k; i++)
	{
		if (strlen(rijeci[i]) > maxLen) {
			maxLen = strlen(rijeci[i]);
			max = rijeci[i];
		}
	}

	/*for (int i = 1; i < k; i++)
	{
		free(rijeci[i]);
		rijeci[i] = NULL;
	}

	free(rijeci);
	rijeci = NULL;*/

	return max;
}