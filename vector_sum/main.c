#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//si crei un programma che effettua la somma vettoriale tra due vettori bi-dimensionali.

typedef struct {
    float x;
    float y;
} vector;


int main(int argc, char **argv) {
    vector v1, v2, result;
    printf("Enter x of vector 1: ");
    scanf("%f", &v1.x);
    printf("Enter y of vector 1: ");
    scanf("%f", &v1.y);
    printf("Enter x of vector 2: ");
    scanf("%f", &v2.x);
    printf("Enter y of vector 2: ");
    scanf("%f", &v2.y);

    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    printf("Vector Sum: (%f,%f)\n", result.x, result.y);
    return 0;
}
