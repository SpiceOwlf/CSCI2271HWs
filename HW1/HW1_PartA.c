#include <stdio.h>
#include <stdlib.h>
#define MAX 80
char *getCharBlock(int *size){
  int index=0;
  char *p;
  char item;
  p=(char*) malloc(MAX*sizeof(char));
  //do i need to assign exact num of places to char
    printf("Enter a line here!\n");
  while (1){

    item=getchar();
    if(item=='\n'){
      break;
    }

    *(p+index)=item;
    index++;
  }
  *size=index;
  *(p+index)='\0';
  return p;

}
//此function应该返回包含char内容的 地址合集
//////////////////////////////////////////////////////////////////

int findMatch(char *text,int sizeText, char *pattern, int sizePattern){
    int i1;
    int i2=0;
    int result;
    for(i1=0;i1<sizeText;i1++){
        if(*(text+i1)==*(pattern+i2)){
          i2++;
          if(i2==sizePattern){
            break;
          }
        }
        else if (*(text+i1)!=*(pattern+i2)){
          i2=0;
          if(*(text+i1)==*(pattern+i2)){
            i2++;
          }
        }
    }
    if(i2==sizePattern){
      result= 1;
      printf("YES, we DO find the pattern\n" );
    }
    else {
      result= 0;
      printf("NO, we DON'T find the pattern\n" );
    }
    return result;
}


void printIt(char *ptr, int size){//why do we need index here?
  int i;
  for(i=0;i<size;i++){
    printf("%c",*(ptr+i));
  }
  printf("\n" );
}

//////////////////////////////////////////////////////////////////
int main(){
char *text, *pattern; //pointers for the characters you will read
char *p,*q,*r; //some pointer variables
int size,size1,x,y; //some integers
printf("give me your TEXT strings\n" );
text= getCharBlock(&size);
printf("the TEXT char is\n");
printIt( text,size);
printf("give me your PATTERN strings\n" );
pattern=getCharBlock(&size1);
printf("the PATTERN char is\n");
printIt(pattern,size1);
printf("So, let's see if we can find the pattern: \t" );
findMatch(text,size,pattern,size1);
//int findMatch(char *text,int sizeText, char *pattern, int sizePattern)

}
