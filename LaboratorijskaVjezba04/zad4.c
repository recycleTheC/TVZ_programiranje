#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* pronadjiDatum(const char* unos, const char* format);

int main() {

	char unos[50] = { 0 }, format[50] = { 0 };

	scanf("%[^\n]", unos);
	scanf(" %[^\n]", format);

	char* datum = pronadjiDatum(unos, format);

	printf("%s\n", datum);

	return 0;
}

int pretvoriUInt(char znak) {
	if (znak >= '0' && znak <= '9') {
		return znak - '0';
	}
	else return -1;
}

int potenciraj(int k) {
	int n = 1;

	for (int i = 1; i <= k; i++)
	{
		n *= 10;
	}

	return n;
}

char* pronadjiDatum(const char* unos, const char* format) {

	int dan = 0, mjesec = 0, godina = 0;
	int kDan = 0, kMjesec = 0, kGodina = 0;

	for (int i = strlen(format) - 1; i >= 0; i--)
	{
		switch (format[i]) {
			case 'g':
				godina += pretvoriUInt(unos[i]) * potenciraj(kGodina);
				kGodina++;
				break;
			case 'm':
				mjesec += pretvoriUInt(unos[i]) * potenciraj(kMjesec);
				kMjesec++;
				break;
			case 'd':
				dan += pretvoriUInt(unos[i]) * potenciraj(kDan);
				kDan++;
				break;
		}
	}

	if (godina >= 0 && godina <= 22) godina += 2000;
	else godina += 1900;

	char* datum = (char*)calloc(12, sizeof(char));

	sprintf(datum, "%02d.%02d.%d.", dan, mjesec, godina);

	return datum;
}