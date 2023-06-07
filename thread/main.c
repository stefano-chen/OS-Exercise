#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


void* print(void* arg){
    while (1){
        printf("%s\n", (char*) arg);
        sleep(2);
    }
    pthread_exit(NULL);
}

int main(int argc, char** argv){
    pthread_t th1, th2;

    printf("This is the main\n");
    pthread_create(&th1, NULL, print,"Th1");
    pthread_create(&th2, NULL, print,"Th2");
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return 0;
}