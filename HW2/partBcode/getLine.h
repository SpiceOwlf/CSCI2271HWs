#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//getLine()
char *getLine(int *lineSize){
  int index=0;
  char *p;
  char item;
  p=(char*) malloc(sizeof(char));
      printf("Enter a line here!\n");
      item=getchar();
    //start here
  while (item!='\n'){
      *(p+index)=item;
      index++;
      p=(char*)realloc(p,sizeof(char)*(index+1));
      item=getchar();
    }
    *lineSize=index;
    *(p+index)='\0';
    return p;
  }
