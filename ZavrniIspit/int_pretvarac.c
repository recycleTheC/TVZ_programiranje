#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int pretvoriUInt(char* string) {
    int zbr = 0, k = 1;

    for (int i = strlen(string) - 1; i >= 0; i--) {
        if (string[i] >= '0' && string[i] <= '9') {
            zbr += (string[i] - '0') * k;
            k *= 10;
        }
    }

    return zbr;
}

int main() {
    char niz[64] = { 0 };

    scanf("%s", niz);
    int broj = pretvoriUInt(niz);

    return 0;
}