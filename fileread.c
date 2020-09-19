#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//using namespace std;

int main (int argc, char *argv[]){
    int i;

    // if (argc<2){
    //     printf("Error: %s <args1> <args2>... <argn> \n", argv[0] );
    //     return 0;
    // }

    // //prints out each arg on the command line
    // for (i = 0; i<argc; i++){
    //     printf("argv[%d]=%s\n",i,argv[i]);
    // }

    //so this is the same as our find-file.sh...can't save it though
    //system("find / -name make2.txt -print 2>/dev/null -quit | tail -n 1");
    char commandS[]  = "find / -name make2.txt -print 2>/dev/null -quit | tail -n 1";
    // printf("%s",commandS);
    // FILE* pipe = popen(commandS, "r");
    FILE* pipe = popen(commandS, "r");
    char line[128];
    char* buffer=NULL; // Buffer to store the string
    unsigned int size=0;
    if (!pipe) {
      printf("%s","popen failed!");
    }

    while (fgets(line,sizeof(line),pipe))
    {
        size+=strlen(line);
        strcat(buffer=realloc(buffer,size),line);
    }

    printf("Contents received from pipe\n ");
    fputs(buffer,stdout);

    pipe = fopen(buffer, "rb"); //reading the file
    
    free(buffer);
    fclose(pipe);
    
    return 0;
}