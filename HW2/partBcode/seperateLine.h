#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getLine.h"
#include "Word.h"

word_t *seperateLine(char *line,int *lineSize){
    //this func will return a LS w/repeatations
    //and put it in linkedlist
  word_t *localWord;
  word_t *resultWord;
  //  这里要用指针吗
  int i=0;
  int lineI=0;
  char *current;
  char c;
  while (lineI< *lineSize) {
      current=(char*) malloc(sizeof(char));
      c= *(line+lineI);
      if (((c>='a')&&(c<='z'))||((c>='A')&&(c<='Z'))){
        *(current+i)=c;
        i++;
        lineI++;
        current=(char*)realloc(current,sizeof(char)*(i+1));
      }
      else if (c==' '|| c=='\0') {
        i=0;
        lineI++;
        localWord=createWord(current, 0, 0);
        resultWord= insertWord(resultWord, localWord);
        current=(char*)realloc(current,sizeof(char)*(i+1));
      }
    }
      return resultWord;
  }
