#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv){
    printf("T1\n");
    if (fork()){
        printf("T2\n");
        printf("T4\n");
        wait(NULL);
        printf("T7\n");
    } else {
        printf("T3\n");
        if(fork()){
            printf("T5\n");
            wait(NULL);
        }else {
            printf("T6\n");
        }
    }
    return 0;
}