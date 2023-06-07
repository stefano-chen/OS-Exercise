#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if (strcmp(argv[1], "read") == 0){
        FILE* f = fopen("myfifo","r");
        char str[100];
        while(fgets(str, 100, f) != NULL){
            printf("%s", str);
        }
    }else {
        FILE* f = fopen("myfifo","w");
        char str[100];
        while(fgets(str, 100, stdin) != NULL){
            fputs(str,f);
            fflush(f);
        }
    }
    return 0;
}