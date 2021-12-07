#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>

float* kreirajMatricuUnosom(int n, int m);
float* kreirajMatricuRandom(int n, int m, int min, int max);

float** kreirajMatricuUnosom2(int n, int m);
float** kreirajMatricuRandom2(int n, int m, int min, int max);

void ispisMatrice(float* mat, int n, int m);
void ispisMatrice2(float** mat, int n, int m);

float generirajRandom(int min, int max);

float** ubaciRedak(float** mat, int* pn, int m, int noviRedak);

int main() {

	srand(time(NULL));
	int n = 3, m = 4;

	float** mat = kreirajMatricuRandom2(n, m, 5, 10);
	ispisMatrice2(mat, n, m);

	printf("\n");

	mat = ubaciRedak(mat, &n, m, 1);
	ispisMatrice2(mat, n, m);

	free(mat);

	return 0;
}

float* kreirajMatricuUnosom(int n, int m) {
	float* mat = (float*)malloc(sizeof(float) * n * m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%f", (mat + i * m + j));
		}
	}

	return mat;
}
float* kreirajMatricuRandom(int n, int m, int min, int max) {
	float* mat = (float*)calloc(n * m, sizeof(float));

	// vrijednosti: <min, max]

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			*(mat + i * m + j) = generirajRandom(min, max);
		}
	}

	return mat;
}
void ispisMatrice(float* mat, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%6.2f", *(mat + i * m + j));
		}
		printf("\n");
	}
}

float** kreirajMatricuUnosom2(int n, int m) {
	float** mat = (float**)malloc(sizeof(float) * n);

	for (int i = 0; i < n; i++) {
		mat[i] = (float*)malloc(sizeof(float) * m);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%f", &mat[i][j]);
		}
	}

	return mat;
}
float** kreirajMatricuRandom2(int n, int m, int min, int max) {
	float** mat = (float**)malloc(sizeof(float) * n);

	for (int i = 0; i < n; i++) {
		mat[i] = (float*)malloc(sizeof(float) * m);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mat[i][j] = generirajRandom(min, max);
		}
	}

	return mat;
}

float generirajRandom(int min, int max) {
	float broj;
	int x = rand() % (max - min) + min + 1;

	if (x > min) {
		broj = x + (rand() % 100) / 100.0f;
	}
	else {
		broj = x * 1.0f;
	}

	return broj;
}

void ispisMatrice2(float** mat, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%6.2f", mat[i][j]);
		}
		printf("\n");
	}
}

float** ubaciRedak(float** mat, int* pn, int m, int noviRedak) {

	int n = *pn;

	mat = (float*)realloc(mat, sizeof(float*) * (n + 1));

	for (int i = n - 1; i >= noviRedak; i--) {
		mat[i + 1] = mat[i];
	}

	mat[noviRedak] = (float*)calloc(m, sizeof(float));
	*(pn) += 1;

	return mat;
}