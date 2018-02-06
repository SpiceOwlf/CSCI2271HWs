#include <stdio.h>
#include <stdlib.h>

char *getCharBlock(int *size){
  int index=0;
  char *p;
  char item;
  p=(char*) malloc(100*sizeof(char));
  //do i need to assign exact num of places to char
  while (1){
    printf("Enter an char only!(enter Z to stop)\n");
    scanf("%s",&item);

      if(item<'A'||item>'Z'){
      fprintf(stderr, "Error! Not an char\n" );
      exit(EXIT_FAILURE);
    }
    if (item=='Z'){
      break;
    }
    *(p+index)=item;
    index++;
  }
  *size=index;
  return p;
}
//此function应该返回包含char内容的 地址合集
//////////////////////////////////////////////////////////////////

int findMatch(char *text,int sizeText, char *pattern, int sizePattern){
    int i1;
    int i2=0;
    int count=0;
    int result;
    for(i1=0;i1<sizeText;i1++){
        if(*(text+i1)==*(pattern+i2)){
          i2++;
          if(i2==sizePattern){
            count++;
            i2=0;
            if(*(text+i1)==*(pattern+i2)){
              i2++;
            }
          }
        }
        else if (*(text+i1)!=*(pattern+i2)){
          i2=0;
          if(*(text+i1)==*(pattern+i2)){
            i2++;
          }
        }
    }

      printf("There are %d patterns\n", count);

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


//////////////////////////////////////////////////////////////////
/*int findMatch(char *text,int sizeText){
  //could not find a generic way to rule out patterns
int initialState, state1, state2, state3,finalState;
initialState=0;
state1=1;
state2=2;
state3=3;
finalState=4;

int *currentState;
char *currentChar;
int index=0;
*currentState=initialState;
 for (index=0; index<sizeText; index++) {
   *currentChar= *(text+index);//find current char with index;
   if (*currentState==0){
     if (*currentChar=='G'){
       *currentState=1;
     }
     else if (*currentChar=='A'){
       *currentState=0;
     }
     else if (*currentChar=='C'){
       *currentState=0;
     }
   }

   else if (*currentState==1){
     if (*currentChar=='C'){
       *currentState=2;}
     else if (*currentChar=='G'){
       *currentState=1;
      }
      else if (*currentChar=='A'){
        *currentState=0;
       }
     }

     else if (*currentState==2){
       if (*currentChar=='C'){
         *currentState=0;}
       else if (*currentChar=='G'){
         *currentState=1;
        }
        else if (*currentChar=='A'){
          *currentState=3;
         }
       }

       else if (*currentState==3){
         if (*currentChar=='C'){
           *currentState=0;}
         else if (*currentChar=='G'){
           *currentState=4;
          }
          else if (*currentChar=='A'){
            *currentState=0;
           }
         }
//FSM ends here
   }
   if (*currentState==4){
     printf("find it!\n" );
   }
   else {
    printf("We do not find it.\n" );
   }
   return 0;

 }*/
//0 means no, 1 means yes!
//////////////////////////////////////////////////////////////////
