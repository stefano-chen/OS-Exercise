#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


//Si scriva un programma che dato un numero di minuti, calcola a quante ore (e minuti rimanenti)
//equivale.

int main(int argc, char **arg){

    int minutes;
    int hours;
    int remaining;
    printf("Enter number of minutes: ");
    scanf("%d", &minutes);
    remaining = minutes % 60;
    hours = minutes / 60;
    printf("it's equivalent to %d:%d hours\n", hours, remaining);
    return 0;
}
