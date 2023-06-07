#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// si crei un programma che determina su un numero inserito dall'utente è primo.

int main(int argc, char **argv) {
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    for (int i = n/2; i > 1; i--) {
        if ( n % i == 0){
            printf("Not Prime\n");
            return 0;
        }
    }
    printf("Prime\n");
    return 0;
}
