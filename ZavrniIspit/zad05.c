#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int* generirajNiz(int n);
void ispisiNiz(int* niz, int n);

int main() {
    srand(time(NULL));

    int* niz = generirajNiz(100);
    ispisiNiz(niz, 100);
}

int* generirajNiz(int n) {
    int* niz = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        // rand() % (max-min+1) + min
        niz[i] = rand() % (87 - 17 + 1) + 17;
    }

    return niz;
}

void ispisiNiz(int* niz, int n) {
    for (int i = 0; i < n; i++) {
        printf("%3d", niz[i]);
        if ((i + 1) % 5 == 0) printf("\n");
    }
}