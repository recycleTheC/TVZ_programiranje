#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* zamjeniHex(char* str) {
    int len = strlen(str) * 5;

    char* hex = (char*)calloc(len + 1, sizeof(char));
    int n = 0;

    while (*str != '\0') {

        if (n != 0) {
            sprintf((hex + n), " ", *str);
            n++;
        }

        sprintf((hex + n), "0x%02x", *str);
        n += 4;

        str++;
    }

    return hex;
}

int main() {
    char string[255] = { 0 };

    scanf("%[^\n]", string);
    
    char* zamjenjeno = zamjeniHex(string);

    printf("%s\n", zamjenjeno);
}