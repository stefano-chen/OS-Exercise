#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    printf("T1\n");
    if ( fork()){
        printf("T2\n");
        wait(NULL);
        printf("T4\n");
    }else {
        printf("T3\n");
    }
    return 0;
}