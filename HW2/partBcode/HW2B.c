#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "WordLinkedList.h"
//////////////////         head     ////////////////////////////

///////////////////////////////////////////////////////////////////
word_t *createWord(char *content, int frequency, int *lineNum){
    word_t *s=(word_t *)malloc(sizeof(word_t));
    char *n;
    s->content=(char*) malloc(sizeof(strlen(content)+1));
    s->frequency=frequency;
    //这里需要根据 空格 分离句子
    //草泥马不用了 直接干
    //lineNum作用不明
    strcpy(s->content,content);
    return s;
}
///////////////////////////////////////////////////////////////////
word_t *insertWord(word_t *s, word_t *newWord){
  if(s==NULL){
    return newWord;
  }
  newWord->next=s;
  s=newWord;
  return s;
}
///////////////////////////////////////////////////////////////////
word_t *seperateLine(char *line,int *lineSize){//this func will return a LS w/repeatations
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
///////////////////////////////////////////////////////////////////
char toString(word_t *s){
  char info[100], *result;
  sprintf(info, '%s', s->content);
  result=(char *)malloc(strlen(info) +1);
  strcpy(result,info);
  return *result;
}
///////////////////////////////////////////////////////////////////
