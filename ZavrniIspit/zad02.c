#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    int umn = 1;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) umn *= i;
    }

    printf("%d", umn);

    return 0;
}