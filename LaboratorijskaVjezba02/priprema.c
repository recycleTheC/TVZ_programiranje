#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {

	int n = 0, i, posjedujem = 0;
	double cijena, kupljeno = 0, prodano = 0, zarazeno = 0;
	
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%lf %lf", &cijena, &zarazeno);

		double zarazeno_m = zarazeno * 20 / 100;

		if (cijena < zarazeno && cijena > zarazeno_m) {
			kupljeno += cijena;
			posjedujem += 1;
		}
		else if(posjedujem > 0 && cijena < zarazeno_m){
			prodano += cijena * posjedujem;
			posjedujem = 0;
		}
	}

	printf("%d ETH\n", posjedujem);
	printf("Prodano ETH: $%.2f\n", prodano);
	printf("Kupljeno ETH: $%.2f\n", kupljeno);

	return 0;
}