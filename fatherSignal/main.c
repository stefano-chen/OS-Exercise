#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig) {
    printf("Ho ricevuto il segnale\n");
}

int main(int argc, char** argv) {
    int pid;
    if (pid = fork()){
        while (1){
            sleep(1);
            kill(pid, SIGUSR1);
        }
    } else {
        struct sigaction sa;
        sa.sa_handler = handler;
        sigaction(SIGUSR1, &sa, NULL);
        while(1);
    }
    return 0;
}