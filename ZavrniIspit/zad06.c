#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int generirajMatricu(int n, int m, int min, int max) {
    int** matrica = (int**)malloc(sizeof(int*) * n);

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        matrica[i] = (int*)calloc(m, sizeof(int));

        for (int j = 0; j < m; j++) {
            matrica[i][j] = rand() % (max - min + 1) + min;
        }
    }

    return matrica;
}

void ispisMatrica(int** matrica, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%4d", matrica[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 10, m = 10;
    int** matrica = generirajMatricu(n, m, -87, 17);
    ispisMatrica(matrica, n, m);
}