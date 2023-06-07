#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// si scriva un programma che riceve due interi come parametri e ne stampa la somma.

int main(int argc, char **argv) {
    int a, b;
    if (argc != 3) {
        printf("Missing Arguments\n");
        exit(1);
    }
    a = atoi(*(argv+1));
    b = atoi(*(argv+2));
    printf("La somma: %d \n", a+b);
    return 0;
}