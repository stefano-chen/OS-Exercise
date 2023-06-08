#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h> //contains struct sockaddr_in
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>


int main(int argc, char** argv){
    int conn = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(4242);
    inet_aton("127.0.0.1", &addr.sin_addr);
    connect(conn, (struct sockaddr*)&addr, sizeof(addr));
    char str[100];
    while(1){
        read(conn, str, 100);
        str[strlen(str)]= '\0';
        write(1, str, strlen(str));
        printf("Enter a Phase\n");
        read(0, str, 100);
        str[strlen(str)]= '\0';
        write(conn, str, strlen(str));
    }
}