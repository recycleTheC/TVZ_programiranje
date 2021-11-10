#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void main() {
	double zd, zs, zv; // prostorija - zidovi
	double ps, pv; // polcice

	scanf("%lf %lf %lf", &zd, &zs, &zv); // ucitavanje podataka za zidove
	scanf("%lf %lf", &ps, &pv); // ucitavanje podataka za plocice

	zd *= 100;
	zs *= 100;
	zv *= 100;

	double povrsina1 = 2 * (zd * zv);
	double povrsina2 = 2 * (zs * zv);
	double povrsina3 = zd * zs;

	double plocica1 = ps * pv;

	int max1 = (int)(zd / ps) * (int)(zv / pv);
	int max2 = (int)(zd / pv) * (int)(zv / ps);

	double iznos1 = povrsina1 / plocica1;
	if (max1 > max2) iznos1 -= (int)iznos1 % max1;
	else iznos1 -= (int)iznos1 % max2;

	max1 = (int)(zs / ps) * (int)(zv / pv);
	max2 = (int)(zs / pv) * (int)(zv / ps);

	double iznos2 = povrsina2 / plocica1;
	if (max1 > max2) iznos2 -= (int)iznos2 % max1;
	else iznos2 -= (int)iznos2 % max2;

	max1 = (int)(zd / ps) * (int)(zs / pv);
	max2 = (int)(zd / pv) * (int)(zs / ps);
	double iznos3 = povrsina3 / plocica1;
	if (max1 > max2) iznos3 -= (int)iznos3 % max1;
	else iznos3 -= (int)iznos3 % max2;

	int n = (int)iznos1 + (int)iznos2 + (int)iznos3;

	printf("%d", n);
}