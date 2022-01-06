#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void ispisPolja(char polje[][10], int m, int n) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%c ", polje[i][j]);
		}

		printf("\n");
	}
	printf("\n");
}

char pobjednik(char polje[][10], int m, int n, int potrebno) {

	for (int j = 0; j < n; j++)
	{
		int unosX = 0, unosO = 0;

		for (int i = 0; i < m; i++)
		{
			switch (polje[i][j]) {
			case 'X':
				unosX++;
				break;
			case 'O':
				unosO++;
				break;
			}
		}

		if (unosO == potrebno) {
			return 'O';
		}

		if (unosX == potrebno) {
			return 'X';
		}
	}

	return 0;
}

int main() {
	char polje[10][10] = { {0} };
	int m, n, zaPobjedu;

	scanf("%dx%d", &m, &n);

	while (!(m >= 3 && m <= 10 && n >= 3 && n <= 10)) {
		printf("Nedozvoljena dimenzija polja!\n");
		scanf("%dx%d", &m, &n);
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			polje[i][j] = '-';
		}
	}

	scanf("%d", &zaPobjedu);

	char igrac[2] = { 0 };

	scanf(" %c", &igrac[0]);

	if (igrac[0] == 'X') igrac[1] = 'O';
	else igrac[1] = 'X';

	ispisPolja(polje, m, n);

	char imaPobjednika = 0;
	int brojac = 0;

	do {
		
		for (int i = 0; i < 2; i++)
		{
			int x, y, uzmiIgraca = brojac % 2;

			scanf("%d %d", &x, &y);
			polje[x - 1][y - 1] = igrac[uzmiIgraca];
			
			imaPobjednika = pobjednik(polje, m, n, zaPobjedu);
			brojac++;
		}

		ispisPolja(polje, m, n);
		
	} while (imaPobjednika == 0);

	printf("Pobjednik je igrac %c!", imaPobjednika);
}