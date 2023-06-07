#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <ctype.h>

int ignoreSignal(int sig){
    struct sigaction sa;
    sa.sa_handler = SIG_IGN;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    return sigaction(sig, &sa, NULL);
    
}


int main(int argc, char** argv){
    ignoreSignal(SIGINT);
    sleep(10);
    return 0;
}