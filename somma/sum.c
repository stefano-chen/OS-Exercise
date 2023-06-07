#include <stdio.h>

// Si scriva un programma che legge due interi da tastiera e stampa la loro somma.

int main(int argc, char **argv){
    int a;
    int b;
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    printf("The sum of %d and %d is %d\n", a, b, a+b);
    return 0;
}
