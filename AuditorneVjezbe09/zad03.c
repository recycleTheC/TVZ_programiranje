#define _CRT_SECURE_NO_WARNINGS

/*
Napisati funkciju prema zadanom prototipu

char *spoji (char *ime, char *prezime);

koja �e spajanjem imena (npr. Ivo) i prezimena
(npr. Ivi�) osobe na�initi niz znakova koji sadr�i prezime i ime osobe odvojene zarezom i prazninom 
(npr. Ivi�, Ivo). Funkcija vra�a pokaziva� na rezultat. Ime i prezime moraju ostaju nepromijenjeni, 
a pretpostavlja se da imaju prate�ih praznina. Rezultat ne smije imati prate�ih praznina.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* spoji(char* ime, char* prezime);

int main() {
	char ime[512] = { 0 }, prezime[512] = { 0 };

	// scanf("%s %s", ime, prezime);

	char* a = spoji("Ivan", "Cesar");
	char* b = spoji("Mario", "Kopjar");

	printf("%s\n%s\n", a, b);
}

char* spoji(const char* ime, const char* prezime) {
	char* rezultat = (char*)calloc(strlen(ime) + strlen(ime) + 1, sizeof(char));

	strcpy(rezultat, prezime);
	strcat(rezultat, ", ");
	strcat(rezultat, ime);

	return rezultat;
}