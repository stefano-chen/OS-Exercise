#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define MAX 100

int main(int argc, char** argv) {
    FILE * file;
    file = fopen("file.txt","r");
    if (file == NULL) {
        perror("File Open Error: ");
        exit(1);
    }
    char line[MAX];
    while(fgets(line,MAX,file)) {
        fputs(line,stdout);
    }
    fclose(file);
    return 0;
}
