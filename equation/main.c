#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// Si scriva un programma che risolve un'equazione di primo grado.

int main(int argc, char **argv) {
    int a, b;
    float x;
    printf("Inserisci il coefficiente a: ");
    scanf("%d", &a);
    printf("Inserisci il coefficiente b: ");
    scanf("%d", &b);
    if ( a != 0) {
        x = ((float) -b) / ((float) a);
        printf("x = %f\n", x);
    } else {
        printf("Invalid Equation\n");
    }
    return 0;
}