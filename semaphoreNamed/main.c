#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

static int counter = 0;

void* increment(void* arg){
    int a = *((int*)arg);
    sem_t* sem;
    sem = sem_open("/semaphore",O_CREAT,S_IRWXU | S_IRWXG, 1);
    while (1){
        sem_wait(sem);
        counter+=(a)? 1 : -1;
        sem_post(sem);
        sleep(2);
    }
}

int main(int argc, char** argv){
    pthread_t th1, th2;
    int* c = malloc(sizeof(int));
    *c = 1;
    int* b = malloc(sizeof(int));
    *b = 0;
    pthread_create(&th1, NULL, increment, c);
    pthread_create(&th2, NULL, increment, b);
    while (1){
        printf("Counter: %d\n", counter);
        sleep(1);
    }
}