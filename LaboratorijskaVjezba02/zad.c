#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {
	int n;

	scanf("%d", &n);

	while (!(n >= 1 && n <= 20)) {
		printf("Neispravan unos!\n");
		scanf("%d", &n);
	}

	int ubrano, podijeljeno, ukUbrano = 0, razlika = 0;

	scanf("%d %d", &ubrano, &podijeljeno);

	ukUbrano += ubrano;
	razlika = ubrano - podijeljeno;

	int max = razlika;
	int maxD = 1;

	for (int i = 2; i <= n; i++) {
		scanf("%d %d", &ubrano, &podijeljeno);

		ukUbrano += ubrano;
		razlika = ubrano - podijeljeno;

		if (razlika > max) {
			max = razlika;
			maxD = i;
		}
	}

	printf("Ukupno ubrano: %d kg.\n", ukUbrano);
	printf("Najveca razlika je bila %d.dan.", maxD);
}