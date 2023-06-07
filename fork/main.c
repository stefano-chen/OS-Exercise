#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv){
    if (fork()){
        sleep(5);
        printf("I am the father\n");
    } else {
        printf("I am the child\n");
    }
    return 0;
}