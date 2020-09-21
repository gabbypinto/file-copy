//Gabriela Pinto and Katherine Hansen
//2318655 and 2326665

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  char *fline = NULL;
  size_t len = 0;
  ssize_t read;

  FILE *fp = fopen(argv[1],"r");
  FILE *outputF = fopen(argv[2],"w");

  //If file path does not work, error occurs
  if (fp == NULL){
    printf("The file was not found.\n");
    exit(EXIT_FAILURE);
  }

  //Reads input file until end is reached
  while ((read = getline(&fline, &len, fp)) != -1) {
    fprintf(outputF,"%s",fline);//Prints contents of each line to output file
  }

  printf("Your file was successfully copied\n");

  fclose(fp);
  fclose(outputF);
  free(fline);
  exit(EXIT_SUCCESS);
}
