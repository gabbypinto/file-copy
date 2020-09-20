#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//using namespace std;

int main (int argc, char *argv[]){
    // int i;

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

    char * lines = NULL;
    size_t len = 0;
    ssize_t read;
    int c;

    if (!pipe)
    {
      printf("%s","popen failed!");
    }

    while (fgets(line,sizeof(line),pipe))
    {
        size+=strlen(line);
        strcat(buffer=realloc(buffer,size),line);
    }

    printf("Contents received from pipe\n ");
    fputs(buffer,stdout);

    pipe = fopen(buffer, "r"); //reading the file
    
  //   while(1) {
  //     printf("hi");
  //     c = fgetc(pipe);
  //     if( feof(pipe) ) { 
  //        break ;
  //     }
  //     printf("%c", c);
  //  }
    if (pipe == NULL){
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&lines, &len, pipe)) != -1) 
    {
          printf("Retrieved line of length %zu:\n", read);
          printf("%s", lines);
    }

    fclose(pipe);
    free(buffer);
    return 0;
}