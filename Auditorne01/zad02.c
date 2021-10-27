#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void main() {
	int temp, pad;

	scanf("%d, &d", &temp, &pad);

	if (temp < -15 || temp > 37) {
		printf("Ne ide van!");
	}
	else if (temp < 0) {
		if (pad == 1) {
			printf("Obuci ce kapu, rukavice, akput, duge hlace, vestu, cizme i uzeti ce kisobran");
		}
		else {
			printf("Obuci ce kapu, rukavice, akput, duge hlace, vestu, cizme.");
		}
	}
	else if (temp <= 20) {
		if (pad == 1) {
			printf("Obuci ce duge hlace, tenisice, kabanicu, obicnu majicu");
		}
		else {
			printf("Obuci ce duge hlace, tenisice, laganu jaknu, obicnu majicu");
		}
	}
	else if (temp <= 30) {
		if (pad == 1) {
			printf("Obuci ce tenisice, kratke hlace, obicnu majicu");
		}
		else {
			printf("Obuci ce tenisice, kratke hlace, obicnu majicu i kisobran");
		}
	}
	else {
		if (pad == 1) {
			printf("Obuci ce japanke, kratke hlace, kratku majicu");
		}
		else {
			printf("Obuci ce japanke, kratke hlace, kratku majicu i kisobran");
		}
		
	}
}