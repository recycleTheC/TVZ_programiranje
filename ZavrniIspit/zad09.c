#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void obrada() {  

    char znakovi[255] = { 0 };
    scanf("%[^\n]", znakovi);

    char* string = (char*)calloc(strlen(znakovi) * 2 + 1, sizeof(char));
    int len = 0;

    char* ptr = &znakovi[0];

    while (*ptr != '\0') {

        if (isdigit(*ptr)) {
            string[len] = *ptr;
            len++;

            string[len] = *ptr;
            len++;
        }
        else if (isalpha(*ptr)) {
            string[len] = *ptr;
            len++;
        }

        ptr += 1;
    }

    printf("%s\n", string);
}

int main() {
    obrada();
}