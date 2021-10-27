#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void main() {
	double v, s, d, cijena, a;

	scanf("%lf %lf %lf %lf %lf", &v, &s, &d, &cijena, &a);

	if (v <= 0 || s <= 0 || d <= 0 || a <= 0) {
		printf("Neispravno upisane velicine - moraju biti pozitivne!");
		return;
	}

	if (s <= a) {
		printf("Vrata moraju stati u prostoriju!");
		return;
	}

	double zid1 = s * v * 2.0;
	double zid2 = s * d * 2.0;
	double strop = s * d;

	double prozori = v * 0.75 * a;
	double vrata = 0.75 * v * 0.1 * s;

	double povrsina = (zid1 + zid2 + strop) - (prozori + a);

	double iznos = povrsina * cijena;

	int kuna = (int)iznos;
	int lipa = (iznos - (int)iznos + 0.0001) * 100;

	printf("Konacna cijena je %d kuna i %d lipa", kuna, lipa);
}