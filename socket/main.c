#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h> //contains struct sockaddr_in
#include <string.h>
#include <pthread.h>


void* clientHandler(void* arg){
    int client = *((int*)arg);
    char str[100] = "Welcome to the Server\n";
    char buf[100];
    write(client, str, strlen(str));
    while (1){
        read(client, buf,100 );
        str[strlen(str)]= '\0';
        write(client, buf, strlen(buf));
    }
}


int main(int argc, char** argv){
    int server = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr, client_addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(4242);
    bind(server, (struct sockaddr*)&addr, sizeof(addr));
    listen(server, 3);
    pthread_t th;
    while(1){
        int* client = malloc(sizeof(int)); 
        *client = accept(server,(struct sockaddr*) &client_addr, NULL);
        pthread_create(&th, NULL, clientHandler, client);
    }
}