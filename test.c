// #define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *fp;
    char *fline = NULL;
    size_t len = 0;
    ssize_t read;

    char line[128];
    char* buffer=NULL; // Buffer to store the string
    unsigned int size=0;
    char copyPath[200];

    char commandS[]  = "find / -name make2.txt -print 2>/dev/null -quit | tail -n 1";
    fp = popen(commandS,"r");

    while (fgets(line,sizeof(line),fp))
    {
        size+=strlen(line);
        strcat(buffer=realloc(buffer,size),line);
    }
    printf("path \n ");
    printf("%s",buffer);

    char fileSpec[strlen(buffer)+1];
    sprintf( fileSpec, "%s" ,buffer);
    //fp = fopen("/System/Volumes/Data/Users/gabbypinto/Desktop/make2.txt", "r");
    
    // fp = fopen(path, "r");
    fp = fopen(fileSpec,"r");
    FILE *outputF = fopen("program.txt","w");

   
    if (fp == NULL)
    {
        printf("doesn't work\n");
        exit(EXIT_FAILURE);
    }

    printf("hi it workd \n");

    while ((read = getline(&fline, &len, fp)) != -1) {
        // printf("Retrieved line of length %zu :\n", read);
        printf("%s", fline);
        printf("\n");
        fprintf(outputF,"%s",fline);
    }

    fclose(fp);
    fclose(outputF);
    free(fline);
    exit(EXIT_SUCCESS);
}

// some commands....
// echo `find /Users -name filecpy.c -print 2>/dev/null -quit | tail -n 1`
// echo `find /Users -name Prewriting.pdf -print 2>/dev/null -quit | tail -n 1`  
// echo `find / -name make2.txt -print 2>/dev/null -quit | tail -n 1`