#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define MAX 5

pthread_mutex_t prod;
pthread_mutex_t cons;
int array[MAX] = {};
int counter = 0;
int i = 0;
int j = 0;


void* production(void* arg){
    while (1){
        pthread_mutex_lock(&prod);
        pthread_mutex_lock(&cons);
        if(counter < MAX){
            array[i] = 1;
            i = (i+1)%MAX;
            counter++;
        }
        pthread_mutex_unlock(&cons);
        pthread_mutex_unlock(&prod);
        sleep(5);
    }
}

void* consumer(void* arg){
    while (1){
        pthread_mutex_lock(&prod);
        pthread_mutex_lock(&cons);
        if(counter > 0){
            array[j] = 0;
            j = (j+1)%MAX;
            counter--;
        }
        pthread_mutex_unlock(&cons);
        pthread_mutex_unlock(&prod);
        sleep(4);
    }
}

void printArray(){
    for (int k=0; k<MAX; k++){
        printf("%d ", array[k]);
    }
    printf("\n");
}

int main(int argc, char** argv){
    pthread_mutex_init(&prod,NULL);
    pthread_mutex_init(&cons,NULL);
    pthread_t th1,th2,th3,th4;
    pthread_create(&th1,NULL,production, NULL);
    pthread_create(&th2,NULL,consumer, NULL);
    pthread_create(&th3,NULL,production, NULL);
    //pthread_create(&th4,NULL,consumer, NULL);
    while(1){
        printArray();
        sleep(1);
    }
}