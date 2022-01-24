#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

typedef struct {
	int dan, mjesec, godina;
} Datum;

typedef struct {
	char nazivSoja[12];
	Datum datumPojave;
	int opasnost;
	int otpornost;
} Virus;

typedef struct {
	char sifraZemlje[4];
	Datum polazak;
	Datum odlazak;
	int iznos;
} Putovanje;

typedef struct {
	Datum pocetak;
	Datum kraj;
} Lockdown;

typedef struct {
	char sifra[4];
	char naziv[30];
	double procjepljenost;
	int tendencijaZatvaranja;
	Putovanje* mogucaPutovanja;
	int brojMogucihPutovanja;
	Lockdown* lockdown;
	int brojLockdowna;
} Zemlja;

char** ucitajCiljeve(int* budget, int* n);
Virus* ucitajPlan(int* brSojeva);
Zemlja* ucitajZemlje(int* brZemlji);
Putovanje* ucitajPutovanja(int* brMogucihPutovanja);

void sortirajPutovanja(Putovanje* putovanja, int brPutovanja);
void poveziPutovanja(Putovanje* putovanja, int brPutovanja, Zemlja* zemlje, int brZemlji);
void odrediLockdown(Zemlja* zemlje, const int brZemlji, Virus* sojevi, const int brSojeva);
void odaberiPutovanja(char** ciljevi, int brCiljeva, Zemlja* zemlje, int brZemlji, int iznos);

Datum pocetakLockdowna(const Datum pojava, double procjepljenost, int tendencijaZatvaranju, int opasnost, int otpornost);
Datum krajLockdowna(const Datum pocetak, int trajanje);

int main() {

	int budget, brCiljanihPutovanja, brZemlji, brMogucihPutovanja, brSojeva;

	char** ciljevi = ucitajCiljeve(&budget, &brCiljanihPutovanja);
	Zemlja* zemlje = ucitajZemlje(&brZemlji);
	Putovanje* putovanja = ucitajPutovanja(&brMogucihPutovanja);
	Virus* sojevi = ucitajPlan(&brSojeva);

	sortirajPutovanja(putovanja, brMogucihPutovanja);
	poveziPutovanja(putovanja, brMogucihPutovanja, zemlje, brZemlji);
	odrediLockdown(zemlje, brZemlji, sojevi, brSojeva);

	odaberiPutovanja(ciljevi, brCiljanihPutovanja, zemlje, brZemlji, budget);

	return 0;
}

char** ucitajCiljeve(int* budget, int* n) {

	FILE* datoteka = fopen("ciljevi.txt", "r");
	if (datoteka == NULL) exit(1);

	fscanf(datoteka, "%d %d", budget, n);
	int br = *n;

	char** mat = (char**)malloc(sizeof(char*) * br);
	if (mat == NULL) exit(1);


	for (int i = 0; i < (*n); i++)
	{
		mat[i] = (char*)calloc(4, sizeof(char));
	}

	for (int i = 0; i < *n; i++)
	{
		fscanf(datoteka, "%s", mat[i]);
	}

	fclose(datoteka);

	return mat;
}

Virus* ucitajPlan(int* brSojeva) {
	FILE* datoteka = fopen("plan.txt", "r");
	if (datoteka == NULL) exit(1);

	int n = 0, max = 5;

	Virus* sojevi = (Virus*)malloc(sizeof(Virus) * max);
	if (sojevi == NULL) exit(1);

	while (fscanf(datoteka, "%s %d.%d.%d. %d %d",
		sojevi[n].nazivSoja, &sojevi[n].datumPojave.dan,
		&sojevi[n].datumPojave.mjesec, &sojevi[n].datumPojave.godina,
		&sojevi[n].opasnost, &sojevi[n].otpornost
	) == 6) {

		n++;

		if (n == max) {
			max += 5;
			sojevi = (Virus*)realloc(sojevi, sizeof(Virus) * max);
			if (sojevi == NULL) exit(1);
		}
	}

	fclose(datoteka);

	*brSojeva = n;

	return sojevi;
}

Zemlja* ucitajZemlje(int* brZemlji) {
	FILE* datoteka = fopen("zemlje.txt", "r");
	if (datoteka == NULL) exit(1);

	int n = 0, max = 5;

	Zemlja* zemlje = (Zemlja*)malloc(sizeof(Zemlja) * max);
	if (zemlje == NULL) exit(1);

	while (fscanf(datoteka, "%s %[^0-1] %lf %d",
		zemlje[n].sifra, zemlje[n].naziv, &zemlje[n].procjepljenost,
		&zemlje[n].tendencijaZatvaranja
	) == 4) {

		int len = strlen(zemlje[n].naziv) - 1;

		if (zemlje[n].naziv[len] == ' ') {
			zemlje[n].naziv[len] = '\0';
		}

		zemlje[n].brojMogucihPutovanja = 0;
		zemlje[n].brojLockdowna = 0;

		n++;

		if (n == max) {
			max += 5;
			zemlje = (Zemlja*)realloc(zemlje, sizeof(Zemlja) * max);
			if (zemlje == NULL) exit(1);
		}

	}

	fclose(datoteka);

	*brZemlji = n;

	return zemlje;
}

Putovanje* ucitajPutovanja(int* brMogucihPutovanja) {
	FILE* datoteka = fopen("putovanja.txt", "r");
	if (datoteka == NULL) exit(1);

	int n = 0, max = 5;

	Putovanje* putovanja = (Putovanje*)malloc(sizeof(Putovanje) * max);
	if (putovanja == NULL) exit(1);

	while (fscanf(datoteka, " %s %d.%d.%d. %d.%d.%d. %d%*[kn]",
		putovanja[n].sifraZemlje,
		&putovanja[n].polazak.dan,
		&putovanja[n].polazak.mjesec,
		&putovanja[n].polazak.godina,
		&putovanja[n].odlazak.dan,
		&putovanja[n].odlazak.mjesec,
		&putovanja[n].odlazak.godina,
		&putovanja[n].iznos
	) == 8) {

		n++;

		if (n == max) {
			max += 5;
			putovanja = (Putovanje*)realloc(putovanja, sizeof(Putovanje) * max);
			if (putovanja == NULL) exit(1);
		}

	}

	fclose(datoteka);

	*brMogucihPutovanja = n;

	return putovanja;
}

int usporediDatume(Datum a, Datum b) {
	if (a.godina < b.godina) return -1;
	else if (a.godina > b.godina) return 1;
	else {
		if (a.mjesec < b.mjesec) return -1;
		else if (a.mjesec > b.mjesec) return 1;
		else if (a.dan < b.dan) return -1;
		else if (a.dan > b.dan) return 1;
		else return 0;
	}

}

void sortirajPutovanja(Putovanje* putovanja, int brPutovanja) {
	for (int i = 0; i < brPutovanja - 1; i++)
	{
		for (int j = i + 1; j < brPutovanja; j++)
		{
			if (usporediDatume(putovanja[i].polazak, putovanja[j].polazak) == 1) {
				Putovanje tmp = putovanja[i];
				putovanja[i] = putovanja[j];
				putovanja[j] = tmp;
			}
		}
	}
}

void poveziPutovanja(Putovanje* putovanja, int brPutovanja, Zemlja* zemlje, int brZemlji) {

	for (int i = 0; i < brZemlji; i++)
	{
		int k = 0, max = 5;

		zemlje[i].mogucaPutovanja = (Putovanje*)malloc(sizeof(Putovanje) * max);
		if (zemlje[i].mogucaPutovanja == NULL) exit(1);

		for (int j = 0; j < brPutovanja; j++)
		{
			if (strcmp(zemlje[i].sifra, putovanja[j].sifraZemlje) == 0) {
				zemlje[i].mogucaPutovanja[k] = putovanja[j];

				k++;

				if (k == max) {
					max += 5;
					zemlje[i].mogucaPutovanja = (Putovanje*)realloc(zemlje[i].mogucaPutovanja, sizeof(Putovanje) * max);
				}
			}
		}

		zemlje[i].brojMogucihPutovanja = k;
	}
}

int trajanjeLockdowna(int opasnost, const int otpornost, int tendencijaZatvaranju) {
	return (opasnost * otpornost * tendencijaZatvaranju) / 10;
}

int brojDanaUMjecesu(int mjesec, int godina) {
	switch (mjesec) {
	case 2:
		if ((godina % 4 == 0) && ((godina % 400 == 0) || (godina % 100 != 0))) {
			return 29;
		}
		else {
			return 28;
		}

	case 4:
	case 6:
	case 9:
	case 11:
		return 30;

	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	}
}

Datum pocetakLockdowna(const Datum pojava, double procjepljenost, int tendencijaZatvaranju, int opasnost, int otpornost) {
	double brojDanaOdPojave = procjepljenost / (double)tendencijaZatvaranju * (double)(50 - opasnost * otpornost);
	int zaokruzeno = floor(brojDanaOdPojave);

	Datum pocetak = { pojava.dan, pojava.mjesec, pojava.godina };

	if (zaokruzeno > 0) {
		for (int i = 1; i <= zaokruzeno; i++)
		{
			pocetak.dan++;

			if (pocetak.dan > brojDanaUMjecesu(pocetak.mjesec, pocetak.godina)) {
				pocetak.dan = pocetak.dan - brojDanaUMjecesu(pocetak.mjesec, pocetak.godina);
				pocetak.mjesec++;
			}

			if (pocetak.mjesec > 12) {
				pocetak.mjesec = 1;
				pocetak.godina++;
			}
		}
	}
	else if (zaokruzeno < 0) {
		zaokruzeno *= -1;

		for (int i = 1; i <= zaokruzeno; i++)
		{
			pocetak.dan--;

			if (pocetak.dan == 0) {
				pocetak.mjesec--;
				pocetak.dan = brojDanaUMjecesu(pocetak.mjesec, pocetak.godina);
			}

			if (pocetak.mjesec == 0) {
				pocetak.mjesec = 12;
				pocetak.godina--;
				pocetak.dan = brojDanaUMjecesu(pocetak.mjesec, pocetak.godina);
			}
		}
	}

	return pocetak;
}

Datum krajLockdowna(Datum pocetak, const int trajanje) {

	Datum kraj = { pocetak.dan, pocetak.mjesec, pocetak.godina };

	for (int i = 0; i < trajanje; i++)
	{
		kraj.dan++;

		if (kraj.dan > brojDanaUMjecesu(kraj.mjesec, kraj.godina)) {
			kraj.dan = 1;
			kraj.mjesec += 1;
		}

		if (kraj.mjesec > 12) {
			kraj.mjesec = 1;
			kraj.godina += 1;
		}
	}

	return kraj;
}

void odrediLockdown(Zemlja* zemlje, const int brZemlji, Virus* sojevi, const int brSojeva) {

	for (int i = 0; i < brZemlji; i++)
	{
		zemlje[i].brojLockdowna = brSojeva;

		zemlje[i].lockdown = (Lockdown*)malloc(sizeof(Lockdown) * brSojeva);
		if (zemlje[i].lockdown == NULL) exit(1);

		for (int j = 0; j < brSojeva; j++)
		{
			Lockdown lockdown;

			lockdown.pocetak = pocetakLockdowna(
				sojevi[j].datumPojave,
				zemlje[i].procjepljenost,
				zemlje[i].tendencijaZatvaranja,
				sojevi[j].opasnost,
				sojevi[j].otpornost
			);

			int trajanje = trajanjeLockdowna(
				sojevi[j].opasnost,
				sojevi[j].otpornost,
				zemlje[i].tendencijaZatvaranja
			);

			lockdown.kraj = krajLockdowna(lockdown.pocetak, trajanje);

			zemlje[i].lockdown[j] = lockdown;
		}
	}
}

int jeLiZaVrijemeLockdowna(Zemlja zemlja, int indexPutovanja) {

	Putovanje odabrano = zemlja.mogucaPutovanja[indexPutovanja];
	int ok = 1;

	for (int i = 0; i < zemlja.brojLockdowna; i++)
	{
		int polazakPocetak = usporediDatume(odabrano.polazak, zemlja.lockdown[i].pocetak);
		int polazakKraj = usporediDatume(odabrano.polazak, zemlja.lockdown[i].kraj);
		int odlazakPocetak = usporediDatume(odabrano.odlazak, zemlja.lockdown[i].pocetak);
		int odlazakKraj = usporediDatume(odabrano.odlazak, zemlja.lockdown[i].kraj);

		if ((polazakPocetak == 1 && polazakKraj == -1) || (odlazakPocetak == 1 && odlazakKraj == -1)) ok = 0;
	}

	return ok;
}

Putovanje* izvuciMogucaPutovanja(int* brojMogucih, char** ciljevi, int brCiljeva, Zemlja* zemlje, int brZemlji) {

	int nMogucih = 0, max = 5;

	Putovanje* mogucaPutovanja = (Putovanje*)malloc(sizeof(Putovanje) * max);
	if (mogucaPutovanja == NULL) exit(1);

	for (int n = 0; n < brCiljeva; n++)
	{
		for (int i = 0; i < brZemlji; i++)
		{
			if (strcmp(zemlje[i].sifra, ciljevi[n]) == 0) {
				for (int j = 0; j < zemlje[i].brojMogucihPutovanja; j++)
				{
					int test = jeLiZaVrijemeLockdowna(zemlje[i], j);

					if (test) {
						mogucaPutovanja[nMogucih] = zemlje[i].mogucaPutovanja[j];
						nMogucih++;

						if (nMogucih == max) {
							max += 5;
							mogucaPutovanja = (Putovanje*)realloc(mogucaPutovanja, sizeof(Putovanje) * max);
						}
					}
				}
			}
		}
	}

	*brojMogucih = nMogucih;

	return mogucaPutovanja;
}

Putovanje* izvuciNajpovoljnijaPutovanja(Putovanje* putovanja, int brMogucihPutovanja, char** ciljevi, int brCiljeva) {
	Putovanje* minimalna = (Putovanje*)malloc(sizeof(Putovanje) * brCiljeva);
	if (minimalna == NULL) exit(1);

	for (int n = 0; n < brCiljeva; n++)
	{
		int index = 0, min;

		for (int i = 0; i < brMogucihPutovanja; i++)
		{
			if (strcmp(putovanja[i].sifraZemlje, ciljevi[n]) == 0) {
				if (index == 0) {
					min = putovanja[i].iznos;
					minimalna[n] = putovanja[i];
					index++;
				}
				else if (putovanja[i].iznos < min) {
					min = putovanja[i].iznos;
					minimalna[n] = putovanja[i];
				}
			}
		}
	}

	return minimalna;
}

Putovanje* izvuciKonacanOdabir(Putovanje* putovanja, int brPutovanja, int iznos, int* odabrano) {
	int odabir = 0, preostalo = iznos;

	Putovanje* odabrana = (Putovanje*)malloc(sizeof(Putovanje) * brPutovanja);
	if (odabrana == NULL) exit(1);

	for (int i = 0; i < brPutovanja; i++)
	{
		if (preostalo - putovanja[i].iznos >= 0) {
			odabrana[odabir] = putovanja[i];
			odabir++;

			preostalo -= putovanja[i].iznos;
		}
	}

	*odabrano = odabir;

	return odabrana;
}

char* nazivZemlje(char sifra[], Zemlja* zemlje, int brZemlji) {
	for (int i = 0; i < brZemlji; i++)
	{
		if (strcmp(zemlje[i].sifra, sifra) == 0) {
			return &zemlje[i].naziv;
		}
	}
}

void odaberiPutovanja(char** ciljevi, int brCiljeva, Zemlja* zemlje, int brZemlji, int iznos) {
	int brMogucih = 0, odabrano;

	Putovanje* mogucaPutovanja = izvuciMogucaPutovanja(&brMogucih, ciljevi, brCiljeva, zemlje, brZemlji);
	Putovanje* najpovoljnija = izvuciNajpovoljnijaPutovanja(mogucaPutovanja, brMogucih, ciljevi, brCiljeva);

	free(mogucaPutovanja);

	Putovanje* konacanOdabir = izvuciKonacanOdabir(najpovoljnija, brCiljeva, iznos, &odabrano);

	free(najpovoljnija);

	FILE* datoteka = fopen("plan.out", "w");
	if (datoteka == NULL) exit(1);

	for (int i = 0; i < odabrano; i++)
	{
		char* zemlja = nazivZemlje(konacanOdabir[i].sifraZemlje, zemlje, brZemlji);

		printf(
			"%s %02d.%02d.%02d - %02d.%02d.%02d: %d kn\n",
			zemlja,
			konacanOdabir[i].polazak.dan,
			konacanOdabir[i].polazak.mjesec,
			konacanOdabir[i].polazak.godina,
			konacanOdabir[i].odlazak.dan,
			konacanOdabir[i].odlazak.mjesec,
			konacanOdabir[i].odlazak.godina,
			konacanOdabir[i].iznos
		);

		fprintf(
			datoteka,
			"%s %02d.%02d.%02d - %02d.%02d.%02d: %d kn\n",
			zemlja,
			konacanOdabir[i].polazak.dan,
			konacanOdabir[i].polazak.mjesec,
			konacanOdabir[i].polazak.godina,
			konacanOdabir[i].odlazak.dan,
			konacanOdabir[i].odlazak.mjesec,
			konacanOdabir[i].odlazak.godina,
			konacanOdabir[i].iznos
		);
	}

	free(konacanOdabir);
	
	fclose(datoteka);
}