#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig) {
    printf("Ho ricevuto il segnale %d\n", sig);
}

int main(int argc, char** argv){
    struct sigaction sa;
    sa.sa_handler = handler;

    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGHUP, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);
    while (1);
    return 0;
}