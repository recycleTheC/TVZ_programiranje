#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
	int id;
	char naziv[100];
	char kategorija[50];
	float duljina;
	int brLezajeva;
	int brSoba;
	int cijenaTjedan;
} Model;

typedef struct {
	char nazivHale[6];
	int modelId; // Jahta -> id
	char imeBroda[128];
	char operater[128];
	char booth[4];
	Model modelBroda;
} Brod;

Model* ucitajModele(int* brModela);
Brod* ucitajBrodove(int* brBrodova, int minCijena, int maxCijena, float minDuljina, float maxDuljina, Model* modeli, int brModela);
void sortiranje(Brod* brodovi, int brBrodova);

int main() {
	int brModela, brBrodova, minCijena, maxCijena;
	float minDuljina, maxDuljina;

	scanf("%d-%d", &minCijena, &maxCijena);
	scanf("%f-%f", &minDuljina, &maxDuljina);

	Model* modeli = ucitajModele(&brModela);
	Brod* brodovi = ucitajBrodove(&brBrodova, minCijena, maxCijena, minDuljina, maxDuljina, modeli, brModela);

	sortiranje(brodovi, brBrodova);

	FILE* datoteka = fopen("rezultat.out", "w");

	for (int i = 0; i < brBrodova; i++)
	{
		fprintf(datoteka, "%s(%s) %s %s %.2f %d EUR\n",
			brodovi[i].nazivHale,
			brodovi[i].booth,
			brodovi[i].modelBroda.naziv,
			brodovi[i].imeBroda,
			brodovi[i].modelBroda.duljina,
			brodovi[i].modelBroda.cijenaTjedan
		);
	}

	fclose(datoteka);

	return 0;
}

Model* ucitajModele(int* brModela) {
	FILE* datoteka = fopen("modeli.dat", "rb");
	if (datoteka == NULL) exit(1);

	fseek(datoteka, 0, SEEK_END);
	int n = ftell(datoteka) / sizeof(Model);
	rewind(datoteka);

	Model* modeli = (Model*)malloc(sizeof(Model) * n);
	if (modeli == NULL) exit(1);

	fread(modeli, sizeof(Model), n, datoteka);

	*brModela = n;

	fclose(datoteka);

	return modeli;
}

Model pronadjiModel(Model* modeli, int brModela, int id) {
	for (int i = 0; i < brModela; i++)
	{
		if (modeli[i].id == id) {
			return modeli[i];
		}
	}
}

Brod* ucitajBrodove(int* brBrodova, int minCijena, int maxCijena, float minDuljina, float maxDuljina, Model* modeli, int brModela) {

	int n = 0, max = 5;

	Brod* brodovi = (Brod*)malloc(sizeof(Brod) * max);
	if (brodovi == NULL) exit(1);

	FILE* datoteka = fopen("sajam.txt", "r");
	if (datoteka == NULL) exit(1);

	Brod temp;

	while (fscanf(datoteka, " %s %d %[^#]#%[^#]#%s",
		temp.nazivHale,
		&temp.modelId,
		temp.imeBroda,
		temp.operater,
		temp.booth
	) == 5) {
		if (temp.modelId != 0) {
			temp.modelBroda = pronadjiModel(modeli, brModela, temp.modelId);

			if (temp.modelBroda.cijenaTjedan >= minCijena && temp.modelBroda.cijenaTjedan <= maxCijena) {
				if (temp.modelBroda.duljina >= minDuljina && temp.modelBroda.duljina <= maxDuljina) {
					brodovi[n] = temp;

					n++;
				}
			}
		}

		if (n == max) {
			max += 5;
			brodovi = (Brod*)realloc(brodovi, sizeof(Brod) * max);
		}
	}

	*brBrodova = n;

	fclose(datoteka);

	return brodovi;
}

void sortiranje(Brod* brodovi, int brBrodova) {

	for (int i = 0; i < brBrodova - 1; i++)
	{
		for (int j = i + 1; j < brBrodova; j++)
		{
			if (strcmp(brodovi[i].imeBroda, brodovi[j].imeBroda) == 1) {
				Brod tmp = brodovi[i];
				brodovi[i] = brodovi[j];
				brodovi[j] = tmp;
			}

			if (strcmp(brodovi[i].nazivHale, brodovi[j].nazivHale) == 1) {
				Brod tmp = brodovi[i];
				brodovi[i] = brodovi[j];
				brodovi[j] = tmp;
			}
		}
	}
}