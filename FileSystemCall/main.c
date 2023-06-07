#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char** arg) {
    const char* str = "Arbitrary string to be written to a file\n";
    const char* filename = "innn.txt";

    int fd = open(filename, O_RDWR | O_CREAT);
    if (fd == -1) {
        perror("File Open Error: ");
        exit(1);
    }

    write(fd,str,strlen(str));
    close(fd);
    return 0;
}