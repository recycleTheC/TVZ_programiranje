#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>

void main() {
	double dzeparac, cijena;
	int n, str, len, height;

	scanf("%lf%d", &dzeparac, &str);

	if (str < 3) {
		printf("Krivi unos! Molim probajte opet.\n");
		scanf("%d", &str);
	}

	scanf("%d", &len);

	if (len < 0) {
		printf("Krivi unos! Molim probajte opet.\n");
		scanf("%d", &len);
	}

	scanf("%d%lf", &height, &cijena);

	n = dzeparac / cijena;

	double volumen = height * str * pow(len, 2) * (cos(3.14 / str) / sin(3.14 / str)) / 4;
	double ispl = cijena / volumen;

	printf("Perica moze kupiti: %d kolaca, a platit ce %.2fkn/cm^3.", n, ispl);
}