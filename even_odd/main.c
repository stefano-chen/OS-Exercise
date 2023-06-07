#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//si scriva un programma che legge da tastiera un intero e scrive se esso è
//positivo o negativo

int main(int argc, char **argv){
    int number;
    printf("Enter the number: ");
    scanf("%d", &number);
    if (number % 2 == 0) {
        printf("E' un numero pari \n");
    } else {
        printf("E' un numero dispari \n");
    }
    return 0;
}
