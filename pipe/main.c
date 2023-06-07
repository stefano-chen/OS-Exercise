#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char** argv) {
    int pfd[2];
    if (fork()){
        write(pfd[1], argv[1], strlen(argv[1]));
        wait(NULL);
    }else {
        char str[100];
        read(pfd[0], str, 100);
        printf("%s\n", str);
    }
    return 0;
}