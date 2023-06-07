#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mw;
pthread_mutex_t mr;
static int counter = 0;

void* increment(void* arg){
    while(1){
        pthread_mutex_lock(&mw);
        pthread_mutex_lock(&mr);
        counter+=1;
        pthread_mutex_unlock(&mr);
        pthread_mutex_unlock(&mw);
        sleep(2);
    }
    
}

void* print(void* arg){
    while (1){
        pthread_mutex_lock(&mw);
        pthread_mutex_lock(&mr);
        printf("Counter: %d\n", counter);
        pthread_mutex_unlock(&mr);
        pthread_mutex_unlock(&mw);
        sleep(2);
    }
}
    

int main(int argc, char** argv){
    pthread_mutex_init(&mw,NULL);
    pthread_mutex_init(&mr,NULL);
    pthread_t th1, th2;
    pthread_create(&th1, NULL, increment, NULL);
    pthread_create(&th2, NULL, print, NULL);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return 0;
}