/*
U slobodno vrijeme Stipe se voli baviti križanjem raznih vrsta pasmina.
Posebno mu je zanimljivo kombinirati imena pasa kako bi dobio ime nove pasmine.
Primjerice, ukoliko križa buldoga sa gonièem, nova pasmina se može zvati buniè ili goldog.
Vaš zadatak je da iz dva imena psa, kao rezultat u programu ispišete dvije moguænosti za naziv novonastale vrste križanjem,
na naèin da zamijenite prvi slog svake pasmine jedan s drugim. Slog se promatra kao niz suglasnika kojeg slijedi neprekinuti
niz samoglasnika (slogovi bi bili primjerice: kla, koo, kua, trkua ali ne bi bili neg, stup, pr). Stipe ne križa pasmine koje
poèinju sa samoglasnikom, jer je to pomalo nespretno.
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

int jeliSamoglasnik(char znak);

int duljinaPrvogSloga(char rijec[]) {
	int slog = 0;

	for (int i = 0; i < strlen(rijec) - 1; i++)
	{
		if (!jeliSamoglasnik(rijec[i])) {
			slog++;
		}
		else {
			slog++;

			if (!jeliSamoglasnik(rijec[i + 1])) {
				//slog++;
				break;
			}
		}
	}

	return slog;
}

int jeliSamoglasnik(char znak) {
	switch (znak) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return 1;
	default:
		return 0;
	}
}

void mix(char ime1[], int n1, char ime2[], int n2, char spremi[]) {
	strncpy(spremi, ime1, n1);
	strcat(spremi, &ime2[n2]);
}

int main() {
	char ime1[25], ime2[25];

	scanf("%s %s", ime1, ime2);
	
	int slog1 = duljinaPrvogSloga(ime1);
	int slog2 = duljinaPrvogSloga(ime2);

	// printf("%d\n", slog1);
	// printf("%d\n", slog2);

	char mix1[25]={0}, mix2[25]={0};

	mix(ime1, slog1, ime2, slog2, mix1);
	mix(ime2, slog2, ime1, slog1, mix2);

	printf("%s %s\n", mix1, mix2);

	return 0;
}