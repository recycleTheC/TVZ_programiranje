#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void obradaArgumenata(char* args[], char** nazivDatoteke, int* min, int* max, int* n, int* nRed);
int* generirajNiz(int n, int min, int max);

int main(int argc, char* args[]) {
    int min, max, n, nRed;
    char* nazivDatoteke = NULL;

    if (argc != 6) exit(1);

    obradaArgumenata(args, &nazivDatoteke, &min, &max, &n, &nRed);

    int* niz = generirajNiz(n, min, max);

    FILE* datoteka = fopen(nazivDatoteke, "w");

    for (int i = 0; i < n; i++) {
        fprintf(datoteka, "%d ", niz[i]);
        if ((i + 1) % nRed == 0) fprintf(datoteka, "\n");
    }

    fclose(datoteka);

    return 0;
}

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

void obradaArgumenata(char* args[], char** nazivDatoteke, int* min, int* max, int* n, int* nRed) {
    *nazivDatoteke = (char*)calloc(strlen(args[1]) + 1, sizeof(char));
    strcpy(*nazivDatoteke, args[1]);

    *min = pretvoriUInt(args[2]);
    *max = pretvoriUInt(args[3]);
    *n = pretvoriUInt(args[4]);
    *nRed = pretvoriUInt(args[5]);
}

int* generirajNiz(int n, int min, int max) {
    int* niz = (int*)calloc(n, sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        niz[i] = rand() % (max - min + 1) + min;
    }

    return niz;
}