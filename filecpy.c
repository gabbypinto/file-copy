#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
//using namespace std;

int main (int argc, char *argv[]){
    int i;
    FILE *fp;
    if (argc<2){
        printf("Error: %s <args1> <args2>... <argn> \n", argv[0] );
        return 0;
    }
    else{
        /*int i,j;
        j=system("./test");
        printf("j=%d\n",j);*/
        //fp=fopen(argv[1], "r");
        //char buf[PATH_MAX]; /* PATH_MAX incudes the \0 so +1 is not required */
        /*char *res = realpath("findme", buf);
        if (res) {
        printf("This source is at %s.\n", buf);
        } else {
            perror("realpath");
            exit(EXIT_FAILURE);
        }*/
        //char filename[] = argv[1];
        char filename[] = argv[1];
        
        //strcat(filename, argv[1]);
        char* path = realpath(filename, NULL);
        if(path == NULL){
            printf("cannot find file with name[%s]\n", filename);
        } else{
            printf("path[%s]\n", path);
            free(path);
        }
    return 0;
    }
    /////
    
    
    return 0;
}