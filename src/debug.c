#include <stdio.h>

void print_debug_d(char str[], int var) {
    printf("DEBUG: ");
    printf(str, var);
    printf("\n");
}

void print_debug_s(char str[], char var[]) {
    printf("DEBUG: ");
    printf(str, var);
    printf("\n");
}

void print_debug_f(char str[], float var) {
    printf("DEBUG: ");
    printf(str, var);
    printf("\n");
}

void print_debug(char str[]) {
    printf("DEBUG: ");
    printf(str);
    printf("\n");
}