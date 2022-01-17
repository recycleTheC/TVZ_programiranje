#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int jeLiPalindrom(const char* string, int tolerantni);

int main() {

	int tolerancija; char unos[256];

	scanf("%s %d", unos, &tolerancija);

	int rezultat = jeLiPalindrom(unos, tolerancija);

	printf("%s ", unos);

	if (rezultat) printf("je ");
	else printf("nije ");

	printf("tolerantni palindrom.\n");

	return 0;
}

char* reverse(char* string) {
	int len = strlen(string);

	char* reversed = (char*)calloc(len + 1, sizeof(char));

	for (int i = 0; i < len; i++)
	{
		reversed[i] = string[len - i - 1];
	}

	return reversed;
}

int jeLiPalindrom(const char* string, int tolerantni) {

	int len = strlen(string);

	char* obrnuti = reverse(string);

	int podudaranje = 0;

	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] == obrnuti[i]) podudaranje++;
	}

	free(obrnuti);

	if (podudaranje >= (len - 2 * tolerantni)) return 1;
	else return 0;
}