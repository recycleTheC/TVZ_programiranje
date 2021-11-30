#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>

int main() {
	double tecajProdajni, tecajProdajniStari, tecajKupovni, tecajKupovniStari, kune = 100.0, euro = 0.0;
	int n, k = 0;

	scanf("%d", &n);
	scanf("%lf %lf", &tecajProdajni, &tecajKupovni);

	euro = roundf(kune / tecajProdajni * 100.0) / 100.0;
	kune = 0.00;

	tecajKupovniStari = tecajKupovni;
	tecajProdajniStari = tecajProdajni;
	k++;

	for (int i = 1; i < n; i++) {
		scanf("%lf %lf", &tecajProdajni, &tecajKupovni);

		if (tecajKupovni > tecajKupovniStari && euro != 0) {
			kune = round(euro * tecajKupovni * 100.0) / 100.0;
			euro = 0.00;
			k++;

			
		}else if (tecajProdajni < tecajProdajniStari && kune != 0) {
			euro = round(kune / tecajProdajni * 100.0) / 100.0;
			kune = 0.00;
			k++;

			tecajProdajniStari = tecajProdajni;
		}

		if(tecajKupovni > tecajKupovniStari) tecajKupovniStari = tecajKupovni;
		if (tecajProdajni < tecajProdajniStari) tecajProdajniStari = tecajProdajni;
	}

	printf("Nakon %d promjena, ostaje mu ", k);

	if (euro != 0) printf("%.2f EUR.", euro);
	else printf("%.2f kn.", kune);

	return 0;
}