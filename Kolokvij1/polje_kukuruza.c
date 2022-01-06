#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>

// abs(I - II) <= 3

#define M 3
#define N 20

/*
· kukuruz 'I' – za èije branje mu je potrebno 5 sekundi
· trava '.' – na kojoj nema kukuruza i prolazi se u roku 1 sekunde
· blato ',' – na kojem nema kukuruza, ali su potrebne 2 sekunde da ga se prohoda
*/

enum Polje {
	Kukuruz = 'I',
	Trava = '.',
	Blato = ','
};

enum Vrijeme {
	VKukuruz = 5,
	VTrava = 1,
	VBlato = 2
};

int main() {
	char polje[M][N] = { {0} };

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf(" %c", &polje[i][j]);
		}
	}

	int vrijeme[M] = { 0 }, ubrano[M] = { 0 };

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			switch (polje[i][j]) {
			case Kukuruz:
				vrijeme[i] += VKukuruz;
				ubrano[i]++;
				break;

			case Trava:
				vrijeme[i] += VTrava;
				break;

			case Blato:
				vrijeme[i] += VBlato;
				break;
			}
		}
	}

	int red = 0, bestBerba = ubrano[0];
	double performanse[3] = { 0 };

	for (int i = 0; i < M; i++)
	{
		if (ubrano[i] > bestBerba) {
			bestBerba = ubrano[i];
		}

		performanse[i] = (double)ubrano[i] / vrijeme[i];
	}

	double bestPerformanse = performanse[0];

	for (int i = 1; i < M; i++)
	{
		if (performanse[i] > bestPerformanse) {
			bestPerformanse = performanse[i];
		}
	}

	for (int i = 0; i < M; i++)
	{
		int razlika = abs(bestBerba - ubrano[i]);

		if (razlika <= 3 && performanse[i] == bestPerformanse) {
			red = i;
			break;
		}
	}

	printf("Pozicioniraj se u %d. red!\n", red + 1);

}